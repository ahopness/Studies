**29/05 - Projeto e Análise de Algoritmos - Busca Heurística**

- Estratégias de busca podem ser divididas em duas categorias principais:
    - **Busca sem informação (não informada):** Encontra soluções gerando sistematicamente novos estados e comparando-os com o objetivo. São estratégias muito ineficientes na maioria dos casos.
    - **Busca com informação (informada ou heurística):** Utiliza conhecimento específico do problema para encontrar soluções de maneira mais eficiente, tentando expandir primeiro os caminhos que parecem mais promissores.

---

### Busca com Informação e a Função Heurística

- **Ideia Principal:** A busca com informação, ou busca heurística, utiliza uma **função heurística**, denotada por **h(n)**, para guiar a exploração.
- **Função Heurística h(n):** É uma função que estima o custo do caminho de menor custo de um nó `n` até o nó objetivo.
    - Se `n` é o nó objetivo, então `h(n) = 0`.
    - **Exemplo:** Em um problema de encontrar o caminho mais curto em um mapa, uma boa heurística `h(n)` seria a distância em linha reta entre o nó atual `n` e a cidade objetivo.
- **Abordagem Geral (Melhor-Escolha-Primeiro):** É uma estratégia que expande os nós com base em uma **função de avaliação f(n)**, que mede a "distância" até o objetivo, considerando a heurística.
    - O nó com a avaliação mais baixa é selecionado para expansão.
    - A implementação geralmente utiliza uma fila de prioridades para manter os nós a serem expandidos, ordenados por `f(n)`.

---

### Algoritmos de Busca Heurística

#### 1. Busca Gulosa (Greedy Best-First Search)

- **Ideia:** Tenta expandir o nó que está mais perto do objetivo, na esperança de que isso leve a uma solução rapidamente.
- **Função de Avaliação:** `f(n) = h(n)`. Ela ignora o custo do caminho percorrido até o momento e foca apenas na estimativa de custo para chegar ao objetivo.
- **Características:**
    - **Não é Ótima:** Pode encontrar uma solução que não é a de menor custo, pois pode ser atraída por um caminho que parece curto, mas que na verdade é uma "cilada" que leva a um caminho geral mais longo.
    - **Não é Completa:** Pode ficar presa em loops se não houver um controle de estados já visitados. Se houver controle, ela se torna completa em espaços de estados finitos.
    - **Complexidade de Tempo e Espaço (pior caso):** $O(b^m)$, onde `b` é o fator de ramificação e `m` é a profundidade máxima do espaço de busca.

#### 2. Busca A*

- **Ideia:** É o algoritmo de busca com informação mais conhecido. Combina o custo do caminho percorrido desde o início (`g(n)`) com o custo estimado do nó atual até o objetivo (`h(n)`).
- **Função de Avaliação:** `f(n) = g(n) + h(n)`.
    - **g(n):** Custo do caminho desde o nó inicial até o nó `n`.
    - **h(n):** Custo estimado do caminho mais barato de `n` até o objetivo (a heurística).
    - `f(n)` representa o custo estimado da solução mais barata que passa pelo nó `n`.
- **Propriedades da Heurística para o A*:**
    - **Admissível:** Uma heurística `h(n)` é admissível se ela **nunca superestima** o custo real para alcançar o objetivo. Ou seja, `h(n)` é sempre menor ou igual ao custo real.
        - **Exemplo:** A distância em linha reta é uma heurística admissível, pois o caminho real nunca pode ser mais curto que a linha reta.
        - **Consequência:** Se a heurística `h(n)` é admissível, o algoritmo A* é **ótimo** (encontrará a solução de menor custo).
    - **Consistente (ou Monotônica):** Uma heurística é consistente se, para cada nó `n` e cada sucessor `n'` de `n`, o custo estimado de `n` (`h(n)`) não é maior que o custo de ir de `n` para `n'` (`c(n, a, n')`) somado ao custo estimado de `n'` (`h(n')`). Formalmente: `h(n) ≤ c(n, a, n') + h(n')`.
        - **Consequência:** Se a heurística é consistente, a primeira vez que o A* expande um nó, ele já encontrou o caminho ótimo para esse nó. Isso torna o algoritmo mais eficiente.
- **Características do A*:**
    - **Completo:** Encontrará uma solução se ela existir.
    - **Ótimo:** Encontrará a solução de menor custo se a heurística `h(n)` for admissível.
    - **Eficiência:** Sua eficiência depende muito da qualidade da função heurística.
    - **Complexidade:** O número de nós expandidos ainda é exponencial no pior caso, mas na prática o A* é muito mais eficiente que as buscas não informadas.

---

### Qualidade e Escolha da Função Heurística

- **Eficácia da Heurística:** A eficácia do A* depende do quão próxima a heurística `h(n)` está do custo real `h*(n)`.
- **Dominância:** Se temos duas heurísticas admissíveis, `h1` e `h2`, e para todo nó `n`, `h2(n) ≥ h1(n)`, dizemos que `h2` **domina** `h1`.
    - É sempre melhor usar uma função heurística com valores mais altos, desde que ela continue sendo admissível, pois ela podará mais nós da árvore de busca. 
- **Custo de Execução:** Uma boa função heurística também deve ser eficiente para calcular. Se o custo de calcular a heurística for muito alto, pode não valer a pena usá-la.
- **Heurística Composta:** Se existem várias heurísticas admissíveis (`h1`, `h2`, ...) e nenhuma delas domina as outras, pode-se usar uma heurística composta: `h(n) = max(h1(n), h2(n), ...)`. Esta nova heurística `h` também será admissível e dominará cada uma das heurísticas individuais.

---

**Conclusão:**

A busca heurística, em particular o algoritmo A*, oferece uma maneira poderosa de resolver problemas de busca de forma muito mais eficiente do que os métodos de força bruta. O segredo de seu sucesso reside na formulação de uma boa função heurística — uma que seja admissível (para garantir a otimalidade) e que estime o custo real com a maior precisão possível (para garantir a eficiência).