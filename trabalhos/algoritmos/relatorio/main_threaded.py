import sys
sys.setrecursionlimit(1000000)

import random
max_elemento = 1000

def gerar_vetor_crescente(tamanho):
    return [i for i in range(tamanho)]
def gerar_vetor_decrescente(tamanho):
    return [i for i in range(tamanho-1, -1, -1)]
def gerar_vetor_aleatorio(tamanho):
    return [random.randint(1, max_elemento) for _ in range(tamanho)]

import time
def calcular_tempo(func_sort, tamanho, resultados):
    inicio = time.time()
    func_sort(tamanho)
    fim = time.time()
    resultados.append(fim - inicio)

min_tamanho = 1
max_tamanho = 5000 + 1
step_tamanho = 100

from bubblesort import *
from quicksort import *

import matplotlib.pyplot as plt
import threading
def processar_grafo(tamanhos, func_gerar_vetor, nome_arquivo):
    tempos_bubble = []
    tempos_quick = []

    for tamanho in tamanhos:
        vetor = func_gerar_vetor(tamanho)

        thread_bubble = threading.Thread(target=calcular_tempo, args=(bubble_sort, vetor.copy(), tempos_bubble,))
        thread_quick = threading.Thread(target=calcular_tempo, args=((lambda tam: quick_sort(tam, 0, tamanho-1)), vetor.copy(), tempos_quick,))

        thread_bubble.start()
        thread_quick.start()

        thread_bubble.join()
        thread_quick.join()

        print(tempos_bubble[-1], ",", tempos_quick[-1])

    plt.clf()

    plt.plot(tamanhos, tempos_bubble, label="Bubble Sort")
    plt.plot(tamanhos, tempos_quick, label="Quick Sort")

    plt.xlabel('Tamanho da Entrada (nº de elementos)')
    plt.ylabel('Tempo de Execução (s)')
    plt.legend()
    
    plt.savefig(nome_arquivo + ".svg")
    print(nome_arquivo, "pronto!\n")

if __name__ == "__main__":
    tamanhos_ordinarios = range(min_tamanho, max_tamanho, step_tamanho)
    processar_grafo(tamanhos_ordinarios, gerar_vetor_crescente, "ordinarios_crescente")
    processar_grafo(tamanhos_ordinarios, gerar_vetor_decrescente, "ordinarios_decrescente")
    processar_grafo(tamanhos_ordinarios, gerar_vetor_aleatorio, "ordinarios_aleatorio")

    tamanhos_multiplos = [50, 500, 5000, 50000]
    processar_grafo(tamanhos_multiplos, gerar_vetor_crescente, "multiplos_crescente")
    processar_grafo(tamanhos_multiplos, gerar_vetor_decrescente, "multiplos_decrescente")
    processar_grafo(tamanhos_multiplos, gerar_vetor_aleatorio, "multiplos_aleatorio")

    print("\ntudo pronto!")
