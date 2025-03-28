# Instruções para execução (executar comandos no terminal):
# - Verificar se python esta instalado:
# - - Windows: "winget install python3"
# - - Linux (com sistemas debian): "sudo apt install python3"
# - - MacOS: "brew install python3"
# - Verificar se o sympy esta instalado:
# - - "pip install sympy"
#
# Informações adicionais sobre o codigo:
# - criei a classe 'lim(função, tendencia)' para facilitar
# o calculo de todos os limites usando um for loop.

from sympy import *

class lim:
    def __init__(self, func, tend):
        self.func = func
        self.tend = tend
    
    def esquerdo(self):
        return limit(self.func, x, self.tend, '-')
    def direito(self):
        return limit(self.func, x, self.tend, '+')

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
    print("A função", limite.func, "é")

    print(limite.esquerdo(), "a esquerda,")
    print(limite.direito(), "a direita")

    if limite.esquerdo() == limite.direito():
        print("e é definido em", limite.tend)
    else:
        print("e é não é definido em", limite.tend)
    
    print("\n")

