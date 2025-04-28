**28/04 - Algoritmos e Estrutura de Dados - Pilhas, Filas e Deques**

- Ao modificar o comportamento dos operadores de inserção e remoção em estruturas de dados, podemos criar novas organizações como pilhas, filas e deques. Cada uma possui regras específicas para adicionar e remover elementos, impactando como os dados são acessados e gerenciados.

---

### Pilhas (Stacks)

- A principal característica da pilha é o comportamento **LIFO** (Last In - First Out) ou **UEPS** (Último a Entrar - Primeiro a Sair). Isso significa que o último elemento adicionado é sempre o primeiro a ser removido.
- Para controlar uma pilha, precisamos apenas de uma informação: o **topo**. Todas as operações (inserção e remoção) ocorrem no topo.
- **Operações:**
    - `Empilhar (Push)`: Insere um novo elemento no topo da pilha. O elemento é adicionado após o último existente e o indicador de topo é atualizado.
    - `Desempilhar (Pop)`: Remove e retorna o elemento que está no topo da pilha. É preciso verificar se a pilha não está vazia, salvar o elemento do topo, decrementar o indicador do topo e retornar o elemento salvo.
- **Implementação:** Geralmente usa-se um vetor (alocação estática ou dinâmica) para armazenar os elementos. Uma variável `topo` indica a próxima posição livre ou o último elemento inserido.

---

### Filas (Queues)

- Filas seguem o comportamento **FIFO** (First In - First Out) ou **PEPS** (Primeiro a Entrar - Primeiro a Sair). O primeiro elemento que entrou na fila é o primeiro a ser atendido (removido).
- Diferente das pilhas, filas precisam controlar o **início** (onde se remove) e o **fim** (onde se insere).
- **Operações:**
    - `Enfileirar (Enqueue)`: Adiciona um elemento no final da fila.
    - `Desenfileirar (Dequeue)`: Remove e retorna o elemento do início da fila.
- **Implementações Comuns:**
    1.  **Início Fixo:** O início é sempre a posição 0 do vetor. A inserção é O(1), mas a remoção é O(n) porque todos os elementos restantes precisam ser deslocados para preencher o espaço vazio.
    2.  **Circular:** O vetor é tratado como um círculo, onde o final se conecta ao início. Utiliza variáveis para `inicio` e `nElementos` (ou `fim`). Tanto a inserção quanto a remoção são O(1).

---

### Deques (Double-Ended Queues)

- Deques são estruturas que permitem inserção e remoção de elementos em **ambas as extremidades** (início e fim).
- As inserções ocorrem após o último elemento de uma ponta, e as remoções pegam o primeiro elemento da ponta escolhida.
- **Implementação (com vetor):** A implementação circular usada em filas não é diretamente aplicável. A remoção em uma das pontas pode exigir deslocamento dos elementos, resultando em custo O(n). É preciso indicar em qual extremo (esquerdo ou direito) a operação será realizada.