# Resumo de Algoritmos e Estruturas de Dados

Este resumo aborda os principais tópicos de Algoritmos e Estruturas de Dados, com base nos slides das aulas, no livro "Estruturas de Dados e Seus Algoritmos" de Jayme Luiz Szwarcfiter e Lilian Markenzon. O objetivo é auxiliar nos estudos para a prova, relacionando o conteúdo com as questões da atividade escrita.

## 1. Recursividade

A recursividade é uma técnica onde uma função chama a si mesma para resolver um problema, dividindo-o em instâncias menores e mais simples até atingir um caso base que pode ser resolvido diretamente.

**Ideia Central:**
* Resolver uma instância maior de um problema ($P(i)$) utilizando a solução de uma instância menor do mesmo problema ($P(j)$, onde $j < i$).

**Elementos Essenciais de uma Função Recursiva:**
1.  **Caso Base:** Uma ou mais condições onde a função retorna um valor diretamente, sem chamadas recursivas. É o ponto de parada da recursão.
2.  **Passo Recursivo:** A parte da função que reduz o problema e chama a si mesma com a instância menor. É crucial que o passo recursivo progrida em direção ao caso base.

**Exemplo: Fatorial**
O fatorial de um número $n$ ($Fat(n)$) pode ser definido recursivamente:
* $Fat(n) = n \cdot Fat(n-1)$, para $n > 0$
* $Fat(0) = 1$ (Caso Base)

