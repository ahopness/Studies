**15/05 & 22/05 - Projeto e Análise de Algoritmos - Projeto de Algoritmos, Força Bruta, Tentativa e Erro (Backtracking, Branch-and-Bound) e Satisfação de Restrições**

- O projeto de algoritmos envolve a criação de técnicas genéricas para implementar soluções, cuja escolha está ligada à natureza do problema a ser resolvido. Isso é diferente dos padrões de projeto de software, que se relacionam mais com a linguagem de programação utilizada. Ambos descrevem técnicas genéricas, mas em contextos diferentes.
- Algumas das principais técnicas de projeto de algoritmos incluem Força Bruta, Programação Dinâmica, Algoritmos Gulosos, Balanceamento e Algoritmos Aproximados.

---

### Força Bruta

- **Ideia Principal:** É a abordagem mais direta para resolver um problema, geralmente baseada nas definições e regras dos conceitos envolvidos. Depende mais do poder computacional (força) do que da inteligência na modelagem do algoritmo.
- **Características:**
    - Simples de implementar.
    - Frequentemente ineficiente para problemas grandes, pois pode levar a um crescimento exponencial do esforço computacional.
    - Para alguns problemas, pode ser a única forma conhecida de encontrar uma solução ótima, embora heurísticas possam ser usadas para encontrar soluções boas, mas não necessariamente ótimas.
- **Exemplos:**
    - **Ordenação:** Selection Sort, Bubble Sort.
    - **Busca:** Busca sequencial.
    - **Outros:** Casamento de strings, Multiplicação de matrizes.
    - **Problema do Ciclo Hamiltoniano:** Encontrar o circuito de custo mínimo que passa por cada cidade exatamente uma vez e retorna à origem. A força bruta testaria todas as permutações possíveis de cidades. Por exemplo, para 5 cidades, um caminho como [1, 2, 3, 5, 4, 1] com custo 15 pode ser encontrado testando diferentes sequências.
    - **Problema da Clique:** Dado um conjunto de `n` pessoas, verificar se existe um subconjunto de `r` pessoas onde todos se conhecem mutuamente. Uma solução por força bruta verificaria todas as combinações de `r` pessoas. Por exemplo, para encontrar um clique de 5 pessoas em um grupo de 8, onde as relações de conhecimento são dadas por uma matriz, a força bruta testaria todas as 56 combinações possíveis. Se, por exemplo, as pessoas {1, 3, 4, 6, 7} todas se conhecem entre si, isso seria uma clique encontrada.

---

### Técnicas de Tentativa e Erro

- Para problemas difíceis onde não se conhece uma solução algorítmica eficiente, as técnicas de tentativa e erro buscam diminuir o espaço de busca da solução. Mesmo assim, no pior caso, ainda podem enfrentar a explosão exponencial da busca exaustiva.
- Duas técnicas principais são o **Backtracking** e o **Branch-and-Bound**. Ambas constroem uma árvore de estados, onde cada nó representa uma escolha em direção à solução. A ideia é explorar essa árvore de forma inteligente.

#### Backtracking

- **Ideia Principal:** É um refinamento da busca por força bruta. Elimina grande parte das soluções sem examiná-las explicitamente. Aplica-se a problemas onde a solução é uma sequência de decisões e pode ser modelada por uma árvore de estados.
- **Funcionamento:**
    - Explora a árvore de estados (espaço de busca).
    - Se um caminho (ramo da árvore) não leva a uma solução válida ou desejada (por exemplo, se uma restrição é violada), o algoritmo "recua" (backtrack) para o nó anterior e tenta uma decisão diferente, podando o ramo inviável.
    - A ordem de visita dos nós é tipicamente em profundidade.
- **Exemplo: Números binários de 3 bits com soma de 1's ≥ 2:**
    - O espaço de busca são todas as combinações de 3 bits (000 a 111).
    - Ao construir a árvore:
        - Começa com "" (vazio).
        - Ramifica para "0" e "1".
        - De "0", ramifica para "00" e "01".
        - De "00", ramifica para "000" (soma 0, não serve) e "001" (soma 1, não serve).
        - Se já temos "00", e precisamos de soma ≥ 2, mas só falta 1 bit, já sabemos que este ramo não dará certo se o máximo de 1s que podemos adicionar não atinge o limite.
        - Se chegamos a "11" (soma 2), a próxima ramificação "110" (soma 2, serve) e "111" (soma 3, serve) são soluções.
