**08/05 & 13/05 - Projeto e Análise de Algoritmos - Intratabilidade de Problemas**

- A intratabilidade de problemas em ciência da computação refere-se àqueles problemas para os quais não se conhece uma solução eficiente, ou seja, que possa ser resolvida em tempo polinomial. A teoria da complexidade busca classificar esses problemas, ajudando a entender seus limites e dificuldades computacionais.
- Algoritmos eficientes são geralmente aqueles com tempo de execução polinomial, ou seja, $O(n^k)$ para alguma constante k. Problemas que só podem ser resolvidos por algoritmos com tempo de execução exponencial, como $O(2^n)$, são considerados intratáveis para entradas grandes, pois o tempo de execução cresce rapidamente.

---

### Problemas Tratáveis e Intratáveis

- **Problemas Tratáveis:** São aqueles para os quais existe um algoritmo com complexidade de tempo polinomial que os resolve.
- **Problemas Intratáveis:** São aqueles para os quais os melhores algoritmos conhecidos possuem complexidade de tempo exponencial. Embora uma solução possa existir, o tempo para encontrá-la torna-se proibitivo à medida que o tamanho da entrada aumenta.
- Existem também problemas cuja resposta é tão longa que demanda um tempo exponencial apenas para descrevê-la, mas estes são frequentemente considerados como não bem postos.
- O foco principal no estudo da intratabilidade recai sobre problemas com limite superior de complexidade exponencial e limite inferior polinomial, ou seja, não se sabe se são tratáveis ou intratáveis.

---

### Classes de Complexidade

#### Classe P

- **Definição:** A classe P (Polinomial) agrupa todos os problemas de decisão que podem ser resolvidos por um algoritmo determinístico em tempo polinomial.
- **Características:** São considerados problemas "fáceis" ou tratáveis computacionalmente.
- **Exemplos:**
    - Verificar se um grafo é conexo.
    - Encontrar o caminho mínimo entre dois pontos em um grafo com pesos não negativos (usando o algoritmo de Dijkstra).
    - Multiplicação de matrizes.
    - Ordenação de um conjunto de números.

#### Classe NP

- **Definição:** A classe NP (Não-determinístico Polinomial) agrupa todos os problemas de decisão para os quais uma solução candidata (chamada de "certificado") pode ser verificada em tempo polinomial por um algoritmo determinístico. Alternativamente, são problemas que podem ser resolvidos por um algoritmo não-determinístico em tempo polinomial.
- **Características:**
    - "NP" não significa "não-polinomial", mas sim "resolvível em tempo polinomial por uma máquina de Turing não-determinística".
    - Se uma instância do problema tem resposta "sim", existe um certificado que o comprova, e esse certificado é de tamanho polinomial e verificável em tempo polinomial.
    - A classe P está contida na classe NP ($P \subseteq NP$). [cite: 221, 422] Se um problema pode ser resolvido em tempo polinomial, sua solução pode ser verificada em tempo polinomial (ignorando o certificado e simplesmente resolvendo).
- **A grande questão $P = NP$?:** Uma das maiores questões em aberto na ciência da computação é se P é igual a NP. Se for provado que $P = NP$, significaria que todos os problemas em NP poderiam ser resolvidos eficientemente em tempo polinomial. A maioria dos cientistas acredita que $P \neq NP$.

#### Problemas de Decisão

- Para o estudo teórico da complexidade, frequentemente se convertem problemas de busca ou otimização em problemas de decisão (cuja resposta é "sim" ou "não"), pois isso simplifica a análise sem alterar fundamentalmente a complexidade computacional do problema.
    - **Exemplo (Caixeiro Viajante):**
        - **Problema de Otimização:** Encontrar a rota de menor custo que visita cada cidade exatamente uma vez e retorna à origem.
        - **Problema de Decisão:** Dado um grafo com custos nas arestas e um valor K, existe um ciclo Hamiltoniano (um ciclo que visita cada vértice exatamente uma vez) com custo total menor ou igual a K?

#### Algoritmos Não-Determinísticos

- Um algoritmo não-determinístico pode ser visualizado como um algoritmo que, em certos pontos, faz uma "escolha" correta que o levará a uma solução, se uma existir.
- Outra forma de entender é que ele possui a capacidade de explorar múltiplos caminhos de computação simultaneamente.
- A complexidade de um algoritmo não-determinístico é o tempo do caminho de computação mais curto que leva a uma resposta "sim".
- Máquinas de Turing Não-Determinísticas (MTND) são um modelo formal para esses algoritmos. Um problema está em NP se existe uma MTND que o resolve em tempo polinomial.

---

### Reduções Polinomiais

