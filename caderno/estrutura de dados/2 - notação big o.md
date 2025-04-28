**25/03 - Algoritmos e Estrutura de Dados - Notação Big O**

-  Na criação de um algoritmo dentro de um ambiente onde a performance é um fator matriz é necessario a optimização dos comandos, começando pela investigação dos comandos sendo execultados e verificando o impacito que elas tem na demora que o hardware tem para execulta-lo. Essa investigação pode ser feita mais facil utilizando uma notação Big O.

<br>
<div align="center">
    <img height="250px" src="https://upload.wikimedia.org/wikipedia/en/0/0e/Big_o.jpg"></img>
    <p><i>Aparentemenre tem um anime chamado Big O, oq torna tudo mais bizzaro ainda...</i></p>
</div>

---

### Gênesis

```c
int bubblesort(int *a, int size) 
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
            swap(a+j, a+j+1);
            }
        }
        if (swapped == 0)
            return 1; 
    }
    return 0;
}
```
*Ex.1: BubbleSort.*

- Para verificar o custos da função, devemos buscar a quantidade de operações e iterações que ela execulta:
  - Usando o exemplo acima de base, a primeira iteração faz *size* operções, isto é, o tamanho do vetor está diretamente relacionando a quantidade de comparações (`a[j] > a[j + 1]`) que a função vai execultar.
  - Essa função execulta 2 iterações, então precisamos contar **os casos** de ambas: sendo *size* & *size - i - 1*.

- Dado a contagem, nós diluimos as constantes (pois oque queremos investigar é a complexidade gradual do algoritmo), restando apenas a variação da complexidade de execulção: **O(n²)**.

<div align="center"><i>Extra: n=size; onde size * size; onde n é o crescimento de complexiade gradual.</i></div>

---

### Apocalipse

<br>
<div align="center">
    <img height="250px" src="https://miro.medium.com/v2/resize:fit:640/format:webp/0*5a1WQJGJeriFo4RT"></img>
    <br>
    <p>A notação Big O é uma ferramenta matemática que permite avaliar a eficiência de algoritmos usando a entrada deles como medida.</p>
</div>

- Concorda que um algoritmo pode variar de performance depende do tamando e da organização de uma entrada? Para isso que nós devemos estudar cada casos a parte:
  - **Ex. de melhor caso (Notação Ω):** [1,2,3,4,5,6,7,8,9,10];
  - **Ex. de pior caso (Notação θ):** [10,9,8,7,6,5,4,3,2,1];
  - **Ex. de Caso medio (Notação O):** (Mediana da maioria das variações entre os dois casos).