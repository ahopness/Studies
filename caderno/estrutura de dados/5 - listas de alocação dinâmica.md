**12/05 - Algoritmos e Estruturas de Dados - Listas de Alocação Dinâmica**

- Nesta aula, exploramos a alocação dinâmica de memória e como ela é utilizada para construir listas encadeadas, uma estrutura de dados flexível e eficiente para diversas aplicações.

---

### Alocação Estática vs. Dinâmica

-   **Alocação Estática (ou Sequencial)**:
    * Toda a memória para a estrutura é alocada de uma só vez, em um bloco contínuo.
    * Um exemplo clássico é um **vetor**.
    * **Vantagem**: Acesso direto a qualquer elemento é rápido (ex: para ir à posição 10, basta calcular um deslocamento a partir do início).
    * **Desvantagem**: O tamanho é fixo. Se declararmos muito espaço e usarmos pouco, há desperdício. Se precisarmos de mais espaço do que o declarado, falta memória.
-   **Alocação Dinâmica**:
    * A memória é alocada conforme a necessidade, pedaço por pedaço.
    * Quando um novo elemento precisa ser inserido, um novo bloco de memória é alocado para ele.
    * Como os elementos são alocados individualmente, eles podem estar em posições de memória não contíguas.
    * **Problema**: Se os elementos estão espalhados, como localizar um elemento específico, como o décimo da lista?
    * **Solução**: **Ponteiros!** Cada elemento da lista guarda, além de sua informação, um "endereço" que aponta para o próximo elemento da lista. Sabendo onde está o primeiro, podemos seguir os ponteiros para percorrer toda a lista.

---

### Listas Encadeadas (Linked Lists)

-   Uma lista encadeada é uma sequência de elementos, chamados **nós**.
-   **Estrutura de um Nó**:
    * **Dados**: A informação que queremos armazenar (ex: um número, um nome, etc.).
    * **Ponteiro (`próximo`)**: Uma referência (endereço) para o próximo nó na sequência. O último nó aponta para `NULL` (nada).
-   **Listas Simplesmente Encadeadas**:
    * Cada nó aponta apenas para o próximo.
    * **Implementação com Cabeça**:
        * Existe um nó especial no início, chamado **cabeça** (ou `head`).
        * Este nó cabeça **não guarda dados** da lista; ele serve apenas para marcar o início e seu ponteiro `próximo` aponta para o primeiro nó real da lista (ou `NULL` se a lista estiver vazia).
        * **Vantagem**: Simplifica algumas operações, pois sempre existe um nó cabeça, evitando verificações de lista vazia em certos contextos.
        * **Desvantagem**: Um nó "extra" para gerenciar.
        * (A aula opta por esta abordagem).
-   **Percorrendo a Lista**:
    1.  Começa-se com um ponteiro auxiliar apontando para o que o `cabeça->próximo` aponta (o primeiro elemento real).
    2.  Enquanto o ponteiro auxiliar não for `NULL`:
        * Acessa-se o dado do nó atual.
        * Move-se o ponteiro auxiliar para `aux->próximo`.
-   **Definindo a Lista (o Cabeça)**:
    * O nó cabeça é alocado dinamicamente.
    * Seu ponteiro `próximo` é inicializado como `NULL` (lista vazia).

---

### Operações em Listas Encadeadas Não Ordenadas

-   **Inserção**:
    * **Na Primeira Posição (Início)**:
        1.  Aloca-se memória para o novo nó e preenche-se seus dados.
        2.  O ponteiro `próximo` do novo nó deve apontar para onde o `cabeça->próximo` atualmente aponta (o antigo primeiro elemento, ou `NULL` se a lista estava vazia).
        3.  O ponteiro `cabeça->próximo` é atualizado para apontar para o novo nó.
        * **Custo**: $O(1)$ (constante, muito rápido).
    * **Na Última Posição (Fim)**:
        1.  Primeiro, é preciso percorrer a lista desde o início até encontrar o último elemento (aquele cujo `próximo` é `NULL`). Se a lista for com cabeça, o ponteiro auxiliar começa em `cabeça` e avança enquanto `aux->próximo != NULL`.
        2.  Aloca-se memória para o novo nó e preenche-se seus dados. O `próximo` do novo nó será `NULL`.
        3.  O ponteiro `próximo` do antigo último elemento é atualizado para apontar para o novo nó.
        * **Custo**: $O(n)$ (linear, depende do tamanho da lista, pois precisa percorrê-la).
-   **Observação Importante sobre Alocação Dinâmica**:
    * Uma vez que um nó é alocado e inserido, o acesso a ele é feito através da estrutura da lista (seguindo os ponteiros desde a cabeça).
    * Se um ponteiro no meio da lista for perdido, toda a parte subsequente da lista pode se tornar inacessível (**memory leak** se não for liberada).
    * É crucial **liberar a memória** (`free()`) dos nós quando eles não são mais necessários para evitar consumir toda a memória do computador.
