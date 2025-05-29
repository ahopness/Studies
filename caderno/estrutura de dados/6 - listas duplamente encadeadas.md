**21/05 - Algoritmos e Estruturas de Dados - Listas Duplamente Encadeadas**

-   Nesta aula, continuamos a explorar a alocação dinâmica, focando nas listas duplamente encadeadas e suas variações, que oferecem novas funcionalidades e otimizações em relação às listas simplesmente encadeadas.

---

### Listas Simplesmente Encadeadas: O Problema

-   Em uma **lista simplesmente encadeada**, cada elemento (nó) aponta apenas para o **próximo** elemento.
-   Um desafio surge: como descobrir o elemento que **antecede** um nó específico?
    -   A única forma é percorrer a lista desde o início até que `aux->prox` seja o nó desejado.
    -   Essa operação tem um custo de $O(n)$ (linear), o que pode ser ineficiente.

---

### Listas Duplamente Encadeadas (LDE)

-   Para resolver o problema do antecessor, as **listas duplamente encadeadas (LDE)** introduzem um segundo ponteiro em cada nó.
-   **Estrutura de um Nó em LDE**:
    * **Dados**: A informação armazenada.
    * Ponteiro `prox`: Aponta para o próximo nó na lista.
    * Ponteiro `ant`: Aponta para o nó anterior na lista.
-   **Nó Cabeça em LDE**:
    * Assim como nas listas simplesmente encadeadas com cabeça, este nó não guarda dados da lista.
    * `cabeca->prox` aponta para o primeiro elemento real (ou `NULL` se vazia).
    * `cabeca->ant` aponta para `NULL` (pois não há ninguém antes da cabeça).
-   **Percorrendo a Lista**:
    * Para frente (usando `prox`): Similar à lista simplesmente encadeada.
    * Para trás: Pode-se percorrer usando o ponteiro `ant` a partir de um nó.

---

### Operações em Listas Duplamente Encadeadas (LDE)

-   **Inserção na Primeira Posição (Não Ordenada)**:
    1.  Cria-se um `novo` nó.
    2.  `novo->prox` aponta para o antigo primeiro elemento (`cabeca->prox`).
    3.  `novo->ant` aponta para `cabeca`.
    4.  Se a lista não estava vazia, o `ant` do antigo primeiro elemento (`cabeca->prox->ant`) deve apontar para o `novo` nó.
    5.  `cabeca->prox` passa a apontar para `novo`.
    * **Custo**: $O(1)$.
-   **Inserção na Última Posição (Não Ordenada)**:
    1.  Percorre-se a lista com um ponteiro `aux` até `aux->prox == NULL` (encontrar o último elemento).
    2.  Cria-se um `novo` nó.
    3.  `novo->prox = NULL`.
    4.  `novo->ant = aux` (o antigo último).
    5.  `aux->prox = novo`.
    * **Custo**: $O(n)$ (devido à busca pelo último elemento).
-   **Busca**:
    * **Não Ordenada**: Percorre a lista comparando cada elemento. Custo $O(n)$.
    * **Ordenada (LDE-O)**: Percorre a lista. Se um elemento maior que o buscado é encontrado, a busca pode parar, pois o elemento não estará mais à frente. Custo $O(n)$.
-   **Inserção em Lista Duplamente Encadeada Ordenada (LDE-O)**:
    1.  Cria-se o `novo` nó.
    2.  Se a lista estiver vazia (`cabeca->prox == NULL`), o `novo` nó é inserido após a `cabeca` (similar à inserção na primeira posição de lista vazia).
    3.  Senão, usa-se a função `Buscar` (para LDE-O) para encontrar o nó `aux` onde a inserção deve ocorrer.
        * Se `aux->valor > _valor` (onde `_valor` é o valor do novo nó), o `novo` nó deve ser inserido **antes** de `aux`. Envolve ajustar `novo->prox`, `novo->ant`, `aux->ant->prox` e `aux->ant`.
        * Senão (o `novo` nó deve ser inserido **após** `aux`, pois `_valor` é maior ou igual ao valor de `aux` e `aux` é o último ou o ponto onde a busca parou), ajusta-se `novo->prox`, `novo->ant` e `aux->prox`.
    * **Custo**: $O(n)$ (devido à busca pela posição correta).
