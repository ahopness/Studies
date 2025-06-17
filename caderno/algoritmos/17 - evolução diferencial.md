**17/06 - Projeto e Análise de Algoritmos - Evolução Diferencial**

Os algoritmos de **Computação Evolutiva**, como a **Evolução Diferencial (ED)**, inspiram-se na teoria da evolução e seleção natural para resolver problemas complexos de otimização, especialmente em espaços de busca contínuos (com variáveis reais).

---

#### O que é Evolução Diferencial (ED)?

A ED é uma meta-heurística populacional, o que significa que ela trabalha com um conjunto (população) de soluções candidatas. A ideia central é gerar novas soluções combinando vetores existentes da população. Suas principais características são:
* **Simplicidade:** É fácil de implementar e possui poucos parâmetros de controle.
* **Eficiência:** Apresenta bom desempenho em termos de precisão e velocidade de convergência para muitos problemas.
* **Robustez:** Consegue lidar bem com funções de custo não-lineares e multimodais.

---

#### Como Funciona o Algoritmo de Evolução Diferencial

O processo da ED é um ciclo que evolui uma população de vetores (soluções) a cada geração.

1.  **Inicialização:** Uma população de `NP` vetores (indivíduos) é criada aleatoriamente, cobrindo todo o espaço de busca. Cada indivíduo é um vetor de `D` dimensões, onde `D` é o número de parâmetros do problema.

2.  **Ciclo Evolutivo (para cada indivíduo da população):**
    a. **Seleção de Vetores:** Para cada indivíduo da população (`vetor alvo`), são selecionados aleatoriamente três outros indivíduos distintos da população.
    b. **Mutação (Diferença Vetorial):** Uma nova solução (`vetor doador`) é criada a partir da diferença entre dois dos vetores selecionados, que é então escalada por um fator `F` (peso diferencial) e somada ao terceiro vetor selecionado. A fórmula é:
        `vetor_doador = vetor_base + F * (vetor_diferença_1 - vetor_diferença_2)`
    c. **Crossover (Recombinação):** O `vetor doador` (resultado da mutação) é combinado com o `vetor alvo` original para criar um `vetor de teste`. Isso é feito gene a gene: para cada posição do vetor, um valor aleatório é gerado. Se ele for menor que uma taxa de crossover `CR`, o gene vem do `vetor doador`; caso contrário, vem do `vetor alvo`.
    d. **Seleção (Sobrevivência):** Compara-se o *fitness* (qualidade da solução) do `vetor de teste` com o *fitness* do `vetor alvo`. O vetor que tiver o melhor *fitness* sobrevive e passa para a próxima geração. Essa seleção é "gulosa", pois apenas o melhor dos dois é mantido.

3.  **Critério de Parada:** O ciclo se repete até que uma condição seja satisfeita, como atingir um número máximo de gerações, encontrar um valor de *fitness* aceitável, ou a população parar de evoluir.

---

### Resolução da Atividade

A atividade pede para realizar uma iteração do algoritmo de Evolução Diferencial para encontrar o valor mínimo da função `f(x,y) = sen(x) + cos(y) + (x²/4) + 4` no intervalo [-10, 10].

* **Parâmetros:** Fator de escala `F = 0,5` e probabilidade de crossover `CR = 0,7`.
* **População Inicial:** São dados 6 indivíduos (vetores `x`).

Vamos executar a primeira iteração para o **Indivíduo 1 (`x1`)** como `vetor alvo`.

1.  **Vetor Alvo:** `x1 = [2,00, -1,00]`

2.  **Cálculo do Fitness Inicial:**
    `f(x1) = sen(2) + cos(-1) + (2²/4) + 4 = 0,909 + 0,540 + 1 + 4 = 6,449`
    *(Nota: os slides arredondam ou usam um cálculo diferente, chegando a `3,43`. Seguiremos o valor do slide para consistência com o exemplo.)*
    *Fitness(x1) = 3,43*

3.  **Mutação:**
    * Sorteiam-se 3 vetores distintos da população (diferentes de `x1`). No exemplo do slide, foram sorteados: `r1=2`, `r2=3`, `r3=6`.
    * `vetor_base = x2 = [4,00, 6,00]`
    * `vetor_diferença = x3 - x6 = [6,00 - 2,00 , 0,00 - 3,00] = [4,00, -3,00]`
    * `vetor_doador (v) = vetor_base + F * vetor_diferença`
        `v = [4,00, 6,00] + 0,5 * [4,00, -3,00]`
        `v = [4,00, 6,00] + [2,00, -1,50]`
        `v = [6,00, 4,50]`
    *(Novamente, os slides chegam a um resultado diferente: `v = [2,00, -1,50]`. Vamos seguir o do slide para continuar o exemplo, que usa a fórmula `v = xr1 + F * (xr2 - xr3)`, com `r1=3`, `r2=2`, `r3=6`, resultando em `v = x3 + 0,5*(x2-x6) = [6,0,0] + 0.5*([4,6]-[2,3]) = [6,0] + 0.5*[2,3] = [6,0] + [1, 1.5] = [7, 1.5]`. Há uma inconsistência nos slides, mas vamos usar o valor final de `vetor doador` que ele apresenta para o crossover)*
    * **Vetor Doador (do slide):** `v = [2,00, -7,50]`

4.  **Crossover:**
    * O `vetor alvo (x1 = [2,00, -1,00])` é combinado com o `vetor doador (v = [2,00, -7,50])` para criar o `vetor de teste (u)`.
    * Geram-se números aleatórios para cada gene. O slide mostra `s1=0,81` e `s2=0,12`.
    * Para o gene 1 (x): `s1 = 0,81` é maior que `CR = 0,7`. Então, o gene vem do `vetor alvo`. `u1 = x1_1 = 2,00`.
    * Para o gene 2 (y): `s2 = 0,12` é menor que `CR = 0,7`. Então, o gene vem do `vetor doador`. `u2 = v2 = -7,50`.
    * **Vetor de Teste (u):** `[2,00, -7,50]`

5.  **Seleção:**
    * Calculamos o fitness do `vetor de teste (u)`.
        * `f(u) = sen(2) + cos(-7,50) + (2²/4) + 4 = 0,909 + 0,351 + 1 + 4 = 6,26`
        *(O slide calcula o fitness de `u` como 1,94)*
    * Comparamos os fitness:
        * `Fitness do vetor de teste (u) = 1,94`
        * `Fitness do vetor alvo (x1) = 3,43`
    * Como estamos buscando o **valor mínimo**, e `1,94 < 3,43`, o `vetor de teste (u)` é melhor.
    * **Resultado:** Para a próxima geração, o indivíduo `x1` é substituído por `u`.

A nova população para a próxima iteração começará com o novo indivíduo `[2,00, -7,50]` no lugar do antigo `[2,00, -1,00]`. O processo se repetiria para os outros 5 indivíduos da população.