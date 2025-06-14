**12/06 - Projeto e Análise de Algoritmos - Algoritmos Genéticos**

Os **Algoritmos Genéticos (AGs)** são um método de busca local inspirado na teoria da evolução biológica de Charles Darwin. Eles são particularmente eficazes para explorar espaços de busca muito grandes e complexos, onde métodos de busca tradicionais poderiam levar um tempo impraticável para encontrar uma solução satisfatória.

---

### Conceitos Fundamentais

A terminologia dos Algoritmos Genéticos é emprestada da biologia:

* **População:** Um conjunto de possíveis soluções para o problema.
* **Indivíduo (ou Cromossomo):** Uma única solução (um ponto no espaço de busca). Cada indivíduo é composto por um conjunto de genes.
* **Gene:** Um único parâmetro ou parte da solução.
* **Função de Avaliação (Fitness):** Uma função que mede a "qualidade" ou "aptidão" de um indivíduo, ou seja, o quão boa é aquela solução para o problema. O objetivo do AG é maximizar essa função.
* **Geração:** Cada ciclo iterativo do algoritmo, onde uma nova população é criada a partir da anterior.

---

### Funcionamento do Algoritmo Genético

O processo de um Algoritmo Genético segue um ciclo evolutivo:

1.  **Inicialização:** Uma população inicial de indivíduos (soluções) é criada, geralmente de forma aleatória.
2.  **Avaliação:** A função de fitness é calculada para cada indivíduo da população, medindo sua qualidade.
3.  **Seleção:** Indivíduos mais "aptos" (com maior valor de fitness) são selecionados com maior probabilidade para se tornarem "pais" da próxima geração. Um método comum é a **seleção por roleta**, onde cada indivíduo recebe uma fatia da roleta proporcional à sua aptidão.
4.  **Reprodução (Operadores Genéticos):** Os pais selecionados geram filhos através de dois operadores principais:
    * **Crossover (Recombinação):** Combina o material genético (partes do cromossomo) de dois pais para criar um ou mais filhos, que herdam características de ambos.
    * **Mutação:** Introduz pequenas e aleatórias alterações nos genes de um filho. Isso garante diversidade genética na população e ajuda a evitar que a busca fique presa em ótimos locais.
5.  **Nova Geração:** Os filhos criados formam a nova população.
6.  **Término:** O ciclo se repete (passos 2 a 5) até que uma condição de parada seja atingida, como um número máximo de gerações, um tempo limite, ou quando uma solução com qualidade suficiente é encontrada.

---

### Vantagens e Aplicações

* **Vantagens:**
    * São robustos e podem lidar com espaços de busca complexos, ruidosos e multimodais (com vários picos de "boa solução").
    * Têm uma natureza inerentemente paralela, pois a avaliação de cada indivíduo pode ser feita de forma independente.
    * São bons para encontrar soluções "boas o suficiente" rapidamente, em vez de garantir a solução ótima.

* **Aplicações:**
    * Problemas de otimização e aprendizado de máquina.
    * Alocação de tarefas e configuração de sistemas complexos.
    * Seleção de rotas e problemas de agendamento.
