**12/03 - Algoritmos e Estrutura de Dados - Recursividade**

- Quando uma tarefa não possui etapas claras ou insuficientes para ser finalizada, ela pode se *auto-iterar* varias vezes para chegar em um resultado, isso é oque nós chamamos de recursividade.

<br>
<div align="center"><img height="250px" src="https://media2.dev.to/dynamic/image/width=1600,height=900,fit=cover,gravity=auto,format=auto/https%3A%2F%2Fdev-to-uploads.s3.amazonaws.com%2Fuploads%2Farticles%2F3y9pghpnsf19nlvivn2r.jpg"></img></div>

---

### Como funciona

- Temos que programar um <ins>fatorial</ins> usando a seguinte formula matematica em mente: `fat(n) = n * n-1 * ... * 1`

- Na tentativa de criar um **caso recursivo** sobre nossso fatorial, temos o seguinte codigo: `int fat(int n) { return n * fat(n-1); }`

- Pela falta de um **caso base**, tal codigo acaba rodando infinitamente (ou até a nossa runtime reclamar de *stack overflow*), podemos concertar isso inserindo um argumento onde a execução se denomina completa:

```
int fat(int n)
{
    if (n>0) return n * fat(n-1);
    else if (n==0) return 1;
}
```

*Note que o codigo de fatoração, o 'n * fat(n-1)' ainda esta presente, mas agora esta cercado com um passos a mais para não sofrer um stack overflow.*

---

### Recursividade X Iteração

- **Desvantagens:** em certos caso, iteração pode exigir menos da maqiuna por adminstrar variaveis de forma mais inteligente, diminuindo o numero de repetições de certas tarefas.
    - Um exemplo disso seria uma sequencia de *fibonacci*: (sem programação dinamica) onde, pela falta de acesso a rotas de optimização (como variavéis locais e loops), ele acaba necessitando de mais processamento para re-descobrir os valores faltosos
<br>

- **Vantagens:** Alguns procedimentos precisam de instruções mais nitidas para serem efetuados, necessidade que seria somente possivel atender com a automação de um processo iterativo.
    - Um exemplo disso seria uma *torre de hanói*: onde, para mover cada aro, é necessario intruções claras ou um algoritmo mais complicado para as movimentações.