**Código C99/C11 para Fatorial Recursivo:**
```c
int fatorial(int n) {
    if (n == 0) { // Caso base
        return 1;
    } else { // Passo recursivo
        return n * fatorial(n - 1);
    }
}

// Versão em uma linha (operador ternário)
int fatorial_ternario(int n) {
    return (n > 0) ? (n * fatorial_ternario(n - 1)) : 1;
}
````

**Vantagens da Recursividade:**

  * Soluções mais intuitivas e naturais para certos problemas (ex: Torres de Hanói).
  * Código mais conciso e, por vezes, mais fácil de entender e provar a correção.

**Desvantagens da Recursividade:**

  * **Desempenho:** Pode ser menos eficiente que soluções iterativas devido ao overhead das chamadas de função e gerenciamento da pilha de execução.
  * **Uso de Memória:** Cada chamada recursiva consome memória na pilha de execução para armazenar parâmetros, variáveis locais e o endereço de retorno. Uma recursão muito profunda ou infinita (sem caso base ou caso base inatingível) pode levar a um estouro de pilha (stack overflow).
  * **Recálculo:** Em alguns problemas (ex: Fibonacci recursivo simples), a mesma sub-instância pode ser calculada múltiplas vezes, levando à ineficiência.

**Pilha de Execução:**

  * O sistema operacional utiliza uma pilha para gerenciar as chamadas de função, incluindo as recursivas.
  * A cada chamada, o contexto atual é salvo (empilhado) e a nova chamada é executada.
  * Ao retornar, o contexto do topo da pilha é restaurado (desempilhado).

## 2. Análise de Complexidade Computacional

A análise de complexidade avalia a eficiência de um algoritmo em termos de recursos computacionais (tempo de execução e memória) consumidos em função do tamanho da entrada, independentemente do hardware ou software específico.

**Objetivos:**

  * Comparar diferentes algoritmos para o mesmo problema.
  * Prever o comportamento de um algoritmo para entradas grandes.

**Medidas Comuns:**

  * **Complexidade de Pior Caso (Big O - $O$):** Limite superior do número de operações. É a mais utilizada, pois garante um teto para o desempenho.
  * **Complexidade de Melhor Caso (Big Omega - $\Omega$):** Limite inferior do número de operações.
  * **Complexidade de Caso Médio (Big Theta - $\Theta$):** Desempenho esperado, considerando a probabilidade de cada tipo de entrada. Seu cálculo pode ser complexo e exigir conhecimento da distribuição das entradas.

**Operação Dominante:**

  * A operação básica executada com maior frequência no algoritmo. A contagem dessas operações é a base para a análise.

**Notação Big O ($O$):**

  * Descreve o limite assintótico superior do crescimento da função de complexidade.
  * Dizemos que $f(n)$ é $O(g(n))$ se existem constantes positivas $c$ e $n_0$ tal que $0 \le f(n) \le c \cdot g(n)$ para todo $n \ge n_0$. Essencialmente, $g(n)$ cresce pelo menos tão rápido quanto $f(n)$ para $n$ grande.
  * Ao usar a notação $O$, desprezam-se constantes multiplicativas e termos de menor ordem, pois o interesse está no comportamento para entradas suficientemente grandes.
      * Exemplo: Se um algoritmo executa $3n^2 + \frac{12}{8}n + 7$ operações, sua complexidade é $O(n^2)$. A parcela $3n^2$ domina para $n$ grande.

**Classes de Complexidade Comuns (em ordem crescente de eficiência para $n$ grande):**

  * $O(1)$: Constante (excelente)
  * $O(\log n)$: Logarítmica (muito bom)
  * $O(n)$: Linear (bom)
  * $O(n \log n)$: Linearítmica (bom para ordenação por comparação)
  * $O(n^2)$: Quadrática (aceitável para entradas pequenas)
  * $O(n^3)$: Cúbica (usável para entradas pequenas)
  * $O(2^n)$: Exponencial (ruim, geralmente inviável para entradas moderadas/grandes)
  * $O(n\!)$: Fatorial (muito ruim, inviável para entradas pequenas)

**Análise de Algoritmos Recursivos:**

  * Frequentemente envolve a definição de uma **fórmula de recorrência** ($T(n)$) que descreve o número de operações em função do tamanho da entrada $n$.
  * Exemplo (Fatorial):
      * $T(n) = T(n-1) + O(1)$ (uma chamada recursiva e uma multiplicação)
      * $T(0) = O(1)$ (caso base)
      * Resolvendo a recorrência, $T(n) = O(n)$.
  * Exemplo (Busca Binária):
      * $T(n) = T(n/2) + O(1)$
      * $T(1) = O(1)$
      * Resolvendo, $T(n) = O(\log n)$.
  * Exemplo (MergeSort):
      * $T(n) = 2T(n/2) + O(n)$ (duas chamadas recursivas e $O(n)$ para intercalar)
      * Resolvendo, $T(n) = O(n \log n)$.

## 3. Algoritmos de Ordenação

Algoritmos de ordenação rearranjam os elementos de uma coleção (como um vetor) em uma ordem específica (crescente ou decrescente).

**Conceitos Importantes:**

  * **Estabilidade (Stable Sort):** Um algoritmo de ordenação é estável se elementos com chaves iguais mantêm sua ordem relativa original após a ordenação.
  * **In-place:** Um algoritmo é in-place se ordena os elementos diretamente na estrutura de dados de entrada, usando uma quantidade de memória auxiliar constante (ou no máximo $O(\log n)$ para recursão).
  * **Online:** Um algoritmo é online se pode processar a entrada item por item, sem necessitar de todos os dados de uma vez.

**Algoritmos Comuns (e suas complexidades de pior caso em C99/C11):**

  * **Bubble Sort:**

      * Compara pares adjacentes e os troca se estiverem fora de ordem, repetindo até que nenhuma troca seja necessária.
      * Complexidade: $O(n^2)$.
      * Estável: Sim. In-place: Sim.

    ```c
    void bubbleSort(int arr[], int n) {
        int i, j;
        int swapped;
        for (i = 0; i < n - 1; i++) {
            swapped = 0;
            for (j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Trocar arr[j] e arr[j+1]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = 1;
                }
            }
            if (swapped == 0) // Otimização: se não houve trocas, está ordenado
                break;
        }
    }
    ```

  * **Selection Sort:**

      * Encontra o menor (ou maior) elemento da porção não ordenada e o coloca no início (ou fim) dessa porção.
      * Complexidade: $O(n^2)$.
      * Estável: Não naturalmente, mas pode ser implementado para ser. In-place: Sim.

    ```c
    void selectionSort(int arr[], int n) {
        int i, j, min_idx;
        for (i = 0; i < n - 1; i++) {
            min_idx = i;
            for (j = i + 1; j < n; j++) {
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            // Trocar o elemento mínimo encontrado com o primeiro elemento da parte não ordenada
            if (min_idx != i) {
                int temp = arr[min_idx];
                arr[min_idx] = arr[i];
                arr[i] = temp;
            }
        }
    }
    ```

  * **Insertion Sort:**

      * Constrói a lista ordenada um elemento por vez, inserindo cada novo elemento em sua posição correta na parte já ordenada.
      * Complexidade: $O(n^2)$. Melhor caso (lista já ordenada): $O(n)$.
      * Estável: Sim. In-place: Sim. Online: Sim.

    ```c
    void insertionSort(int arr[], int n) {
        int i, key, j;
        for (i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;
            // Move os elementos de arr[0..i-1] que são maiores que key
            // uma posição à frente de sua posição atual
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
    ```

  * **Merge Sort (Recursivo):**

      * Algoritmo de "dividir para conquistar".
        1.  Divide o vetor ao meio recursivamente até ter subvetores de tamanho 1 (que estão trivialmente ordenados).
        2.  Intercala (merge) os subvetores ordenados para produzir vetores maiores ordenados.
      * Complexidade: $O(n \log n)$ em todos os casos.
      * Estável: Sim (se a intercalação for implementada corretamente). In-place: Não (requer array auxiliar para intercalação, $O(n)$ de espaço).

    ```c
    // Função para intercalar dois subvetores de arr[]
    // O primeiro subvetor é arr[l..m]
    // O segundo subvetor é arr[m+1..r]
    void merge(int arr[], int l, int m, int r) {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        // Cria arrays temporários
        int L[n1], R[n2];

        // Copia dados para os arrays temporários L[] e R[]
        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];

        // Intercala os arrays temporários de volta em arr[l..r]
        i = 0; // Índice inicial do primeiro subvetor
        j = 0; // Índice inicial do segundo subvetor
        k = l; // Índice inicial do subvetor intercalado
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) { // Para manter a estabilidade
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // Copia os elementos restantes de L[], se houver
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Copia os elementos restantes de R[], se houver
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    // l é para o índice esquerdo e r é o índice direito do subvetor de arr a ser ordenado
    void mergeSort(int arr[], int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2; // Mesmo que (l+r)/2, mas evita overflow para l e r grandes

            // Ordena a primeira e a segunda metade
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);

            merge(arr, l, m, r);
        }
    }
    ```

    A análise de complexidade do MergeSort resulta em $T(n) = 2T(n/2) + \Theta(n)$, que leva a $O(n \log n)$.

  * **Quick Sort (Recursivo):**

      * Algoritmo de "dividir para conquistar".
        1.  Escolhe um elemento como pivô.
        2.  Particiona o array de forma que elementos menores que o pivô fiquem à sua esquerda e maiores à direita. O pivô fica em sua posição final.
        3.  Ordena recursivamente as sub-arrays à esquerda e à direita do pivô.
      * Complexidade:
          * Melhor e Médio Caso: $O(n \log n)$.
          * Pior Caso (ex: array já ordenado e pivô é sempre o primeiro/último): $O(n^2)$.
      * Estável: Não (depende da implementação do particionamento). In-place: Sim (geralmente, com espaço $O(\log n)$ para a pilha de recursão).

    ```c
    // Função para trocar dois elementos
    void swap(int* a, int* b) {
        int t = *a;
        *a = *b;
        *b = t;
    }

    // Esta função toma o último elemento como pivô, coloca
    // o pivô em sua posição correta no array ordenado,
    // e coloca todos os menores (menores que o pivô)
    // à esquerda do pivô e todos os maiores à direita do pivô
    int partition(int arr[], int low, int high) {
        int pivot = arr[high]; // pivô
        int i = (low - 1);   // Índice do menor elemento

        for (int j = low; j <= high - 1; j++) {
            // Se o elemento atual é menor ou igual ao pivô
            if (arr[j] <= pivot) { // Usar <= para tentar manter alguma estabilidade, mas não garante
                i++; // incrementa o índice do menor elemento
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }

    // Função principal que implementa QuickSort
    // arr[] --> Array a ser ordenado,
    // low --> Índice inicial,
    // high --> Índice final
    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            // pi é o índice de particionamento, arr[pi] está agora no lugar certo
            int pi = partition(arr, low, high);

            // Ordena separadamente os elementos antes e depois da partição
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    ```

    A escolha do pivô no QuickSort é crucial.

  * **Heap Sort:**

      * Usa a estrutura de dados Heap (geralmente Max-Heap).
        1.  Constrói um Max-Heap a partir do array de entrada ($O(n)$).
        2.  Repetidamente, remove o maior elemento do heap (a raiz), coloca-o no final da porção ordenada do array e reajusta o heap ($O(\log n)$ para cada remoção).
      * Complexidade: $O(n \log n)$ em todos os casos.
      * Estável: Não. In-place: Sim.

    ```c
    // Para transformar um subárvore com raiz no nó i em um heap
    // n é o tamanho do heap
    void heapify(int arr[], int n, int i) {
        int largest = i;   // Inicializa o maior como raiz
        int l = 2 * i + 1; // filho esquerdo = 2*i + 1
        int r = 2 * i + 2; // filho direito = 2*i + 2

        // Se o filho esquerdo é maior que a raiz
        if (l < n && arr[l] > arr[largest])
            largest = l;

        // Se o filho direito é maior que o maior até agora
        if (r < n && arr[r] > arr[largest])
            largest = r;

        // Se o maior não é a raiz
        if (largest != i) {
            swap(&arr[i], &arr[largest]);

            // Recursivamente heapify a subárvore afetada
            heapify(arr, n, largest);
        }
    }

    // Função principal para fazer o heap sort
    void heapSort(int arr[], int n) {
        // Constrói o heap (rearranja o array)
        for (int i = n / 2 - 1; i >= 0; i--) // Começa do último nó não-folha
            heapify(arr, n, i);

        // Extrai um por um os elementos do heap
        for (int i = n - 1; i > 0; i--) {
            // Move a raiz atual para o fim
            swap(&arr[0], &arr[i]);

            // chama max heapify no heap reduzido
            heapify(arr, i, 0);
        }
    }
    ```

**Limite Inferior para Ordenação por Comparação:**

  * Qualquer algoritmo de ordenação baseado em comparações entre elementos tem uma complexidade de pior caso de no mínimo $\Omega(n \log n)$.

## 4. Listas Sequenciais: Ordenadas vs. Não Ordenadas

Listas são estruturas de dados lineares. Quando implementadas com alocação sequencial (vetores), os elementos são armazenados em posições contíguas de memória.

**Listas Não Ordenadas (Sequenciais):**

  * **Inserção:**
      * Geralmente no final da lista: $O(1)$, se houver espaço.
      * Se verificar duplicatas: busca $O(n)$ + inserção $O(1) = O(n)$.
  * **Remoção:**
      * Busca do elemento ($O(n)$).
      * Mover último elemento para o "buraco": $O(1)$.
      * Deslocar elementos posteriores: $O(n)$.
  * **Busca:**
      * Busca sequencial: $O(n)$.
  * **Alteração:**
      * Busca ($O(n)$) + alteração ($O(1)$).

**Listas Ordenadas (Sequenciais):**

  * Mantêm os elementos em ordem.
  * **Inserção:**
      * Encontrar posição: $O(\log n)$ (busca binária) ou $O(n)$ (busca sequencial).
      * "Abrir espaço" (deslocar): $O(n)$.
      * Total: $O(n)$.
  * **Remoção:**
      * Busca: $O(\log n)$ ou $O(n)$.
      * "Fechar espaço" (deslocar): $O(n)$.
      * Total: $O(n)$.
  * **Busca:**
      * **Busca Binária:** $O(\log n)$.
      * Busca Sequencial Ordenada: Pior caso $O(n)$.
  * **Alteração:**
      * Se chave de ordenação muda: remover ($O(n)$) + reinserir ($O(n)$) = $O(n)$.

**Quando usar qual?**

  * **Listas Não Ordenadas:** Inserções frequentes, buscas raras, ordem não importa.
  * **Listas Ordenadas:** Buscas frequentes (busca binária), inserções/remoções menos comuns.

**Código C99/C11 para Busca Binária (em vetor ordenado):**

```c
// Retorna o índice de x em arr[l..r] se presente, senão -1
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}
```

## 5. Pilhas, Filas e Deques

### Pilhas (Stacks)

  * **Comportamento:** LIFO (Last In, First Out) / UEPS (Último a Entrar, Primeiro a Sair).
  * **Ponto de Acesso Principal:** Topo.
  * **Operações Principais:**
      * `Empilhar (Push)`: Adiciona elemento no topo.
      * `Desempilhar (Pop)`: Remove e retorna elemento do topo.
      * `Topo (Peek/Top)`: Retorna o elemento do topo sem remover.
      * `Vazia (IsEmpty)`: Verifica se a pilha está vazia.
  * **Implementação (vetor):**
      * Vetor para dados.
      * Variável `topo` para índice do elemento do topo.
  * **Exemplo de Aplicação:** Avaliação de expressões pós-fixadas.

**Código C99/C11 para Pilha (vetor estático):**

```c
#define MAX_PILHA 100

typedef struct {
    int itens[MAX_PILHA];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == MAX_PILHA - 1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int empilhar(Pilha *p, int valor) {
    if (pilhaCheia(p)) {
        return 0; // Erro: pilha cheia
    }
    p->topo++;
    p->itens[p->topo] = valor;
    return 1;
}

int desempilhar(Pilha *p, int *valorRemovido) {
    if (pilhaVazia(p)) {
        return 0; // Erro: pilha vazia
    }
    *valorRemovido = p->itens[p->topo];
    p->topo--;
    return 1;
}

int verTopo(Pilha *p, int *valorTopo) {
    if (pilhaVazia(p)) {
        return 0; // Erro: pilha vazia
    }
    *valorTopo = p->itens[p->topo];
    return 1;
}
```

-----

### Filas (Queues)

  * **Comportamento:** FIFO (First In, First Out) / PEPS (Primeiro a Entrar, Primeiro a Sair).
  * **Pontos de Acesso Principais:** Início (remoção) e Fim (inserção).
  * **Operações Principais:**
      * `Enfileirar (Enqueue)`: Adiciona elemento no fim.
      * `Desenfileirar (Dequeue)`: Remove e retorna elemento do início.
      * `Frente (Front/Peek)`: Retorna o elemento do início sem remover.
      * `Vazia (IsEmpty)`: Verifica se a fila está vazia.
  * **Implementações (vetor):**
    1.  **Início Fixo:** Início na posição 0. Remoção $O(n)$.
    2.  **Circular:** Vetor como círculo. Inserção e Remoção $O(1)$.
  * **Exemplo de Aplicação:** Gerenciamento de jobs de impressão.

**Código C99/C11 para Fila Circular (vetor estático):**

```c
#define MAX_FILA 100

typedef struct {
    int itens[MAX_FILA];
    int inicio;
    int fim;
    int nElementos;
} FilaCircular;

void inicializarFila(FilaCircular *f) {
    f->inicio = 0;
    f->fim = -1;
    f->nElementos = 0;
}

int filaCheia(FilaCircular *f) {
    return f->nElementos == MAX_FILA;
}

int filaVazia(FilaCircular *f) {
    return f->nElementos == 0;
}

int enfileirar(FilaCircular *f, int valor) {
    if (filaCheia(f)) {
        return 0; // Erro: fila cheia
    }
    f->fim = (f->fim + 1) % MAX_FILA;
    f->itens[f->fim] = valor;
    f->nElementos++;
    return 1;
}

int desenfileirar(FilaCircular *f, int *valorRemovido) {
    if (filaVazia(f)) {
        return 0; // Erro: fila vazia
    }
    *valorRemovido = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_FILA;
    f->nElementos--;
    return 1;
}

int verFrente(FilaCircular *f, int *valorFrente) {
    if (filaVazia(f)) {
        return 0; // Erro: fila vazia
    }
    *valorFrente = f->itens[f->inicio];
    return 1;
}
```

### Deques (Double-Ended Queues)

  * **Comportamento:** Permite inserção e remoção em ambas as extremidades.
  * **Operações Principais:** `InserirInício`, `InserirFim`, `RemoverInício`, `RemoverFim`, etc.
  * **Implementação (vetor):** Pode ser complexa para ter $O(1)$ em todas as operações; uma das extremidades pode ter operações $O(n)$ devido a deslocamentos.
  * **Exemplo de Aplicação:** Algoritmo de "sliding window maximum/minimum".

**Implementar uma Fila usando Duas Pilhas:**

  * Pilhas: `pilhaEntrada`, `pilhaSaida`.
  * **Enfileirar(elemento):** `empilhar(pilhaEntrada, elemento)`. ($O(1)$).
  * **Desenfileirar():**
    1.  Se `pilhaSaida` vazia, mover tudo de `pilhaEntrada` para `pilhaSaida` (desempilha de entrada, empilha em saida).
    2.  `desempilhar(pilhaSaida)`.
      * Custo Amortizado: $O(1)$. Pior Caso (single op): $O(N)$.

```c
// Pseudocódigo para Fila com Duas Pilhas

// Pilha pilhaEntrada, pilhaSaida;

// procedimento enfileirar(elemento)
//     empilhar(pilhaEntrada, elemento)

// procedimento desenfileirar()
//     se pilhaSaida estiver vazia então
//         enquanto pilhaEntrada não estiver vazia faça
//             elementoMovido = desempilhar(pilhaEntrada)
//             empilhar(pilhaSaida, elementoMovido)
//         fim enquanto
//     fim se

//     se pilhaSaida estiver vazia então
//         retornar ERRO_FILA_VAZIA
//     senão
//         retornar desempilhar(pilhaSaida)
//     fim se
```

-----

## 6\. Listas de Alocação Dinâmica (Encadeadas)

Memória alocada conforme a necessidade; elementos não contíguos.

**Listas Simplesmente Encadeadas:**

  * Cada nó: dado + ponteiro para o próximo. Último nó aponta para `NULL`.
  * **Nó Cabeça:** Nó especial no início, não armazena dados da lista, simplifica operações.

**Estrutura de um Nó em C99/C11:**

```c
struct No {
    int valor;
    struct No* prox;
};
typedef struct No No;
```

**Operações (com nó cabeça):**

  * **Percorrer:** Seguir ponteiros `prox` a partir de `cabeca->prox`.

    ```c
    void percorrerLista(No* cabeca) {
        No* atual = cabeca->prox;
        while (atual != NULL) {
            // Processar atual->valor
            atual = atual->prox;
        }
    }
    ```

  * **Inserção no Início ($O(1)$):**

    1.  Alocar novo nó.
    2.  `novoNo->prox = cabeca->prox;`
    3.  `cabeca->prox = novoNo;`

    <!-- end list -->

    ```c
    void inserirInicio(No* cabeca, int valor) {
        No* novoNo = (No*)malloc(sizeof(No));
        if (novoNo == NULL) return;
        novoNo->valor = valor;
        novoNo->prox = cabeca->prox;
        cabeca->prox = novoNo;
    }
    ```

  * **Inserção no Fim ($O(n)$):**

    1.  Percorrer até o último nó (ou nó cabeça se vazia).
    2.  Alocar novo nó, `novoNo->prox = NULL;`
    3.  `ultimoNo->prox = novoNo;`

    <!-- end list -->

    ```c
    void inserirFim(No* cabeca, int valor) {
        No* novoNo = (No*)malloc(sizeof(No));
        if (novoNo == NULL) return;
        novoNo->valor = valor;
        novoNo->prox = NULL;

        No* atual = cabeca;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoNo;
    }
    ```

  * **Busca ($O(n)$):** Percorrer comparando.

    ```c
    No* buscar(No* cabeca, int valor) {
        No* atual = cabeca->prox;
        while (atual != NULL) {
            if (atual->valor == valor) {
                return atual;
            }
            atual = atual->prox;
        }
        return NULL;
    }
    ```

  * **Remoção ($O(n)$):**

    1.  Manter ponteiros `anterior` e `atual`.
    2.  Encontrar `atual` a ser removido.
    3.  `anterior->prox = atual->prox;`
    4.  `free(atual);`

    ```c
    int remover(No* cabeca, int valor) {
        No* anterior = cabeca;
        No* atual = cabeca->prox;

        while (atual != NULL && atual->valor != valor) {
            anterior = atual;
            atual = atual->prox;
        }

        if (atual == NULL) {
            return 0; // Não encontrado
        }

        anterior->prox = atual->prox;
        free(atual);
        return 1;
    }
    ```

**Listas Encadeadas Ordenadas:**

  * **Inserção ($O(n)$):** Encontrar posição correta e ajustar ponteiros.
  * **Remoção ($O(n)$):** Busca pode ser otimizada.

**Pilhas e Filas com Listas Encadeadas:**

  * **Pilha:** Inserção/Remoção no início ($O(1)$).
  * **Fila:** Remoção no início ($O(1)$). Inserção no fim ($O(1)$ se mantiver ponteiro para o fim).

**Buffering de Pacotes em um Roteador:**

  * **Fila:** Ideal para processamento FIFO de pacotes.
  * **Pseudocódigo (Fila Encadeada com `cabeca` e `fim` para $O(1)$ em enfileirar):**
    ```c
    // No* cabecaFilaPacotes; // nó cabeça
    // No* fimFilaPacotes;   // ponteiro para o último nó

    // procedimento inicializarRoteador()
    //     cabecaFilaPacotes = (No*)malloc(sizeof(No));
    //     cabecaFilaPacotes->prox = NULL;
    //     fimFilaPacotes = cabecaFilaPacotes;

    // procedimento receberPacote(pacote)
    //     No* novoPacoteNo = (No*)malloc(sizeof(No));
    //     // verificar novoPacoteNo
    //     novoPacoteNo->valor = pacote;
    //     novoPacoteNo->prox = NULL;
    //
    //     fimFilaPacotes->prox = novoPacoteNo;
    //     fimFilaPacotes = novoPacoteNo;

    // procedimento enviarPacote()
    //     se cabecaFilaPacotes->prox != NULL então // Fila não vazia
    //         No* pacoteAEnviarNo = cabecaFilaPacotes->prox;
    //         pacote = pacoteAEnviarNo->valor;
    //
    //         cabecaFilaPacotes->prox = pacoteAEnviarNo->prox;
    //         if (cabecaFilaPacotes->prox == NULL) então
    //             fimFilaPacotes = cabecaFilaPacotes;
    //         fim se
    //         free(pacoteAEnviarNo);
    //
    //         transmitirPacoteParaRede(pacote);
    //     fim se
    ```
