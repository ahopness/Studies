# Instruções para execução (rodar comandos no terminal):
# - Verificar se python esta instalado:
# - - Windows: "winget install python3"
# - - Linux(sistemas debian): "sudo apt install python3"
# - - MacOS: "brew install python3"
# - Verificar se o sympy esta instalado:
# - - "pip install sympy"
#
# Informações adicionais sobre o codigo:
# - criei uma classe pra ficar mais facil de calcular
# todos os limites usando um for loop.

from sympy import *

class lim:
    def __init__(self, func, tend):
        self.func = func
        self.tend = tend

x = symbols('x')

f = ((x - 3)
    /
    (sqrt(x) - sqrt(3)))
limite_f = lim(f, 3) # lim f(), onde x -> 3

g = ((pow(x, 2) - 1)
    /
    (abs(x - 1)))
limite_g = lim(g, 1) # lim g(), onde x -> 1

h = ((abs(x +  2))
    /
    (pow(x, 2) - 4))
limite_h = lim(h, 2) # lim h(), onde x -> -2

i = ((1 - x)
    /
    (sqrt(x - 1) - 2))
limite_i = lim(i, 5) # lim i(), onde x -> 5

for limite in [limite_f, limite_g, limite_h, limite_i]:
    limite_esquerdo = limit(limite.func, x, limite.tend, '-')
    limite_direito = limit(limite.func, x, limite.tend, '+')
    limite_em_1 = limite.func.subs(x, 1)

    print("A função", limite.func, "é...")
    print(limite_esquerdo, "a esquerda,")
    print(limite_direito, "a direita")
    if limite_esquerdo == limite_direito:
        print("é definido em", limite.tend)
    else:
        print("é não é definido em", limite.tend)
    print("\n")

