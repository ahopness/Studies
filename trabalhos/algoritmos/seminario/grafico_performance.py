import matplotlib.pyplot as plt
import numpy as np

n = np.linspace(0, 10, 100)
y = n**3

plt.plot(n, y, 'b-', linewidth=2, label='O(n³)')
plt.plot(9, 9**3, 'ro', markersize=8, label='O(9³)')

plt.grid(True, alpha=0.3)

plt.title('Complexidade de O(n³)')

plt.xlabel('Tamanho da Entrada (nº de elementos)')
plt.ylabel('Tempo de Execução (s)')
plt.legend()

plt.xlim(0, 10)
plt.ylim(0, 1000)

plt.show()