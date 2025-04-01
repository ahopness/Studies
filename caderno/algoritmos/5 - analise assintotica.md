**01/04 - Projeto e Analise de Algoritmos - Analise Assintótica**

- A partir da noção que o tempo de execução de um algoritmo é proporcional ao tamanho da entrada, é necessario o estudo das operações do algoritmo para medir o crescimento do tempo de execução, os resultados desse estudo são funções assintóticas.

---

### Comparações de função

- Dada a função `(3n² + 7n + 8)/2`, é correto afirmar que o elemento de maior peso (isto é, oque mais afeta o resultado da função a partir da entrada) é o exponencial, o `n²`.
- Dado `2n³` & `10n³ + 5`, é correto afirmar que ambas possuem a mesma taxa de cresimento devido a potencia em suas entradas.
- Dado  `n²`, é correto afirmar que o mesmo cresce mais rápido que `100n` para `n` suficientemente grande, mesmo que `100n` seja maior para valores pequenos de `n`.
-  Dados as relações acima, existem **três tipos de comparação assintótica** baseadas nelas:
  - Uma com a ideia de "$\geq$" (Omega - $\Omega$)
  - Outra com a ideia de "$\leq$" (Omicron - O)
  - Uma terceira com a ideia de "=" (Theta - $\Theta$)

---

### Dominação Assintótica

- **Definição:** Uma função `g(n)` domina assintoticamente outra função `f(n)` se existem duas **constantes positivas** `c` e `n₀` tais que, para todo `n ≥ n₀`, temos:
  - `|f(n)| ≤ c . |g(n)|`

*(eu sei, isso não faz sentido nenhum ainda, mas aguenta mais um )*

- **Exemplo:**
  - `g(n) = n` e `f(n) = n²`
  - `|n| ≤ |n²|` para todo `n ∈ N`.
  - Para `c = 1` e `n₀ = 1`, temos `|g(n)| ≤ c . |f(n)|`.
  - Portanto, `f(n)` domina assintoticamente `g(n)`.

---

### Análise Assintótica: Ordens O, Ω e Θ e notação Big O / O(n)

- A análise de algoritmos se concentra no comportamento para valores **enormes** de `n`, em contraste com a intuição comum de pensar em valores pequenos.

---

### Classes de Problemas (Ordens de Complexidade)

- Foram apresentadas diversas ordens de complexidade, com exemplos de onde tipicamente ocorrem:
  - **O(log n): Ordem logarítmica**
    - Típica de algoritmos que resolvem problemas transformando-os em problemas menores (ex: busca binária).
  - **O(n): Ordem linear**
    - Geralmente, uma certa quantidade de operações é realizada sobre cada um dos elementos de entrada (ex: percorrer um array).
  - **O(n log n): Ordem log linear**
    - Típica de algoritmos que trabalham com particionamento dos dados, resolvendo subproblemas independentemente e depois unindo-os (ex: merge sort, quicksort - caso médio).
  - **O(n²): Ordem quadrática**
    - Normalmente ocorre quando os dados são processados aos pares (ex: dois loops aninhados).
  - **O(n³): Ordem cúbica**
    - Caracterizada pela presença de três estruturas de repetição aninhadas.
  - **O(2ⁿ): Ordem exponencial**
    - Geralmente ocorre com soluções de força bruta e não são práticas para grandes entradas.
  - **O(n!): Ordem fatorial**
    - Também comum em soluções de força bruta, com um comportamento ainda pior que o exponencial.
  - **O(1): Ordem constante**
    - O tempo de execução não depende do tamanho da entrada.

e no fim das contas, a ordem de complexidade (do melhor caso pro pior caso) se resume em: `O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(n³) < O(2ⁿ) < O(n!)`
