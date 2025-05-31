#set page(
  paper: "a4",
  margin: (x: 2cm, y: 2cm),
  columns: 2,
  numbering: "1"
)
    
#set text(10pt, font: "TeX Gyre Pagella")
#show heading: set text(size: 12pt)
#set list(indent: 8pt)
#show figure: set text(size: 8pt)

#place(
  top,
  scope: "parent",
  float: true,
  {
    text(24pt, weight: "bold", "ANÁLISE EXPERIMENTAL DE ALGORITMOS: BUBBLE SORT & QUICK SORT")
    parbreak()
  
    text(12pt, "Lucas Ângelo Câmara da Silva")
    v(8pt)
    
    text(10pt, 
"Instituto Politécnico, Universidade do Estado do Rio de Janeiro
Disciplina: Projeto e Análise de Algoritmos
Professor: Profª. Drª. Camila Martins Saporetti")
    v(8pt)

    text(10pt, "Junho, 2025")
    v(8pt)
    
    heading(outlined: false, bookmarked: false)[Resumo]
    text("Uma análise e comparação didática de dois algoritmos ordinários de ordenação: Bubble Sort (desempenho consistentemente inferior) & Quick Sort (desempenho altamente eficiente na maioria dos cenários).")
    parbreak()
  
    heading(outlined: false, bookmarked: false)[Palavras-chave]
    text("Algoritmos, Ordenação, Complexidade, Análise de Algoritmos, Bubble Sort, Quick Sort.")
    v(18pt)
  }
)

= INTRODUÇÃO

Os algoritmos de ordenação são algoritmos determinísticos muito utilizados no aprendizado de computação por demonstrarem a interferência de fluxos de controles na performance de programas. Este estudo foca na comparação tamanho da entrada x tempo de execução de dois algoritmos diferentes: bubble sort - move elementos da esquerda para a direita até que o elemento movido continuar sendo menor que o que ele ultrapassou - e quick sort - _divide e conquista_ o vetor ao redor de um pivô trocando os elementos grandes do lado esquerdo pelos elementos menores do lado direito @1. 

= METODOLOGIA

== Algoritmos

#v(6pt)

- Bubble Sort

Funciona operando da esquerda para a direita, transportando elementos como se fossem bolhas através do vetor, prosseguindo para o proximo assim que ele passa de um elemento que é menor que ele mesmo. É dito como uma ordenação elementar, pois para cada elemento a ser ordenado, todos os outros elementos são verificados.

#v(100pt)

- Quick Sort

Seu principal fator é um pivô, um elemento - muitas vezes o elemento do meio, mas que tambem pode ser o elemento do início, fim ou um aleatótio - que serve de ancora que verifica que os valores a sua esquerda sejam menores que ele e os valores a sua direita sejam maiores que ele, repartindo os dois lados do vetor e execultando a operação recursivamente até o mesmo estar ordenado. Esse é um algorítmo de divisão e conquista por quebrar o vetor em porções menores para ordena-lo.

== Computador

Os testes, todos executados em single thread na versão convencional do
Python 3.10 e em um laptop com um processador Intel© Pentium© N3710 com 4 núcleos de 1.60GHz cada, com 4GB de memoria RAM e 6GB de memoria Swap, com o sistema operacional Linux Mint 21.3 Cinnamon.

= RESULTADOS

Vale ressaltar que todos os gráficos apresentados possuem flutuações no eixo de tempo. Esse ruído se deve ao funcionamento complexo dos sistemas operacionais e hardware modernos, que alternam entre diferentes processos devido a funcionalidade de multitasking e o transporte de memoria entre o cache da CPU e a memória RAM, porem todos os gráficos ainda apresentam padrões dignos de serem estudados.

#figure(
  image("ordinarios_decrescente.svg"),
  caption: [Ordenação de um vetor com números decrescentes],
  supplement: "Gráfico"
) <odec>

Este é o pior caso de que um algorítmo de ordenação pode encontrar, pois ele vai ter que ordenar todos os elementos do vetor. O @odec mostra o Quick Sort performando 62.5% vezes mais rapido que o Bubble Sort performando, fato curioso devido a ambos os algorítimos possuirem a mesma notação de $Omicron(n^(2))$ no pior caso @2, porem o Quick Sort performa melhor no teste devido as suas operações mais eficientes (em parte pela estrateja de _dividir e conquistar_ o vetor).

#figure(
  image("ordinarios_crescente.svg"),
  caption: [Ordenação de um vetor com números crescentes],
  supplement: "Gráfico"
) <ocre>

Ja este é o melhor caso que um algorítmo de ordenação pode encontrar, pois todos os numeros do vetor já estão ordernados. O @ocre mostra que o quicksort possui uma fraquesa neste caso, performando na notação $Omicron(n^2)$ contra $Omicron(n)$ (que aparenta ser $Omicron(1)$ de tão rapido), fraquesa que se deve pelo mesmo fator que foi seu diferencial no teste anterior, a _divisão e a conquista_.

#figure(
  image("ordinarios_aleatorio.svg"),
  caption: [Ordenação de um vetor com números aleatórios],
  supplement: "Gráfico"
) <oale>

Porem é neste caso onde a diferença entre os dois fica mais notavel, o teste de valores aleatórios, demostrando um caso médio entre os dois anteriores. O Bubble Sort é *sempre ruim* em casos médios devido a ele performar com a mesma notação que em casos ruins de ordenação, com uma notação de $Omicron(n^2)$, contra o Quick Sort, que demonstra comportamento *_geralmente_ excelente* em casos médios por ele performar com a mesma notação que em casos _bons_ de ordenação, com uma notação de $Omicron(n log n)$ @2.

#figure(
  image("multiplos_decrescente.svg"),
  caption: [Ordenação períodica de um vetor com números decrescentes],
  supplement: "Gráfico"
) <mdec>

Nos proximos 3 gráficos foi analisado casos mais extremos, de vetores de entrada 10, 100, 1.000 e 10.000 de forma periódica, onde é possivel notar melhor as consequencias das notações entre cada algorítmo, com o @mdec reforçando a diferença de tempo entre os dois.  

#figure(
  image("multiplos_crescente.svg"),
  caption: [Ordenação períodica de um vetor com números crescentes],
  supplement: "Gráfico"
) <mcre>

O @mcre enfatiza o maleficio principal do Quick Sort com vetores já ordenados de tamanhos elevados.

#figure(
  image("multiplos_aleatorio.svg"),
  caption: [Ordenação períodica de um vetor com números aleatórios],
  supplement: "Gráfico"
) <male>

E por ultimo, o @male enfatiza como o beneficio do Quick Sort é notavel comparado com o Bubble Sort, com os dois quase se espelhando comparado com o @mcre.

= CONCLUSÃO

O Bubble Sort é simples em sua funcionalidade mas peca quando lida com vetores de complexidade média ou elevada, que é a grande maioria dos casos vistos no cotidiano, já o Quick Sort demonstra um comportamento exatamente oposto, sendo ruim apenas para vetores ordenados ou pouco ordenados, mas mesmo assim tomando pouco tempo de processamento nesses casos, sendo um dos algorítmos de ordenação mais populares e ja vindo embutidos em linguagens como o Java @3.

= REFERÊNCIAS

#bibliography(
  "refs.yaml", 
  style: "associacao-brasileira-de-normas-tecnicas", 
  title: none
)