- **Exemplo: Problema da Mochila ( versão de decisão ou para encontrar todas as soluções):**
    - **Objetivo:** Preencher uma mochila com itens (cada um com peso e valor) para maximizar o valor total sem ultrapassar a capacidade de peso da mochila.
    - **Força Bruta:** Gerar todas as $2^n$ combinações de itens.
    - **Backtracking:** Ao adicionar itens, se a capacidade da mochila é excedida, esse ramo da árvore de decisão é podado (não se continua a adicionar mais itens por esse caminho). Por exemplo, com uma mochila de capacidade 10kg e itens A(4kg, $40), B(3kg, $50), C(5kg, $60), D(3kg, $20):
        - Se escolhemos A (4kg) e B (3kg), temos 7kg. Se o próximo item C (5kg) excede os 10kg (7+5=12kg), fazemos backtrack e não consideramos C nesse ramo.
- **Exemplo: Problema das N Rainhas:**
    - **Objetivo:** Posicionar N rainhas em um tabuleiro NxN de forma que nenhuma rainha ameace outra (mesma linha, coluna ou diagonal).
    - **Backtracking:** Tenta-se colocar uma rainha em cada coluna, uma por vez. Se ao tentar colocar a k-ésima rainha, percebe-se que qualquer posição na coluna k é atacada pelas rainhas já colocadas, o algoritmo retrocede para a (k-1)-ésima rainha e tenta uma posição diferente para ela. Uma solução é uma lista onde a posição `i` indica a coluna e o valor `lista[i]` indica a linha da rainha `i`. A construção da árvore de estados para N=4 ilustra esse processo de tentativa, conflito e retrocesso.
- **Algoritmo Genérico (Pseudocódigo):**
    ```
    BACKTRACK(X[1..k])
        se X[1..k] é uma solução, ESCREVA X[1..k]
        senão
            para cada elemento e que pode ser o próximo em X
                X[k+1] = e
                BACKTRACK(X[1..k+1])
    ```
- **Vantagens:**
    - Fácil de implementar para problemas complexos.
    - Suportado por algumas linguagens de programação lógica (ex: Prolog).
- **Desvantagens:**
    - Pode levar à explosão combinatória se não houver boas restrições para podar a árvore (busca exaustiva). São inerentemente combinatórios.
    - Requer muita memória na pilha de recursão, podendo crescer exponencialmente com o tamanho do problema.
    - Eficiente para problemas de decisão, mas não projetado diretamente para otimização (para ao encontrar a primeira solução). Para otimização, ele pode ser estendido, levando ao Branch-and-Bound.

---

### Branch-and-Bound (Ramificação e Poda)

- **Ideia Principal:** É uma evolução do backtracking, focada em problemas de otimização (encontrar a melhor solução, não apenas uma solução).
- **Funcionamento:**
    - Como o backtracking, explora uma árvore de estados.
    - Mantém um registro da **melhor solução encontrada até o momento** e seu valor (custo ou benefício).
    - **Ramificação (Branch):** Expande o nó mais promissor (aquele que tem maior potencial de levar a uma solução melhor que a atual "melhor solução").
    - **Poda (Bound/Limitar):** Utiliza uma função de limite (bound) para estimar o melhor resultado possível a partir de um nó parcial.
        - Se o limite de um nó indica que ele não pode levar a uma solução melhor que a "melhor solução até agora", esse nó (e toda a subárvore abaixo dele) é podado. Por exemplo, se buscamos um caminho de custo mínimo e o custo parcial de um nó já excede o custo mínimo conhecido, ele é descartado.
- **Diferença Chave do Backtracking (para otimização):**
    - Backtracking (em sua forma pura) para ao encontrar a primeira solução viável.
    - Branch-and-Bound continua a busca, atualizando a "melhor solução até agora" e usando-a para podar ramos que não podem superá-la.
