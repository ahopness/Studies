**24/04 - Projeto e Análise de Algoritmos - Divisão e Conquista**

- Esta aula introduziu o paradigma de **Divisão e Conquista**, uma estratégia poderosa para resolver problemas, especialmente os complexos ou com grandes entradas.

---

### Ideia Geral

- A estratégia consiste em três passos principais:
    1.  **Dividir:** Quebrar a instância original do problema em duas ou mais sub-instâncias menores e independentes do mesmo problema.
    2.  **Conquistar:** Resolver as sub-instâncias menores, geralmente usando recursão.
    3.  **Combinar:** Unir as soluções das sub-instâncias para formar a solução da instância original.
- Algoritmos de Divisão e Conquista são frequentemente recursivos e costumam dividir o problema em `a` subproblemas, cada um com tamanho `n/b`, levando a recorrências no formato `T(n) = aT(n/b) + f(n)`.

---

### Quando Utilizar

- A técnica é indicada quando:
    - É possível decompor o problema eficientemente.
    - A combinação das soluções parciais é eficiente (idealmente O(n) ou O(1)).
    - As sub-instâncias geradas têm tamanhos parecidos.
- É particularmente útil em problemas com operações repetidas (ex: multiplicação) ou onde uma decisão divide o problema em partes disjuntas.

---

### Vantagens e Desvantagens

- **Vantagens:**
    - Permite resolver problemas complexos (ex: Torre de Hanói).
    - Pode gerar algoritmos muito eficientes (frequentemente O(log n) ou O(n log n)).
    - Facilita o paralelismo (na fase de conquista).
    - Pode melhorar a precisão numérica.
- **Desvantagens:**
    - Dependência de recursão (risco de estouro de pilha) ou necessidade de pilha explícita.
    - Pode repetir o cálculo de subproblemas (memoização pode ajudar).
    - Escolha do caso base pode ser não trivial.

---

### Exemplos de Aplicação

- **Exponenciação (`a^n`):** A abordagem D&C (`a^n = a^(n/2) * a^(n/2)`) reduz a complexidade de O(n) (método iterativo simples) para **O(log n)**.
- **Multiplicação de Inteiros Grandes:** O algoritmo D&C (Karatsuba) usa 3 multiplicações de tamanho n/2 e combina em O(n), resultando em **O(n^log₂3) ≈ O(n^1.58)**, melhor que o O(n²) tradicional.
- **Multiplicação de Matrizes (Strassen):** Usa 7 multiplicações de tamanho (n/2)x(n/2) e combina em O(n²), resultando em **O(n^log₂7) ≈ O(n^2.81)**, melhor que o O(n³) tradicional.
- **Pesquisa Binária:** Busca em array ordenado dividindo ao meio. `T(n) = T(n/2) + O(1)`, resultando em **O(log n)**.
- **Par de Pontos Mais Próximos:** Acha a menor distância entre pontos em um plano 2D. A solução D&C envolve dividir os pontos, resolver recursivamente e combinar verificando uma "faixa" central. `T(n) = 2T(n/2) + O(n)`, resultando em **O(n log n)**, melhor que O(n²) da força bruta.

---

### Técnicas Relacionadas (Breve Introdução)

- **Transformar e Conquistar:** Resolve o problema transformando-o primeiro.
    - *Simplificação da Instância:* Ex: pré-ordenar os dados (custo depende da ordenação, O(n log n)).
    - *Mudança de Representação:* Usar estruturas de dados diferentes.
    - *Redução do Problema:* Transformar em outro problema conhecido.
- **Diminuir e Conquistar:** Resolve explorando a relação entre a solução da instância `n` e uma instância menor (`n-k` ou `n/k`).
    - *Diminuir por Constante:* Ex: Ordenação por Inserção, Busca em Grafos (DFS, BFS).
    - *Diminuir por Fator Constante:* Ex: Pesquisa Binária.
    - *Diminuir por Tamanho Variável.*

---

**Conclusão:**

Divisão e Conquista é um paradigma fundamental no design de algoritmos eficientes, transformando problemas grandes em subproblemas menores, resolvendo-os recursivamente e combinando os resultados. É a base para muitos algoritmos rápidos em computação.