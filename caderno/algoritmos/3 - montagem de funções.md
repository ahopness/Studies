**25/03 - Projeto e Analise de Algoritmos - Montagem de funções**

- Porblemas não são exclusivos de um algoritmo só, eles podem ser resolvidos por vários e de forma plural, porem o algoritmo de melhor esforço vai ser aquele que para toda (ou quase toda) instancia do problema, ele retorna uma instancia correta.

- Para chegar em um algoritmo de melhor esforço,temos ferramentas como *experimentação* e *analise assintotica* ao nosso dispor, para medir, por exemplo, a quantidade de memoria usada, o quantidade de operações usadas e o custo para o algoritmo ser executado.

---

### As analises em sí

- Analise Impirica:
  - Avalia o custo de um algoritmo já implementado e em execução de força submissa ao hardware;
  

- Analise Matematica (Big O):
  - Avalia formalmente um algotitmo, suas entradas, saindas, complexidade e o tempo de execução
  - *PS*: Não é comum analisar a memoria, apenas sé ocorrer algum memory leak.

<br>

- Alguns fatores que devem ser analisados:
  - Atribuição de valores a variáveis;
  - Chamadas de métodos;
  - Operações aritméticas;
  - Comparação de dois números;
  - Acesso a elemento de um array;
  - Seguir uma referência de objeto (acesso a objeto);
  - Retorno de um método.

---

### O tempo de execução

- Diante ambas formas de analises, uma forma de medir a optimização de cada algoritmo é inserindo um conjunto de entradas bem escolhidos e medir o tempo de execução usando ferramentas tradicionais como *top* ou *time* (ambos para sistemas unix).

- Uma limitação dessa forma de medir a eficiencia de um algoritmo é como a quantidade e o formato das entradas raramente vão englobar todos os casos onde o algoritmo vai ser ultilizado pelo usuario final.