- **Exemplo: Problema da Associação de Tarefas (Assignment Problem):**
    - **Objetivo:** Atribuir `n` pessoas a `n` tarefas, onde cada par (pessoa, tarefa) tem um custo. Queremos minimizar o custo total da atribuição.
    - **Tabela de Custos (exemplo):**
        |         | Tarefa1 | Tarefa2 | Tarefa3 | Tarefa4 |
        | :------ | :------ | :------ | :------ | :------ |
        | Pessoa1 | 5       | 5       | 6       | 9       |
        | Pessoa2 | 3       | 1       | 4       | 4       |
        | Pessoa3 | 3       | 5       | 13      | 3       |
        | Pessoa4 | 3       | 9       | 14      | 10      |
    - **Aplicação do Branch-and-Bound:**
        - **Nó Raiz:** Nenhuma atribuição, custo 0. Melhor solução conhecida inicialmente: custo +infinito.
        - **Ramificação:** Atribuir a Pessoa1 uma tarefa.
            - Se Pessoa1 -> Tarefa1: nó [1,0,0,0] (Pessoa1 na Tarefa1, outras livres), custo parcial = 5.
        - **Exploração:** Do nó [1,0,0,0], atribuir Pessoa2.
            - Se Pessoa2 -> Tarefa2: nó [1,1,0,0] (P1->T1, P2->T2), custo parcial = 5 (de P1->T1) + 1 (de P2->T2) = 6. (A aula parece ter um erro de cálculo aqui, ou a notação é diferente. No slide 7 o custo para [1,1,0,0] é 10, sugerindo P1->T1 (5) + P1->T2 (5), mas isso não faz sentido para atribuição. Slide 8 mostra [1,2,0,0] com custo 6, que seria P1->T1(5) + P2->T2(1), o que é correto). Vamos seguir a lógica de atribuição única.
            - Assumindo a lógica correta de atribuição: Nó [1,2,0,0] (Pessoa1->Tarefa1, Pessoa2->Tarefa2), custo = 5+1 = 6.
        - **Poda:** Se em algum momento o custo parcial de um nó (mais uma estimativa otimista do custo restante) exceder o custo da melhor solução completa já encontrada, esse nó é podado.
        - O processo continua, explorando nós promissores e atualizando a melhor solução encontrada, até que todos os nós ativos tenham sido explorados ou podados.

---

### Problemas de Satisfação de Restrições (CSPs - Constraint Satisfaction Problems)

- **Ideia Principal:** CSPs são problemas definidos por:
    - Um conjunto de **variáveis** ($X_i$).
    - Para cada variável, um **domínio** ($D_i$) de possíveis valores.
    - Um conjunto de **restrições** que especificam combinações permitidas de valores para subconjuntos de variáveis.
- **Objetivo:** Encontrar uma atribuição de valores para todas as variáveis de forma que todas as restrições sejam satisfeitas.
- **Componentes:**
    - **Variáveis:** Itens aos quais os valores devem ser atribuídos.
    - **Domínios:**
        - **Discretos Finitos:** Ex: cores {vermelho, verde, azul} para coloração de mapas. O número de atribuições completas é $O(d^n)$. CSPs Booleanos (SAT) são um exemplo.
        - **Discretos Infinitos:** Ex: inteiros para escalonamento de tarefas, necessitando uma linguagem de restrições (ex: InícioTarefa1 + 5 ≤ InícioTarefa3).
        - **Contínuos:** Ex: datas para observações do Hubble; restrições lineares podem ser resolvidas com programação linear.
    - **Restrições:**
        - **Unárias:** Envolvem uma única variável (ex: SA ≠ verde).
        - **Binárias:** Envolvem pares de variáveis (ex: SA ≠ WA). Podem ser representadas por um grafo de restrições.
        - **De Ordem Superior:** Envolvem 3 ou mais variáveis (ex: restrições em cripto-aritmética).
- **Exemplos:**
    - **Coloração de Mapa:** Atribuir cores a regiões de um mapa de forma que regiões adjacentes não tenham a mesma cor.
        - Variáveis: Regiões (WA, NT, Q, etc.).
        - Domínios: Cores {vermelho, verde, azul}.
        - Restrições: WA ≠ NT, etc.. Uma solução seria WA=vermelho, NT=verde, Q=vermelho, NSW=verde, V=vermelho, SA=azul, T=verde.
    - **Cripto-aritmética:** Atribuir dígitos (0-9) a letras em uma equação de forma que a aritmética seja válida (ex: TWO + TWO = FOUR).
        - Variáveis: F, T, U, W, R, O e variáveis de transporte (X1, X2, X3).
        - Domínios: {0,1,...,9}.
        - Restrições: Todas as letras diferentes (Alldiff), as somas das colunas, T ≠ 0, F ≠ 0.
    - **Outros:** Problemas de atribuição (quem ensina qual disciplina), problemas de horários (quando e onde as aulas ocorrem), escalonamento de transportes e fabricação.

