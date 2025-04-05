**03/04 - Projeto e Análise de Algoritmos - Análise de Recorrência**

- Quando algoritmos utilizam **chamadas recursivas**, seu tempo de execução é frequentemente descrito por uma **recorrência**.
- Para algoritmos recursivos, a principal ferramenta de análise é a **relação de recorrência**, uma equação que descreve uma função em termos de seu valor para entradas menores.
- A cada procedimento recursivo associa-se uma função de complexidade desconhecida, T(n), onde 'n' é o tamanho da entrada.

---

### Definição de Relação de Recorrência

- Uma **relação de recorrência** para uma sequência `a_n` é uma equação que expressa `a_n` a partir de:
    - Um ou mais **termos iniciais** da sequência (condições de base).
    - Uma **regra** para determinar termos subsequentes a partir dos termos anteriores.
- Uma sequência **satisfaz** a relação de recorrência se seus termos obedecem à regra.
- Uma equação é uma **solução** para a relação de recorrência se ela calcula o mesmo termo `a_n` que a regra da relação para todo `n`.
- Os **termos iniciais** definem unicamente a sequência gerada pela relação de recorrência.

---

### Relações de Recorrência - Exemplos

- **Exemplo 1 (Crescimento de Bactérias):**
    - Problema: Colônia começa com 5 bactérias, dobra a cada hora. Quantas após `n` horas?
    - Recorrência: `a_n = 2 * a_{n-1}` para `n > 0`, com `a_0 = 5`.
- **Exemplo 2 (Cálculo de Termos):**
    - Dada `a_0 = 3`, `a_1 = 5` e `a_n = a_{n-1} - a_{n-2}` para `n > 1`. [56]
    - Calcular `a_2 = a_1 - a_0 = 5 - 3 = 2`.
    - Calcular `a_3 = a_2 - a_1 = 2 - 5 = -3`.
- **Exemplo 3 (Verificação de Soluções):**
    - A aula demonstrou como verificar se uma fórmula (ex: `a_n = 3n`, `a_n = 2^n`, `a_n = 5`) é solução para uma dada recorrência (ex: `a_n = 2a_{n-1} - a_{n-2}`).
- **Exemplo 4 (Problema de Fibonacci):**
    - Problema: Número de casais de coelhos que se reproduzem após 2 meses. 
    - Recorrência: `f_n = f_{n-1} + f_{n-2}` para `n >= 2`, com `f_0 = 1`, `f_1 = 1`.
- **Exemplo 5 (Torres de Hanoi):**
    - Problema: Número mínimo de movimentos para mover `n` discos entre três pinos.
    - Recorrência: `a_n = 2a_{n-1} + 1` para `n > 1`, com `a_1 = 1`. 
    - Solução (encontrada por método iterativo): `a_n = 2^n - 1`.
- **Exemplo 6 (Sequências de Bits sem "00"):**
    - Problema: Número de sequências binárias de tamanho `n` sem zeros consecutivos.
    - Recorrência: `a_n = a_{n-1} + a_{n-2}` para `n >= 3`, com `a_1 = 2`, `a_2 = 3`.
- **Exemplo 7 (Códigos Decimais Válidos):**
    - Problema: Número de códigos decimais de `n` dígitos com um número par de zeros.
    - Recorrência: `a_n = 8a_{n-1} + 10^{n-1}` (derivada considerando códigos válidos e inválidos de tamanho `n-1`).

---

**Conclusão:**

A aula introduziu as **relações de recorrência** como uma ferramenta matemática fundamental para analisar a complexidade de **algoritmos recursivos**. Foram apresentadas as definições formais e diversos exemplos clássicos (Fibonacci, Torres de Hanoi) e combinatórios (sequências de bits, códigos) para ilustrar como derivar e, em alguns casos, resolver essas recorrências.