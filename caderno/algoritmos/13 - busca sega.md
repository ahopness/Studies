**XX/XX - Projeto e Análise de Algoritmos - Busca Cega**

- Um problema de busca consiste em encontrar uma sequência de ações que leve de um **estado inicial** até um **estado objetivo**.
- **Busca Cega (ou Não Informada):** São estratégias de busca que não possuem nenhuma informação adicional sobre o problema além da sua definição. Elas não sabem se um estado é "mais promissor" que outro, explorando o espaço de busca de forma sistemática.

---

### Estrutura de Dados de Árvore em Problemas de Busca

Para entender como os algoritmos de busca funcionam, é fundamental compreender a estrutura de dados de **árvore**, que é usada para representar o espaço de busca.

- **Nó (Node):** Cada nó na árvore representa um **estado** do problema. Ele contém informações como:
    - O estado correspondente.
    - O **nó pai** (o nó que gerou o estado atual).
    - A **ação** que foi aplicada ao pai para gerar este nó.
    - O **custo do caminho** desde o estado inicial até este nó.
- **Raiz (Root):** É o nó inicial da árvore, correspondendo ao **estado inicial** do problema.
- **Folhas (Leaves):** São os nós que não têm filhos, ou seja, são os nós na "fronteira" da busca, que ainda não foram expandidos.
- **Ramificação (Branching):** O processo de gerar nós filhos a partir de um nó pai é chamado de **expandir** o nó. O número de filhos que um nó pode ter é chamado de **fator de ramificação (b)**.
- **Profundidade (Depth):** A profundidade de um nó é o número de passos (arestas) desde a raiz até ele.

A busca, então, consiste em construir essa árvore, começando pela raiz e expandindo os nós em uma determinada ordem, até que um nó correspondente a um estado objetivo seja encontrado.

---

### Algoritmos de Busca Cega

#### 1. Busca em Largura (Breadth-First Search - BFS)

- **Ideia:** Expande primeiro todos os nós em uma determinada profundidade antes de passar para o próximo nível de profundidade. Começa na raiz, expande todos os seus filhos, depois todos os filhos dos filhos, e assim por diante.
- **Implementação:** Utiliza uma fila do tipo **FIFO (First-In, First-Out)**.
- **Propriedades:**
    - **Completa:** Sim, sempre encontrará uma solução se ela existir.
    - **Ótima:** Sim, encontrará a solução mais "rasa" (com o menor número de passos), desde que o custo de todas as ações seja o mesmo.
    - **Complexidade de Tempo e Espaço:** $O(b^d)$, onde `b` é o fator de ramificação e `d` é a profundidade da solução. A complexidade de espaço é o principal problema, pois precisa armazenar todos os nós da fronteira na memória.

#### 2. Busca de Custo Uniforme (Uniform-Cost Search - UCS)

- **Ideia:** Expande o nó `n` que tem o menor custo de caminho (`g(n)`) desde o estado inicial. É uma generalização da Busca em Largura, usada quando os custos das ações são diferentes.
- **Implementação:** Utiliza uma fila de prioridades, ordenada pelo custo do caminho `g(n)`.
- **Propriedades:**
    - **Completa:** Sim.
    - **Ótima:** Sim, sempre encontra a solução de menor custo.
    - **Complexidade de Tempo e Espaço:** $O(b^{1 + \lfloor C^*/\epsilon \rfloor})$, onde $C^*$ é o custo da solução ótima e $\epsilon$ é o custo mínimo de uma ação. A complexidade ainda é um problema.

#### 3. Busca em Profundidade (Depth-First Search - DFS)

- **Ideia:** Explora um ramo da árvore de busca o mais fundo possível antes de retroceder (backtracking) e explorar outros ramos.
- **Implementação:** Utiliza uma pilha do tipo **LIFO (Last-In, First-Out)**.
- **Propriedades:**
    - **Completa:** Não. Pode ficar presa em ramos infinitos se o espaço de busca for infinito. É completa apenas para espaços finitos sem ciclos.
    - **Ótima:** Não. Encontrará a primeira solução que achar no caminho, que pode não ser a de menor profundidade ou custo.
    - **Complexidade de Tempo:** $O(b^m)$, onde `m` é a profundidade máxima do espaço de busca (pode ser infinito).
    - **Complexidade de Espaço:** $O(bm)$. Esta é a sua grande vantagem. Ela só precisa armazenar um único caminho da raiz até a folha, tornando-a muito mais eficiente em termos de memória que a busca em largura.

#### 4. Busca em Profundidade com Limite (Depth-Limited Search - DLS)

- **Ideia:** É uma variação da Busca em Profundidade para evitar o problema dos caminhos infinitos. Impõe-se um **limite de profundidade** `l`. Nós em profundidade `l` são tratados como se não tivessem sucessores.
- **Propriedades:**
    - **Completa:** Não. Se a solução mais rasa estiver além do limite `l`, ela não será encontrada.
    - **Ótima:** Não.
    - **Complexidade de Tempo:** $O(b^l)$.
    - **Complexidade de Espaço:** $O(bl)$.

#### 5. Busca por Aprofundamento Iterativo (Iterative Deepening Search - IDS)

- **Ideia:** Combina as vantagens da Busca em Largura (completude e otimalidade) com a vantagem de espaço da Busca em Profundidade. Realiza repetidas Buscas em Profundidade com Limite, incrementando o limite a cada iteração (l=0, l=1, l=2, ...).
- **Propriedades:**
    - **Completa:** Sim.
    - **Ótima:** Sim (em termos de profundidade, como a BFS).
    - **Complexidade de Tempo:** $O(b^d)$. Parece desperdiçar trabalho por regenerar os nós superiores, mas o custo disso é baixo comparado ao custo de explorar o último nível.
    - **Complexidade de Espaço:** $O(bd)$.
- **Conclusão:** É a estratégia de busca cega preferida quando o espaço de busca é grande e a profundidade da solução é desconhecida.

---

### Evitando Estados Repetidos

- Um problema significativo em problemas de busca, especialmente em grafos, é a possibilidade de entrar em loops ou gerar o mesmo estado várias vezes por caminhos diferentes, o que é ineficiente.
- A solução é manter um conjunto de **estados já visitados** (ou explorados). Ao gerar um nó filho, verifica-se se o estado correspondente já foi visitado. Se sim, ele é descartado. Isso transforma a árvore de busca em um grafo. Para ser eficaz, todos os estados gerados precisam ser mantidos na memória.