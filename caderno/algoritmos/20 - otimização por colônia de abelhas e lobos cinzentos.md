**01/07 - Projeto e Análise de Algoritmos - Otimização por Colônia de Abelhas e Lobos Cinzentos**

Esta aula explora mais duas meta-heurísticas bioinspiradas: a Otimização por Colônia Artificial de Abelhas (ABC) e o Algoritmo do Otimizador por Lobos Cinzentos (GWO).

---

### Comunicação entre Abelhas

- A comunicação é fundamental para a formação da inteligência coletiva em abelhas.
- **Formas de Comunicação:** Dança (waggle dance), sons, emissão de substâncias químicas (feromônios), tato e estímulos eletromagnéticos.
- **Dança (Waggle Dance):** Atua como uma "bússola solar" e transmite informações cruciais para a colônia:
    - **Direção da fonte de alimento:** Ângulo entre o sol e o caminho da dança.
    - **Distância da colmeia até a fonte:** Duração da dança.
    - **Qualidade da fonte:** Frequência da dança.
- **Categorias de Algoritmos Inspirados em Abelhas:** Comportamento de coleta de alimentos (mais comum, ex: ABC), comportamentos de acasalamento e o conceito de abelha rainha.

---

### Colônia Artificial de Abelhas (ABC)

- **Criação:** Algoritmo desenvolvido por Dervis Karaboga em 2005 e formalizado em 2007.
- **Meta-heurística:** Um método populacional inspirado no comportamento coletivo de uma colônia de abelhas.
- **Base:** Simula o comportamento das abelhas na busca por alimento.
- **Tipos de Abelhas:**
    - **Abelhas Empregadas (Employed Bees):** Exploradoras atuais, carregam informação sobre uma fonte de alimento específica.
    - **Abelhas Observadoras (Onlooker Bees):** Escolhem uma fonte de alimento para explorar com base nas informações compartilhadas pelas abelhas empregadas.
    - **Abelhas Escoteiras (Scout Bees):** Procuram aleatoriamente por novas fontes de alimento quando uma fonte existente é abandonada (geralmente por esgotamento ou má qualidade).
- **Processo do ABC:**
    1. **Inicialização:** Fontes de alimento são geradas aleatoriamente (soluções iniciais).
    2. **Fase da Abelha Empregada:** Abelhas empregadas exploram as fontes atuais, procuram por vizinhos e avaliam a qualidade.
    3. **Fase da Abelha Observadora:** Abelhas observadoras selecionam fontes de alimento com base na probabilidade de sucesso e as exploram.
    4. **Fase da Abelha Escoteira:** Se uma fonte não melhora após um certo número de iterações, a abelha empregada se torna uma escoteira e busca uma nova fonte aleatoriamente.
    5. **Seleção:** A melhor solução é memorizada e o processo se repete até o critério de parada.
- **Vantagens:** Eficiente na busca por ótimos globais, boa para problemas de otimização contínua.
- **Desvantagens:** Pode ter convergência lenta em problemas de alta dimensão, e o desempenho depende da calibração de parâmetros.

---

### Algoritmo do Otimizador por Lobos Cinzentos (GWO)

- **Inspiração:** Baseado no comportamento de caça dos lobos cinzentos na natureza.
- **Estrutura Social:** Os lobos cinzentos têm uma hierarquia social rigorosa:
    - **Alpha ($\alpha$):** O líder (melhor solução).
    - **Beta ($\beta$):** Segundo na hierarquia (segunda melhor solução).
    - **Delta ($\delta$):** Terceiro na hierarquia (terceira melhor solução).
    - **Ômega ($\omega$):** Lobos de baixo escalão, os seguidores (as demais soluções).
- **Fases da Caça:**
    1. **Circundando a presa:** Os lobos circundam a presa, e esse comportamento é modelado matematicamente com base nas posições dos lobos alpha, beta e delta.
    2. **Caçando (Exploração/Explotação):** Os lobos ômega atualizam suas posições com base nas informações dos líderes ($\alpha$, $\beta$, $\delta$), que têm o melhor conhecimento sobre a localização da presa.
    3. **Atacar a presa (Exploração):** O ataque ocorre quando a presa para de se mover. Matematicamente, isso é modelado pela diminuição de um valor de parâmetro, que controla a distância de exploração.
- **Vantagens:** Boa capacidade de exploração e explotação, fácil de implementar.
- **Desvantagens:** Pode convergir prematuramente em ótimos locais, sensível à inicialização da população.