-   **Remoção**:
    1.  Busca-se o elemento a ser removido (`aux`). A vantagem da LDE é que `aux->ant` já nos dá o predecessor direto.
    2.  Se `aux` for encontrado e não for a cabeça:
        * O `prox` do nó anterior a `aux` (`aux->ant->prox`) deve apontar para o `prox` de `aux` (`aux->prox`).
        * Se `aux` não for o último elemento (`aux->prox != NULL`), o `ant` do nó posterior a `aux` (`aux->prox->ant`) deve apontar para o `ant` de `aux` (`aux->ant`).
        * Libera-se a memória de `aux` (`free(aux)`).
    * **Custo**: $O(n)$ (devido à busca). Se o elemento a ser removido for o primeiro ou o último (e tivermos um ponteiro para ele), o custo pode ser $O(1)$ para a remoção em si após a localização.

---

### Listas Duplamente Encadeadas Circulares (LDEC)

-   Em uma LDEC, o ponteiro `prox` do último elemento aponta para o nó `cabeça`, e o ponteiro `ant` do nó `cabeça` aponta para o último elemento.
-   **Vantagens**:
    * Pode-se percorrer a lista em qualquer direção continuamente.
    * Acesso ao último elemento em $O(1)$ através de `cabeca->ant`.
    * Acesso ao primeiro elemento em $O(1)$ através de `cabeca->prox`.
-   **Lista Vazia em LDEC**: `cabeca->prox = cabeca` e `cabeca->ant = cabeca`.
-   **Travessia e Busca**: A condição de parada geralmente muda de `aux != NULL` para `aux != cabeca`.
-   **Operações em LDEC (Não Ordenada)**:
    * **Inserção no Início**: Ajusta os ponteiros `prox` e `ant` do novo nó, do `cabeca` e do antigo primeiro elemento (`cabeca->prox`). **Custo**: $O(1)$.
    * **Inserção no Fim**: Usa `cabeca->ant` para acessar o último. Ajusta os ponteiros do novo nó, do `cabeca` e do antigo último elemento. **Custo**: $O(1)$.
    * **Remoção**: Após buscar o nó `aux`, a remoção envolve fazer `aux->ant->prox = aux->prox` e `aux->prox->ant = aux->ant`, e então liberar `aux`.
        * Remoção do primeiro ou último: $O(1)$ (após identificação).
        * Remoção de elemento específico: $O(n)$ (busca).

---

### LDEC Ordenadas (LDEC-O)

-   Mantêm os elementos em ordem de forma circular e duplamente encadeada.
-   **Busca**: Similar à LDE-O, mas a condição de parada leva em conta `aux != cabeca` e a condição de ordenação (`aux->valor < _valor`).
-   **Inserção Ordenada**:
    1.  Realiza-se a busca pelo local de inserção. Seja `aux` o resultado da busca.
    2.  Se `aux == cabeca` (lista vazia ou novo valor é maior que todos), insere-se o `novo` nó como o último elemento (conectando-o entre `cabeca->ant` e `cabeca`).
    3.  Senão (`aux != cabeca`), o `novo` nó é inserido antes de `aux`.
    * **Custo**: $O(n)$ (devido à busca).

---

### Aplicações e Conclusões

-   **Filas, Pilhas e Deques em LDEC**:
    * **Pilha**: Inserção no início ($O(1)$) e remoção do início ($O(1)$).
    * **Fila**: Inserção no final ($O(1)$) e remoção do início ($O(1)$).
    * **Deque**: Todas as operações (inserção/remoção no início/fim) tornam-se $O(1)$.
-   **Vantagens Gerais das Listas Encadeadas**:
    * Consumo de memória proporcional ao uso.
    * Facilidade na implementação de filas e pilhas (especialmente com LDEC).
-   **Desvantagem Principal**:
    * Não há acesso direto a uma posição; é preciso navegar por ponteiros.
    * Isso implica que a busca (mesmo em listas ordenadas) tem complexidade mínima de $O(n)$, impedindo a busca binária.
-   Para buscas mais eficientes, estruturas como **árvores** (especialmente Árvores Binárias de Busca) serão exploradas futuramente.
