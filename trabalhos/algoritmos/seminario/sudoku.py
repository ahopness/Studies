#!/bin/python3

import gi
gi.require_version('Gtk', '4.0')
from gi.repository import Gtk
import random

GRID_SUDOKU = [[None for j in range(9)] for i in range(9)]
def on_activate(app):
    window_main = Gtk.Window(application=app)
    window_main.set_default_size(450, 500)
    window_main.set_title("Sudoku")
    window_main.set_resizable(False)

    center_box_main = Gtk.CenterBox()
    window_main.set_child(center_box_main)

    box_main = Gtk.Box()
    center_box_main.set_center_widget(box_main)
    box_main.set_spacing(20)
    box_main.set_orientation(Gtk.Orientation.VERTICAL)

    separator = Gtk.Separator()
    box_main.append(separator)

    CELL_SPACING = 2
    BLOCK_SPACING = 8
    sudoku_container = Gtk.Grid()
    box_main.append(sudoku_container)
    sudoku_container.set_column_spacing(BLOCK_SPACING)
    sudoku_container.set_row_spacing(BLOCK_SPACING)

    subgrids = []
    for i in range(3):
        for j in range(3):
            subgrid = Gtk.Grid()
            subgrid.set_column_spacing(CELL_SPACING)
            subgrid.set_row_spacing(CELL_SPACING)
            sudoku_container.attach(subgrid, i, j, 1, 1)
            subgrids.append(subgrid)

    for i in range(9):
        for j in range(9):
            GRID_SUDOKU[i][j] = Gtk.Entry()
            GRID_SUDOKU[i][j].set_max_length(1)
            GRID_SUDOKU[i][j].set_size_request(40, 40)
            
            block_row = i // 3
            block_column = j // 3
            subgrid_index = block_row * 3 + block_column
            
            local_row = i % 3
            local_col = j % 3
            
            subgrids[subgrid_index].attach(GRID_SUDOKU[i][j], local_col, local_row, 1, 1)
            
            buffer = Gtk.EntryBuffer()
            GRID_SUDOKU[i][j].set_buffer(buffer)

    actions_box = Gtk.Box()
    box_main.append(actions_box)
    actions_box.set_spacing(12)
    actions_box.set_orientation(Gtk.Orientation.HORIZONTAL)
    actions_box.set_halign(Gtk.Align.CENTER)

    button_novo = Gtk.Button()
    actions_box.append(button_novo)
    button_novo.set_label("Novo Jogo")
    button_novo.connect('clicked', novo_jogo)

    button_resolver = Gtk.Button()
    actions_box.append(button_resolver)
    button_resolver.set_label("Resolver")
    button_resolver.connect('clicked', resolver)

    window_main.present()

def novo_jogo(*args):
    grid = [[0 for j in range(9)] for i in range(9)]
    
    # cria um sudoku completo
    def criar():
        for i in range(9):
            for j in range(9):
                if grid[i][j] == 0:
                    numbers = list(range(1, 10))
                    random.shuffle(numbers)  # randomiza a ordem dos números
                    for num in numbers:
                        if eh_seguro(i, j, num):
                            grid[i][j] = num
                            if criar():
                                return True
                            grid[i][j] = 0
                    return False
        return True
    def eh_seguro(row, col, num):
        # linha
        for x in range(9):
            if grid[row][x] == num:
                return False
        
        # coluna
        for x in range(9):
            if grid[x][col] == num:
                return False
        
        # bloco 3x3
        start_row, start_col = 3 * (row // 3), 3 * (col // 3)
        for i in range(3):
            for j in range(3):
                if grid[start_row + i][start_col + j] == num:
                    return False
        return True
    
    criar()
    
    # remove alguns numeros aleatórios pra criar o puzzle em si
    cells_to_remove = random.randint(40, 55)
    cells = [(i, j) for i in range(9) for j in range(9)]
    random.shuffle(cells)
    for i in range(cells_to_remove):
        row, col = cells[i]
        grid[row][col] = 0
    
    # insere td na UI
    for i in range(9):
        for j in range(9):
            if grid[i][j] == 0:
                GRID_SUDOKU[i][j].get_buffer().set_text("", 1)
            else:
                GRID_SUDOKU[i][j].get_buffer().set_text(str(grid[i][j]), 1)

def resolver(*args):
    grid = []

    # preenche a grid pegando os números da UI
    for row in GRID_SUDOKU:
        linha = []
        for column in row:
            text = column.get_buffer().get_text()
            if text.isdigit():
                num = int(text)
                if 1 <= num <= 9:
                    linha.append(num)
                else:
                    linha.append(0)
            else:
                linha.append(0)
        grid.append(linha)

    # a parte legal
    def resolver():
        for i in range(9):
            for j in range(9):
                if grid[i][j] == 0:
                    for num in range(1, 10):
                        if eh_seguro(i, j, num):
                            grid[i][j] = num
                            if resolver():
                                return True
                            grid[i][j] = 0
                    return False
        return True
    def eh_seguro(row, col, num):
        # linha
        for x in range(9):
            if grid[row][x] == num:
                return False
        
        # coluna
        for x in range(9):
            if grid[x][col] == num:
                return False
        
        # bloco 3x3
        start_row, start_col = 3 * (row // 3), 3 * (col // 3)
        for i in range(3):
            for j in range(3):
                if grid[start_row + i][start_col + j] == num:
                    return False
        return True

    # fin
    if resolver():
        for i in range(9):
            for j in range(9):
                GRID_SUDOKU[i][j].get_buffer().set_text(str(grid[i][j]), 1)
        print("Sudoku resolvido com sucesso!")
    else:
        print("Sem solução possível")

app = Gtk.Application()
app.connect('activate', on_activate)

app.run(None)