---

### Técnicas de Resolução para CSPs

#### 1. Procura Básica com Retrocesso (Backtracking Search)

- **Formulação:**
    - **Estado Inicial:** Nenhuma variável atribuída (atribuição vazia).
    - **Função Sucessores:** Atribui um valor a uma variável ainda não atribuída, desde que não viole nenhuma restrição com as variáveis já atribuídas.
    - **Teste Objetivo:** Todas as variáveis estão atribuídas e todas as restrições são satisfeitas.
- **Funcionamento:**
    - É uma procura em profundidade. Atribui-se um valor a uma variável por vez.
    - Se uma atribuição parcial leva a um conflito (nenhum valor legal pode ser atribuído à próxima variável), o algoritmo "retrocede" (backtracks) para a variável anterior e tenta um valor diferente.
    - Como a ordem de atribuição de variáveis é comutativa (ex: [WA=vermelho, NT=verde] é o mesmo que [NT=verde, WA=vermelho]), considera-se a atribuição a uma única variável em cada nó, resultando em $d^n$ folhas na árvore de busca.
    - É o algoritmo básico não informado para CSPs.
    - **Exemplo (Coloração de Mapa):**
        1. {} (inicial)
        2. {WA=vermelho}
        3. {WA=vermelho, NT=verde}
        4. {WA=vermelho, NT=verde, Q=vermelho} (Q é adjacente a NT, mas pode ser vermelho se NT=verde)
        ... e assim por diante. Se uma atribuição falhar (ex: SA não puder ser colorido), retrocede.

#### 2. Melhorias ao Retrocesso

O objetivo é detectar falhas mais cedo ou tomar decisões mais inteligentes.

- **Ordenação de Variáveis:**
    - **Heurística do Maior Grau (Degree Heuristic):** Escolhe a variável envolvida no maior número de restrições com variáveis ainda não atribuídas. Ex: No mapa da Austrália, SA (South Australia) é uma boa primeira escolha por ser adjacente a muitas outras regiões.
    - **Heurística dos Valores Remanescentes Mínimos (MRV):** Escolhe a variável com o menor número de valores legais restantes em seu domínio. É uma heurística "fail-first" – tenta encontrar um conflito rapidamente.
- **Ordenação de Valores:**
    - **Heurística do Valor Menos Restritivo (LCV):** Dada uma variável, escolhe o valor que elimina o menor número de valores nos domínios das variáveis vizinhas (conectadas por restrições). Tenta manter a máxima flexibilidade para atribuições futuras.
- **Detecção Antecipada de Falhas:**
    - **Forward Checking (Verificação Adiante):** Ao atribuir um valor a uma variável X, remove valores inconsistentes dos domínios das variáveis Y não atribuídas que compartilham uma restrição com X. Se algum domínio se tornar vazio, a atribuição atual a X é rejeitada, e o algoritmo retrocede.
        - **Exemplo (Coloração):** 
            - Se WA=vermelho, e NT é adjacente a WA, remove-se vermelho do domínio de NT. Se Q é adjacente a WA, remove-se vermelho do domínio de Q.
            - Se atribuímos Q=verde, e SA é adjacente a WA (vermelho) e Q (verde), então vermelho e verde são removidos do domínio de SA. Se o domínio de SA se tornar vazio, retrocede.
    - **Propagação de Restrições (Consistência de Arcos - Arc Consistency):** Mais poderosa que o Forward Checking. Um arco $X_i \rightarrow X_j$ é consistente se, para cada valor $x$ no domínio de $X_i$, existe algum valor $y$ no domínio de $X_j$ tal que $(x,y)$ satisfaz a restrição binária entr.
        - **Algoritmo AC-3:** Um algoritmo comum para impor consistência de arcos. Sua complexidade é $O(n^2d^3)$.
        - **Exemplo:** Se D(SA)={azul} e D(NT)={azul}, e há uma restrição SA ≠ NT, o AC-3 detectaria essa inconsistência, pois para SA=azul não há valor em D(NT) que satisfaça a restrição.
    - **Exemplo 4-Rainhas com Forward Checking:** 
        - Ao colocar R1 na linha 2, o Forward Checking elimina a linha 2 para R2, R3, R4; a diagonal para R2, etc. Isso reduz drasticamente os domínios.
