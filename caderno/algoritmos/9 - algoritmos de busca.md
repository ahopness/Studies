**29/04 - Projeto e Análise de Algoritmos - Algoritmos de Busca**

- A busca é uma tarefa fundamental em computação, consistindo em localizar um elemento específico dentro de um conjunto de dados, geralmente usando uma chave identificadora.
- A forma como os dados são organizados (estrutura de dados, ordenação) impacta significativamente a eficiência dos algoritmos de busca.

---

### Termos Importantes

- **Tabela:** Estrutura genérica para armazenar dados (vetor, lista, árvore, etc.), contendo registros.
- **Chave:** Identificador único (primária) ou não único (secundária) associado a um registro.
- **Busca Interna vs. Externa:** Tabela totalmente na memória principal vs. em armazenamento secundário.
- **Operações Comuns:** Inserção, Remoção, Recuperação (busca).

---

### Busca Sequencial

- **Método:** Percorre a tabela (vetor, lista) elemento por elemento, comparando a chave de cada um com a chave buscada, até encontrar ou chegar ao fim.
- **Complexidade:**
    - **Pior Caso / Caso Médio:** $\Theta(n)$ (elemento é o último ou não existe / média de comparações).
    - **Melhor Caso:** $\Theta(1)$ (elemento é o primeiro).
- **Tabela Ordenada:** Melhora um pouco a busca *sem sucesso* (pode parar antes), mas a complexidade assintótica do pior caso continua $\Theta(n)$.

---

### Busca Binária

- **Requisito:** A tabela (geralmente um vetor) **precisa estar ordenada**.
- **Método (Divisão e Conquista):**
    1. Compara a chave buscada com o elemento do meio.
    2. Se for igual, encontrou.
    3. Se for menor, repete a busca na primeira metade.
    4. Se for maior, repete a busca na segunda metade.
    5. Continua até encontrar ou o intervalo de busca se tornar vazio.
- **Complexidade:**
    - **Pior Caso / Caso Médio:** $\Theta(\log n)$ (o tamanho do problema é dividido por 2 a cada passo).
    - **Melhor Caso:** $\Theta(1)$ (elemento está exatamente no meio na primeira tentativa).

---

### Busca em Árvores (Árvores Binárias de Busca - BST)

- **Método:** Compara a chave com a raiz; se menor, vai para a subárvore esquerda; se maior, vai para a subárvore direita; repete recursivamente.
- **Complexidade:** Depende do balanceamento da árvore.
    - **Melhor Caso / Caso Médio (Árvore Balanceada):** $\Theta(\log n)$ (altura da árvore é logarítmica).
    - **Pior Caso (Árvore Degenerada/Desbalanceada):** $\Theta(n)$ (a árvore se comporta como uma lista encadeada).

---

### Busca por Interpolação

- **Requisitos:** Tabela ordenada e chaves com **distribuição uniforme**.
- **Método:** Similar à busca binária, mas em vez de dividir sempre ao meio, "adivinha" a posição provável da chave baseado em seu valor relativo aos valores mínimo e máximo do intervalo atual.
- **Complexidade:**
    - **Caso Médio (Distribuição Uniforme):** $\Theta(\log(\log n))$ (extremamente rápido).
    - **Pior Caso (Distribuição Não Uniforme):** $\Theta(n)$.
- **Desvantagem:** Sensível à distribuição não uniforme das chaves, que é comum na prática.

---

### Hashing

- **Objetivo:** Realizar busca, inserção e remoção em tempo médio constante $\Theta(1)$.
- **Método:** Uma **função hash** mapeia a chave diretamente para um índice em uma tabela hash (geralmente um vetor).
- **Colisões:** Ocorrem quando chaves diferentes mapeiam para o mesmo índice. Precisam ser tratadas (ex: encadeamento separado - listas em cada posição da tabela).
- **Fator de Carga ($\alpha = n/m$):** Relação entre o número de chaves (`n`) e o tamanho da tabela (`m`). Afeta o desempenho.
- **Complexidade:**
    - **Pior Caso:** $\Theta(n)$ (todas as chaves colidem no mesmo índice).
    - **Caso Médio (Hashing Uniforme, $\alpha=O(1)$):** $\Theta(1)$.

---

### Busca Indexada

- **Método:** Utiliza uma estrutura de índice auxiliar (menor que a tabela principal) que mapeia chaves (ou intervalos) para blocos de dados na tabela principal. A busca é feita primeiro no índice para localizar o bloco relevante, e depois dentro desse bloco.
- **Vantagem:** Reduz drasticamente o espaço de busca, útil para grandes volumes de dados ou armazenamento secundário. A complexidade final depende da busca no índice e da busca no bloco.

---

**Conclusão:**

Existem diversas técnicas de busca, cada uma com suas características, requisitos e complexidades. A escolha ideal depende da estrutura dos dados (ordenados ou não), do tamanho do conjunto, da frequência das operações (busca, inserção, remoção) e da distribuição das chaves. A busca sequencial é simples mas lenta ($\Theta(n)$), a binária é rápida ($\Theta(\log n)$) mas exige ordenação, e o hashing oferece o melhor desempenho médio ($\Theta(1)$) mas com um pior caso linear e a complexidade das colisões.