-   **Busca**:
    * **Busca Binária**: Não é possível, pois não há acesso direto aos elementos pelo índice. Para chegar ao "meio", precisaríamos percorrer metade da lista de qualquer forma.
    * **Busca Sequencial (Exaustiva)**:
        1.  Começa-se do primeiro elemento.
        2.  Verifica-se cada elemento até que o valor desejado seja encontrado ou a lista termine.
        * **Custo**: $O(n)$.
-   **Remoção**:
    1.  **Buscar o elemento**: Primeiro, localiza-se o nó a ser removido. É crucial, durante a busca, manter um ponteiro para o nó **anterior** ao que será removido.
    2.  **Atualizar ponteiros**: O ponteiro `próximo` do nó *anterior* deve passar a apontar para o nó *sucessor* do nó que está sendo removido. (Ex: `anterior->prox = aux->prox`, onde `aux` é o nó a ser removido).
    3.  **Liberar memória**: O nó removido deve ter sua memória liberada (`free(aux)`).
    * **Por que o anterior?** Se simplesmente removêssemos o nó, o encadeamento seria quebrado, e perderíamos o restante da lista. O nó anterior é necessário para "religar" a lista.
    * **Custo**: $O(n)$ (devido à busca).

---

### Listas Encadeadas Ordenadas

-   Mantêm os elementos em uma ordem específica (ex: crescente).
-   **Busca**:
    * Pode ser otimizada: a busca para quando se encontra o elemento, ou quando se encontra um elemento maior que o buscado (sabendo que não estará mais à frente).
    * **Custo**: $O(n)$ no pior caso, mas pode ser mais rápido em média se o elemento estiver no início ou não existir e essa condição for detectada cedo.
-   **Inserção**:
    * Não pode ser simplesmente no início ou no fim.
    * É preciso buscar a posição correta para manter a ordem. Durante a busca, mantém-se um ponteiro para o nó **anterior** (`ant`) e o atual (`aux`).
    * O novo nó será inserido entre `ant` e `aux`.
        1.  Aloca-se o novo nó e preenchem-se os dados.
        2.  `novo->prox` aponta para `aux`.
        3.  `ant->prox` aponta para `novo`.
    * Casos a tratar: inserção em lista vazia, no início, no meio, ou no fim. A lógica geral com `ant` e `aux` (onde `ant` começa como `cabeça` e `aux` como `cabeça->prox`) costuma cobrir esses casos.
    * **Custo**: $O(n)$ (devido à busca pela posição).
-   **Remoção**:
    * Similar à lista não ordenada: busca-se o elemento (a busca pode ser a otimizada para listas ordenadas), mantendo o `anterior`.
    * Se encontrado, `ant->prox = aux->prox` e `free(aux)`.
    * **Custo**: $O(n)$.
-   **Alteração**:
    * Em listas não ordenadas, pode-se alterar o valor diretamente.
    * Em listas ordenadas, alterar o valor de um nó pode quebrar a ordenação. A forma correta é **remover** o nó com o valor antigo e depois **inserir** um novo nó com o novo valor (que encontrará sua posição correta).

---

### Filas, Pilhas e Deques com Listas Encadeadas

-   Assim como com vetores, podemos usar listas encadeadas para implementar estas estruturas, aplicando regras específicas de inserção e remoção:
    -   **Filas (FIFO - Primeiro a Entrar, Primeiro a Sair)**:
        * `Enfileirar (Enqueue)`: Inserção no **final** da lista. Custo $O(n)$ em lista simplesmente encadeada (precisa percorrer até o fim).
        * `Desenfileirar (Dequeue)`: Remoção do **início** da lista. Custo $O(1)$.
    -   **Pilhas (LIFO - Último a Entrar, Primeiro a Sair)**:
        * `Empilhar (Push)`: Inserção no **início** da lista. Custo $O(1)$.
        * `Desempilhar (Pop)`: Remoção do **início** da lista. Custo $O(1)$.
    -   **Deques (Double-Ended Queues - Filas de Duas Pontas)**:
        * Operações na ponta esquerda (início da lista): Inserção $O(1)$, Remoção $O(1)$.
        * Operações na ponta direita (fim da lista): Inserção $O(n)$, Remoção $O(n)$ (para encontrar o penúltimo para remoção do último).

---

### Variações de Listas Encadeadas

-   Existem outras formas de listas que podem otimizar certas operações:
    -   **Listas Duplamente Encadeadas**: Cada nó tem um ponteiro para o **próximo** e um para o **anterior**.
        * Facilita a remoção (não precisa buscar o anterior explicitamente) e a navegação em ambos os sentidos.
    -   **Listas Circulares**: O último nó aponta de volta para o primeiro (ou para o nó cabeça).
    -   **Listas Duplamente Encadeadas Circulares**: Combinam as duas características.
    -   **Benefícios**: Podem reduzir o custo de operações. Por exemplo, uma **Fila** implementada com lista duplamente encadeada circular pode ter inserção e remoção em $O(1)$.
