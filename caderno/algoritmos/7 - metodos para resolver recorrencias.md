** 08/04 - Projeto e Análise de Algoritmos - Métodos para Resolver Recorrências**

- Esta aula apresentou diferentes métodos para encontrar soluções (fórmulas fechadas ou limites assintóticos) para relações de recorrência, que são cruciais para analisar algoritmos recursivos. [24, 25, 26]

---

### Método Iterativo (Determinação pelos Primeiros Termos)

- **Ideia:** Calcular os primeiros termos da sequência definida pela recorrência, observar um padrão e formular uma hipótese para a fórmula fechada. [3]
- **Processo:**
    1. Calcular T(0), T(1), T(2), ... usando a definição da recorrência. [4]
    2. Reorganizar/simplificar os resultados para identificar um padrão em função de `n`. [4, 5]
    3. Formular uma hipótese para T(n). [7]
    4. **Provar a hipótese** usando indução matemática (base + passo indutivo). [9, 11]
- **Exemplo:** Para `T(n) = 2T(n-1)` com `T(0) = 5`, observou-se o padrão `T(n) = 5 * 2^n` e provou-se por indução. [2-13]

---

### Método da Expansão (Substituição)

- **Ideia:** Substituir repetidamente a definição da recorrência dentro dela mesma até que um padrão geral emerja, eventualmente chegando ao caso base. [15]
- **Processo:**
    1. Escrever `T(n)`.
    2. Substituir `T(n-1)` pela sua definição (`2T(n-2)` no exemplo). [16]
    3. Substituir `T(n-2)`, e assim por diante, algumas vezes. [16]
    4. Identificar a fórmula geral após `k` substituições (ex: `T(n) = 2^k * T(n-k)`). [17]
    5. Determinar o valor de `k` necessário para atingir o caso base (ex: `n-k = 0 => k = n`). [18]
    6. Substituir `k` e o valor do caso base na fórmula geral (ex: `T(n) = 2^n * T(0) = 2^n * 5`). [19]
    7. Opcional/Recomendado: Provar a fórmula resultante por indução. [21]
- **Exemplo:** O mesmo `T(n) = 2T(n-1)` com `T(0) = 5` foi resolvido, chegando a `T(n) = 5 * 2^n`. [14-22]

---

### Método do Palpite Inteligente (Para Limites Assintóticos)

- **Ideia:** Usado principalmente para encontrar limites assintóticos (O, Ω, Θ) justos, especialmente quando a recorrência envolve desigualdades ou é complexa para uma solução exata. [27, 30, 31, 32]
- **Processo:**
    1. Fazer um "palpite" (hipótese) sobre o limite assintótico (ex: `T(n) = O(n²)`).
    2. Tentar provar o palpite usando indução matemática.
    3. Se a prova falhar ou se o limite parecer muito "frouxo" (não justo), refinar o palpite (para mais ou para menos) e tentar provar novamente. [42, 43, 47]
- **Exemplo:** Para `T(n) <= 2T(n/2) + 2n - 1` com `T(2)=1`: [29]
    - Palpite `O(n²)`: Provado, mas pareceu frouxo. [33-42]
    - Palpite `O(n)`: Falhou na prova. [43-46]
    - Palpite `O(n log n)`: Provado com sucesso, mostrando ser um limite mais justo. [48-52]

---

### Teorema Mestre

- **Ideia:** Um método "receita de bolo" para resolver recorrências da forma `T(n) = a * T(n/b) + f(n)`, onde `a >= 1`, `b > 1` são constantes e `f(n)` é assintoticamente positiva. [53]
- **Processo:** Compara-se `f(n)` com `n^(log_b a)`:
    - **Caso 1:** Se `f(n)` for polinomialmente **menor** que `n^(log_b a)` (por um fator de `n^ε`), então `T(n) = Θ(n^(log_b a))`. [55]
    - **Caso 2:** Se `f(n)` tiver a **mesma ordem** de crescimento que `n^(log_b a)` (`f(n) = Θ(n^(log_b a))`), então `T(n) = Θ(n^(log_b a) * log n)`. [56]
    - **Caso 3:** Se `f(n)` for polinomialmente **maior** que `n^(log_b a)` (por um fator de `n^ε`) **E** satisfizer a **condição de regularidade** (`a * f(n/b) <= c * f(n)` para `c < 1`), então `T(n) = Θ(f(n))`. [58]
- **Exemplos Resolvidos:**
    - `T(n) = 9T(n/3) + n`: Caso 1 => `Θ(n²)`. [59-63]
    - `T(n) = T(2n/3) + 1`: Caso 2 => `Θ(log n)`. [64-70]
    - `T(n) = 3T(n/4) + n log n`: Caso 3 => `Θ(n log n)`. [71-81]
    - `T(n) = T(n/3) + n`: Caso 3 => `Θ(n)`. [82-93]

---

**Conclusão:**

A aula apresentou quatro métodos principais para resolver relações de recorrência: dois métodos focados em encontrar fórmulas exatas (Iterativo e Expansão) e dois focados em limites assintóticos ou soluções para formas específicas (Palpite Inteligente e Teorema Mestre). A escolha do método depende do tipo de recorrência e do objetivo (solução exata vs. limite assintótico).
