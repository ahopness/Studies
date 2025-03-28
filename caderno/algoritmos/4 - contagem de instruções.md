**27/03 - Projeto e Analise de Algoritmos - Montagem de instruções**

```
AVISO: NÃO TIVE TEMPO DE TERMINAR, FIZ ESSE RESUMO COM A AJUDA DO GEMINI.
```

- A aula de hoje focou na análise de algoritmos através da contagem de instruções, um passo fundamental para o cálculo da complexidade e entendimento do tempo de execução.

---

### Tempo de Execução (Cálculo de Complexidade)

- O custo de execução de um algoritmo é primariamente dependente do **tamanho da entrada dos dados**.
- É comum expressar o tempo de execução de um programa como uma **função do tamanho da entrada**.
- Em alguns casos, o custo de execução pode variar dependendo da **entrada particular dos dados**, e não apenas do seu tamanho (exemplo: algoritmos de ordenação com dados quase ordenados).
- O tempo de execução de um algoritmo é determinado pela **contagem do número de instruções que ele realiza**.

---

### Operações Primitivas (Custo = 1 Unidade de Tempo - UT)

- Para simplificar a análise inicial, assume-se que as seguintes **operações primitivas** possuem o mesmo custo, definido como 1 Unidade de Tempo (UT):
  - Atribuição de valores a variáveis
  - Chamadas de métodos
  - Operações lógicas e aritméticas
  - Comparação de dois números
  - Acesso a elemento de um array
  - Seguir uma referência de objeto (acesso a objeto)
  - Retorno de um método

- Algumas instruções, como **comandos de seleção**, podem ter custo zero (aparentemente referindo-se ao custo da instrução de seleção em si, não das operações dentro dos blocos).

---

### Contagem de Instruções (Foco da Aula)

- A aula de hoje se concentrou na análise de **comandos de condição e de repetição**.
- A aula passada (mencionada brevemente) abordou outros aspectos da contagem de instruções.

---

### Análise de Programas de Exemplo (Maior e Menor Valor)

- Foram analisados diferentes versões de um programa para encontrar o maior e o menor valor em um vetor (`Programa 1.2` e `Programa 1.3`).
- A análise considerou diferentes cenários:
  - **Melhor Caso**: A ordem dos dados de entrada que leva ao menor número de operações.
  - **Pior Caso**: A ordem dos dados de entrada que leva ao maior número de operações.
  - **Caso Médio**: Uma estimativa do número de operações para uma entrada típica.

- **Programa 1.2 (Caso Médio):**
  - O custo médio foi calculado como `(5n + 1) + (5n + 1))/2 = 5n + 1`.

- **Programa 1.3 (com `else if`):**
  - **Melhor Caso (ordem crescente):** `f(n) = 4n + 2`
    - Detalhamento da contagem de cada tipo de operação (inicialização, `for`, comparações, atribuições).
  - **Pior Caso (ordem decrescente):** `f(n) = 5n + 1`
    - Detalhamento da contagem de cada tipo de operação.
  - **Caso Médio:** `((4n + 2) + (5n + 1))/2 = (9n + 3)/2`

---

**Conclusão:**

A aula introduziu o conceito de contagem de instruções como base para analisar o tempo de execução de algoritmos. Foram definidos custos unitários para operações primitivas e demonstrada a análise de diferentes casos (melhor, pior e médio) através de exemplos práticos de código para encontrar o maior e menor valor em um vetor. A análise envolve a contagem detalhada das operações dentro de estruturas de controle como `for` e `if/else`.