- **Retrocesso Inteligente (Backjumping):**
    - **Chronological Backtracking:** Volta para a variável mais recentemente instanciada. Pode ser ineficiente se a causa do conflito é anterior.
    - **Conflict-Directed Backjumping:** Salta diretamente para a variável mais recentemente instanciada que faz parte do **conjunto de conflito** (as variáveis que causaram a falha). Por exemplo, se atribuir valores a Q, NSW, V causa um conflito em SA, e T foi atribuído entre V e SA mas não está envolvido no conflito de SA, o backtracking cronológico alteraria T desnecessariamente. O backjumping iria para V, NSW ou Q.
    - O Forward Checking já realiza parte do trabalho do backjumping simples. Uma noção mais forte de conjunto de conflito pode ser usada para pular ainda mais.
    - **Aprendizagem (Learning):** Adicionar novas restrições (aprendidas com os conflitos) para evitar a repetição dos mesmos erros. Ex: se WA=vermelho e NSW=vermelho leva a um conflito, adiciona-se a restrição "não (WA=vermelho E NSW=vermelho)".

#### 3. Procura Local para CSPs

- **Ideia:** Começa com uma atribuição completa (todas as variáveis têm valores), que pode violar algumas restrições.
- **Funcionamento:** Tenta iterativamente modificar o valor de uma variável por vez para reduzir o número de conflitos.
- **Heurística Min-Conflicts:**
    - Seleciona aleatoriamente uma variável que está em conflito.
    - Atribui a essa variável o valor que minimiza o número de conflitos. Se houver empates, escolhe aleatoriamente.
- **Exemplo (N-Rainhas):** Começa com N rainhas no tabuleiro (ex: uma por coluna, linha aleatória). Escolhe uma rainha em conflito e a move para a posição na sua coluna que gera menos novos conflitos. Pode resolver problemas muito grandes (N=10.000.000) com alta probabilidade e rapidamente.
- **Vantagens:** Muitas vezes eficiente para problemas grandes e encontra soluções rapidamente.
- **Desvantagens:** Incompleta – pode ficar presa em mínimos locais e não garante encontrar uma solução se existir, nem provar que não há solução.

---

### Estrutura do Problema

- A estrutura do grafo de restrições pode simplificar a resolução do CSP.
- **CSPs com Estrutura em Árvore:** Se o grafo de restrições é uma árvore (sem ciclos), o CSP pode ser resolvido em tempo $O(nd^2)$, que é muito mais eficiente que $O(d^n)$ para grafos gerais.
- **Aproximação para Árvore (para grafos gerais):**
    - **Remoção de Nós (Cutset Conditioning):** Atribuir valores a um pequeno conjunto de variáveis (o "cutset") de forma que o grafo restante seja uma árvore. Resolve-se o problema para cada atribuição do cutset. Encontrar o menor cutset é NP-difícil, então usam-se aproximações. Ex: Atribuir um valor a SA no mapa da Austrália pode simplificar o resto.
    - **Colapsagem de Nós (Tree Decomposition):** Decompor o problema em subproblemas interconectados que formam uma estrutura de árvore. Cada subproblema é resolvido e as soluções combinadas.

---

**Conclusões:**

- Padrões de projeto de algoritmos oferecem abordagens genéricas. A Força Bruta é direta mas muitas vezes ineficiente.
- Técnicas como Backtracking e Branch-and-Bound exploram o espaço de soluções de forma mais inteligente, podando ramos inviáveis ou não ótimos, sendo essenciais para problemas de decisão e otimização que seriam intratáveis pela força bruta.
- CSPs fornecem um framework poderoso para modelar problemas com variáveis e restrições.
- O algoritmo de retrocesso é a base para CSPs, mas pode ser significativamente melhorado com heurísticas, forward checking, propagação de restrições e técnicas de retrocesso inteligente.
- A procura local com heurísticas como min-conflicts é muito eficaz para CSPs de grande escala, embora seja incompleta.
- Explorar a estrutura do problema, como decomposições em árvores, pode levar a ganhos exponenciais de eficiência.
