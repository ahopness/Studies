**03/06 - Projeto e Análise de Algoritmos - Programação Dinâmica**

A **Programação Dinâmica (PD)** é uma técnica de projeto de algoritmos, similar à Divisão e Conquista, usada para resolver problemas de otimização. Sua principal característica é a capacidade de lidar eficientemente com **subproblemas sobrepostos**.

* **Ideia Central:** Em vez de recalcular a solução para o mesmo subproblema várias vezes, a PD resolve cada subproblema apenas uma vez e armazena sua solução em uma tabela. Quando a solução para aquele subproblema é necessária novamente, ela é simplesmente consultada na tabela, economizando tempo computacional.

* **Quando usar?** A PD é eficaz quando um problema pode ser quebrado em subproblemas que se repetem e quando a solução ótima do problema geral depende das soluções ótimas de seus subproblemas (propriedade chamada **Princípio da Otimalidade**).

* **Abordagens Principais:**
    * **Top-Down (Memoization):** Uma abordagem recursiva que resolve os problemas conforme eles aparecem, armazenando os resultados para evitar recálculos.
    * **Bottom-Up (Tabulation):** Uma abordagem iterativa que preenche a tabela de soluções começando pelos menores subproblemas e avançando em direção ao problema original.

#### Problema da Parentização de Matrizes

Este é o problema central para a atividade. O objetivo é encontrar a maneira mais econômica (com o menor número de multiplicações escalares) de multiplicar uma cadeia de matrizes `A1 * A2 * ... * An`. A ordem em que as multiplicações são feitas afeta drasticamente o custo total.

* **Entrada:** Um vetor de dimensões `p = [p0, p1, ..., pn]`, onde a matriz `Ai` tem dimensões `pi-1 x pi`.
* **Fórmula Recursiva:** Para resolver o problema, usamos uma fórmula que calcula o custo mínimo `m[i, j]` para multiplicar a cadeia de matrizes de `Ai` até `Aj`.
    * Se `i = j` (uma única matriz), o custo é 0.
    * Se `i < j`, o custo é o mínimo entre todas as possíveis posições `k` para dividir a cadeia:
        $$m[i,j] = \min_{i \le k < j} \{ m[i,k] + m[k+1,j] + p_{i-1} \cdot p_k \cdot p_j \}$$
       
        Onde:
        * `m[i,k]` é o custo de resolver o primeiro subproblema `(Ai...Ak)`.
        * `m[k+1,j]` é o custo de resolver o segundo subproblema `(Ak+1...Aj)`.
        * `p_{i-1} \cdot p_k \cdot p_j` é o custo de multiplicar as duas matrizes resultantes.

