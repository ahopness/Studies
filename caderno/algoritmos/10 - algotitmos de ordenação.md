**06/05 - Projeto e Análise de Algoritmos - Algoritmos de Ordenação**

- A ordenação é uma tarefa fundamental e muito comum na computação, utilizada para organizar sequências de elementos (números, nomes, etc.) de acordo com uma relação de ordem específica (ex: crescente, decrescente, alfabética).
- Ter dados ordenados facilita operações subsequentes, como busca e recuperação de informações.
- A comparação entre algoritmos de ordenação geralmente se baseia em suas complexidades de tempo, sendo a operação dominante, na maioria dos casos, o número de comparações entre elementos.

---

### Bubble-Sort (Método da Bolha)

- **Ideia:** Percorre o vetor repetidamente. A cada passagem, compara elementos adjacentes e os troca de posição se estiverem na ordem errada. Isso faz com que o maior (ou menor, dependendo da ordem) elemento "borbulhe" para sua posição correta ao final de cada passagem completa.
- **Complexidade:** $\Theta(n^2)$ em todos os casos (melhor, médio e pior), devido aos loops aninhados. É um dos algoritmos mais simples de entender, mas ineficiente para grandes conjuntos de dados.

---

### Quick-Sort (Ordenação Rápida / Troca de Partição)

- **Ideia (Divisão e Conquista):**
    1.  **Dividir:** Escolhe-se um elemento do vetor como **pivô**. O vetor é então reorganizado (particionado) de forma que todos os elementos menores que o pivô fiquem à sua esquerda, e todos os maiores fiquem à sua direita. O pivô acaba em sua posição final correta.
    2.  **Conquistar:** Os subvetores à esquerda e à direita do pivô são ordenados recursivamente usando o mesmo processo.
    3.  **Combinar:** Nenhum passo explícito de combinação é necessário, pois a ordenação ocorre "no lugar" (in-place) durante o particionamento.
- **Complexidade:**
    - **Melhor Caso e Caso Médio:** $\Theta(n \log n)$.
    - **Pior Caso:** $\Theta(n^2)$ (ocorre quando o pivô escolhido é consistentemente o menor ou o maior elemento, levando a partições desbalanceadas, como em um vetor já ordenado ou inversamente ordenado com uma má escolha de pivô).

---

### Insertion-Sort (Inserção Simples / Direta)

- **Ideia:** Funciona construindo uma sub-lista ordenada no início do vetor. A cada passo, o próximo elemento não ordenado é pego e inserido em sua posição correta dentro da sub-lista já ordenada, deslocando os elementos maiores para abrir espaço.
- **Complexidade:**
    - **Melhor Caso:** $\Theta(n)$ (quando o vetor já está ordenado, apenas verificações são feitas).
    - **Pior Caso e Caso Médio:** $\Theta(n^2)$ (quando o vetor está inversamente ordenado, exigindo o máximo de deslocamentos).
- É eficiente para listas pequenas ou parcialmente ordenadas.

---

### Selection-Sort (Seleção Direta / Simples)

- **Ideia:**
    1.  Encontra o menor elemento na porção não ordenada do vetor.
    2.  Troca esse menor elemento com o primeiro elemento da porção não ordenada.
    3.  Move o limite da porção ordenada um elemento para a direita e repete o processo até que todo o vetor esteja ordenado.
- **Complexidade:** $\Theta(n^2)$ em todos os casos (melhor, médio e pior), pois sempre realiza o mesmo número de comparações para encontrar o próximo menor elemento, independentemente da ordem inicial dos dados.

---

### Merge-Sort (Ordenação por Intercalação)

- **Ideia (Divisão e Conquista):**
    1.  **Dividir:** O vetor é dividido recursivamente ao meio até que cada subvetor contenha apenas um elemento (ou esteja vazio), que é considerado ordenado.
    2.  **Conquistar:** (É implícito na divisão).
    3.  **Combinar (Intercalar/Merge):** Os subvetores ordenados são combinados (intercalados) de forma ordenada para produzir subvetores maiores e ordenados, até que todo o vetor original esteja ordenado. Este passo geralmente requer um vetor auxiliar.
- **Complexidade:** $\Theta(n \log n)$ em todos os casos (melhor, médio e pior), tornando-o um algoritmo de ordenação muito confiável e eficiente em termos de tempo. Sua principal desvantagem é o uso de espaço adicional para o vetor auxiliar.

---

**Conclusão:**

A escolha do algoritmo de ordenação ideal depende de vários fatores, como o tamanho do conjunto de dados, se os dados estão parcialmente ordenados, os recursos de memória disponíveis e a necessidade de estabilidade. Algoritmos como Merge-Sort e Quick-Sort (em seu caso médio) oferecem melhor desempenho ($ \Theta(n \log n) $) para grandes volumes de dados em comparação com os algoritmos quadráticos ($ \Theta(n^2) $) como Bubble-Sort, Insertion-Sort e Selection-Sort.