- **Conceito:** Uma redução polinomial é uma forma de transformar uma instância de um problema $P_1$ em uma instância de outro problema $P_2$ em tempo polinomial, de tal forma que a solução para a instância de $P_2$ nos dá a solução para a instância original de $P_1$. Se $P_1$ é redutível polinomialmente a $P_2$ (denotado $P_1 \le_p P_2$), então $P_1$ não é "mais difícil" que $P_2$.
- **Importância:**
    - Se $P_1 \le_p P_2$ e existe um algoritmo polinomial para $P_2$, então existe um algoritmo polinomial para $P_1$.
    - Se $P_1 \le_p P_2$ e $P_1$ é sabidamente difícil (não tem algoritmo polinomial conhecido), então $P_2$ também é considerado difícil.
- As reduções são fundamentais para definir as classes NP-Completo e NP-Difícil.

---

### Classe NP-Completo (NPC)

- **Definição:** Um problema de decisão $L$ é NP-Completo se:
    1.  $L \in NP$ (pode ser verificado em tempo polinomial). 
    2.  Todo problema $L' \in NP$ é redutível polinomialmente a $L$ ($L' \le_p L$). Isso significa que $L$ é pelo menos tão difícil quanto qualquer outro problema em NP. 
- **Características:**
    - São os problemas "mais difíceis" da classe NP.
    - Se um único problema NP-Completo puder ser resolvido em tempo polinomial, então todos os problemas em NP poderão ser resolvidos em tempo polinomial, o que implicaria $P=NP$.
    - O primeiro problema provado ser NP-Completo foi o Problema da Satisfatibilidade Booleana (SAT) por Stephen Cook em 1971.
    - Depois de Cook, Richard Karp mostrou que muitos outros problemas eram NP-Completos, reduzindo SAT a eles.
- **Exemplos de problemas NP-Completos:**
    - Problema da Satisfatibilidade Booleana (SAT).
    - 3-SAT (Satisfatibilidade com 3 literais por cláusula).
    - Problema do Ciclo Hamiltoniano.
    - Problema do Caixeiro Viajante (versão de decisão).
    - Problema da Cobertura de Vértices.
    - Problema da Clique (encontrar um subgrafo completo de tamanho k).
    - Problema da Soma de Subconjuntos (Subset-Sum).
    - Coloração de Grafos (decidir se um grafo pode ser colorido com k cores).

---

### Classe NP-Difícil (NP-Hard)

- **Definição:** Um problema $L$ é NP-Difícil se todo problema $L' \in NP$ é redutível polinomialmente a $L$ ($L' \le_p L$).
- **Características:**
    - A diferença chave em relação a NP-Completo é que um problema NP-Difícil não precisa necessariamente pertencer à classe NP. Ou seja, ele pode não ser um problema de decisão, ou sua solução pode não ser verificável em tempo polinomial.
    - Problemas NP-Completos são problemas NP-Difíceis que também estão em NP.
    - Se um problema NP-Difícil puder ser resolvido em tempo polinomial, então $P=NP$.
- **Exemplos:**
    - O Problema do Caixeiro Viajante (versão de otimização, que busca a rota de menor custo, não apenas se existe uma rota abaixo de um custo K).
    - Muitos problemas práticos de otimização e planejamento são NP-Difíceis.

---

### Lidando com Problemas NP-Difíceis/NP-Completos

- Dado que se acredita que $P \neq NP$, não se espera encontrar algoritmos de tempo polinomial para resolver problemas NP-Completos ou NP-Difíceis de forma exata e para todas as instâncias.
- Estratégias comuns incluem:
    - **Algoritmos de Aproximação:** Buscam soluções que são "boas o suficiente" ou próximas da ótima, com garantia de quão perto da ótima a solução estará, em tempo polinomial.
    - **Heurísticas:** Algoritmos que encontram soluções boas na prática para muitas instâncias, mas sem garantia de otimalidade ou de tempo de execução polinomial no pior caso.
    - **Algoritmos Exatos para Instâncias Pequenas:** Técnicas como backtracking ou branch-and-bound podem encontrar soluções ótimas, mas seu tempo de execução é exponencial no pior caso, tornando-as viáveis apenas para instâncias de tamanho limitado.
    - **Casos Especiais:** Identificar subconjuntos de instâncias do problema que podem ser resolvidos em tempo polinomial.

---

**Conclusão:**

A teoria da NP-Completude fornece uma estrutura robusta para entender a intratabilidade de muitos problemas computacionais importantes. Reconhecer que um problema é NP-Completo ou NP-Difícil sugere que a busca por um algoritmo exato e eficiente em tempo polinomial provavelmente será infrutífera, direcionando os esforços para abordagens alternativas. A questão de se $P=NP$ permanece como um dos desafios centrais da ciência da computação.
