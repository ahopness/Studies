**25/06 - Projeto e Análise de Algoritmos - Otimização por Colônia de Formigas**


Esta aula aborda a Otimização por Colônia de Formigas (ACO), uma técnica bioinspirada que utiliza o comportamento das formigas para resolver problemas de otimização.

---

### Inteligência de Enxame

- **Definição:** Algoritmos em que agentes atuam localmente, realizando interações com o grupo, resultando em um padrão coerente global que resolve um problema. Não há centralização e a coordenação ocorre sem comunicação evidente.
- **Características:** Individualismo vs. Coletivo; cada agente interage localmente com o ambiente; essa interação causa um padrão coerente global resolvendo um problema; não existe centralização; coordenação sem comunicação evidente.
- **Algoritmos Populares:** Ant Colony Optimization (ACO) e Particle Swarm Optimization (PSO).
- **Comportamentos "Inteligentes" de Insetos Sociais:**
    - **Formigas:** Definição de trilhas até as fontes de comida através de feromônios; formação de pontes com seus corpos para superar obstáculos.
    - **Abelhas:** Construção padronizada da colmeia; regulação da temperatura; exploração de fontes de alimento por qualidade e distância.
    - **Cupins:** Construção de túneis de comunicação; construção de pilares de sustentação.
- **Comportamentos Estudados em Formigas:** Organização para agrupar e ordenar larvas e indivíduos mortos; busca de alimentos e rotas (feromônios); divisão de tarefas; reconhecimento de indivíduos do grupo.

---

### Otimização por Colônia de Formigas (ACO)

- **Inspiração:** Baseado no comportamento de busca de alimento por formigas, que encontram os caminhos mais curtos entre a colônia e uma fonte de alimento.
- **Mecanismo:** As formigas depositam uma substância química (feromônio) no chão enquanto caminham, criando um rastro. Outras formigas são atraídas por esse rastro, e quanto mais feromônio, mais atraente é o caminho. O feromônio evapora com o tempo.
- **Caminho Mais Curto:** Em caminhos mais curtos, as formigas voltam mais rapidamente, reforçando o rastro de feromônio mais intensamente do que em caminhos mais longos. Isso faz com que o feromônio se acumule mais rapidamente nos caminhos ótimos.
- **Componentes do Modelo ACO:**
    - **Feromônio:** Representa a atratividade de um caminho.
    - **Evaporação:** Simula a evaporação do feromônio, permitindo que o sistema "esqueça" caminhos menos eficientes e evite a convergência prematura.
    - **Probabilidade de Escolha:** As formigas escolhem o próximo nó com base na quantidade de feromônio no caminho e na heurística da distância (inverso da distância).
- **Algoritmos ACO Populares:**
    - **Ant System (AS):** O primeiro e mais simples algoritmo ACO.
    - **Ant Colony System (ACS):** Introduz uma regra de atualização local de feromônio e uma estratégia de "ação-melhor".
    - **Max-Min Ant System (MMAS):** Limita a quantidade de feromônio para evitar a estagnação e promove a exploração.

---

### Aplicações do ACO

- **Problema do Caixeiro Viajante (TSP):** Onde o ACO é frequentemente testado e demonstra bons resultados na busca do menor caminho entre cidades.
- **Otimização Contínua:** Utilizado para problemas onde as variáveis de decisão são contínuas.
- **Otimização Combinatória:** Amplamente aplicado em problemas de roteamento, escalonamento e alocação de recursos.

---

### Vantagens e Desvantagens do ACO

- **Vantagens:**
    - Para o TSP (Traveling Salesman Problem) é relativamente eficiente, especialmente para um grande número de nós, onde TSPs são computacionalmente muito difíceis de resolver (NP-hard).
    - Possui um melhor desempenho do que outras técnicas de otimização (Algoritmos Genéticos, Simulated Annealing, etc.).
    - Retém toda a memória da colônia, ao invés de apenas a geração anterior.
    - A solução está no ambiente e não no agente.
    - Pouco afetado por uma inicialização "pobre" (random path selection e colony memory).
    - Pode ser utilizado em aplicações dinâmicas.
    - É continuamente empregado em uma vasta variedade de aplicações.
    - É uma boa escolha para problemas de restrições discretas.
- **Desvantagens:**
    - A análise teórica é complicada.
    - Sequências aleatórias podem causar lentidão.
    - Pode exigir muitos parâmetros para ajustar.
    - Pode convergir lentamente em alguns casos.
    - Dificuldade em lidar com problemas de otimização de grande escala.
