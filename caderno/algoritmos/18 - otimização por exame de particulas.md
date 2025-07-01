**19/06 - Projeto e Análise de Algoritmos - Otimização por Enxame de Partículas**

Esta aula aborda a Otimização por Enxame de Partículas (PSO), uma técnica inspirada na Inteligência de Enxame e na cognição social humana.

---

### Inteligência de Enxame

- **Definição:** Algoritmos onde agentes atuam localmente, interagindo com o grupo, resultando em um padrão coerente global que resolve um problema. Não há centralização e a coordenação ocorre sem comunicação evidente.
- **Características:** Individualismo x Coletivo, interação local com o ambiente, e a emergência de um padrão coerente global.
- **Exemplos na Natureza:** Busca por alimento, organização de ninhos, voo em grupo de pássaros, e a organização de formigas (como as cortadeiras e as tecelãs).
- **Exemplos no Dia a Dia:** Trânsito, atribuição de tarefas em equipes, linhas de montagem e cirurgias médicas.
- **Propriedades da Inteligência Coletiva:** Proximidade (agentes interagem), Qualidade (agentes avaliam comportamentos), Diversidade (reage a inesperados), Estabilidade (variações não afetam o agente), e Adaptabilidade (adequa-se a variações ambientais).

---

### Adaptação Social do Conhecimento e Cognição Social

- O PSO simula o comportamento social humano, especialmente a capacidade de processar conhecimento, baseando-se em uma população de agentes que interagem entre si e com o ambiente.
- Cada indivíduo (partícula) possui experiência própria e avalia sua qualidade, além de ter conhecimento do comportamento de seus vizinhos.
- A decisão de um indivíduo é influenciada pelo seu desempenho passado e pelo desempenho dos vizinhos (aprendizagem individual e transmissão cultural).
- O conceito de que "pensar é um ato social" é fundamental, onde a cognição envolve representações de outras pessoas e o uso de artefatos culturais.
- A cultura tem um papel crucial na compreensão das capacidades de pensamento individuais.
- **Modelo Cultural de Axelrod (1997):** Indivíduos são vetores de características, organizados em uma grade com vizinhos. A interação com vizinhos é proporcional às características iguais, e o indivíduo "imita" características do vizinho em um processo de avaliar, comparar e imitar. Isso forma agrupamentos locais com características comuns.

---

### Auto-organização

- Mecanismos dinâmicos pelos quais múltiplos elementos estabelecem ordem sem imposição externa.
- **Ingredientes Principais:** Realimentação positiva e negativa, amplificação de perturbações e múltiplas interações.
- A capacidade coletiva aumenta, sendo o todo maior que a soma das partes.
- Regras simples, forte interação entre vizinhos e uso de informações locais são características.
- **Modelo de Craig Reynolds:** Observou o movimento sincronizado de bandos de pássaros e cardumes de peixes sem controle central, criando um modelo com quatro regras: Separação, Alinhamento, Coesão e Desvio de obstáculos.

---

### Particle Swarm Optimization (PSO)

- Técnica de otimização desenvolvida por Kennedy e Eberhart na década de 90, inspirada no comportamento social de revoadas de pássaros.
- Baseado no Modelo Cultural Adaptativo (ACM) de Axelrod: Avaliar, Comparar e Imitar.
- **Funcionamento:**
    - Mantém uma população de soluções (partículas), onde cada partícula é um vetor de números reais representando uma possível solução.
    - Cada partícula tem uma posição e uma velocidade.
    - A atualização de uma partícula é influenciada pela sua melhor experiência pessoal (`pbest`) e pela melhor experiência do grupo (`gbest`).
    - As partículas iterativamente atualizam sua velocidade e posição com base nessas informações, movendo-se em direção a uma combinação linear desses dois vetores.
    - É um processo auto-organizado, onde unidades simples cooperam para um objetivo comum através de comunicação intensa e interação com o ambiente.
    - A capacidade do enxame é uma qualidade emergente, e há ausência de controle centralizado.
- **Cálculo da Velocidade:** A velocidade de cada partícula é calculada considerando a velocidade anterior, a melhor posição pessoal (`pbest`) e a melhor posição do grupo (`gbest`), com pesos de inércia ($\omega$), parâmetros cognitivo ($c_1$) e social ($c_2$).
- **Pontos Positivos:** Simples, robusta, flexível, distribuída, baixas exigências de memória e processamento, rápida convergência.
- **Pontos Negativos:** Rápida perda de diversidade e convergência prematura a ótimos locais.
- **Aplicações:** Determinação de pesos e arquitetura de redes neurais artificiais, otimização de funções numéricas, análise de tremor humano, otimização de moinhos, controle de potência e tensão reativa, estimação de carregamento de baterias, composição musical, controle adaptativo baseado em Redes Neurais, configuração de antenas, aprendizado não-supervisionado de robôs, PSO em ambientes dinâmicos, engenharia (ajuste de sistemas de recomendação, modelagem de antenas, projeto de sistemas de controle e de circuitos VLSI), treinamento de redes neurais e neuro-fuzzy, inferência de redes gênicas, reconstrução de árvores filogenéticas e otimização de modelos biomecânicos.

---

### Comparação entre PSO e AG (Algoritmos Genéticos)

- Ambos possuem uma população de indivíduos e cálculo de `fitness`.
- Ambos não garantem a solução ótima global.
- O PSO não utiliza operadores de Crossover e Mutação; as partículas atualizam posições pela velocidade e possuem memória.
- O PSO não tem método de Seleção; toda a população participa.
- AG é para codificação discreta (adaptável), enquanto PSO é para codificação contínua (adaptável).
