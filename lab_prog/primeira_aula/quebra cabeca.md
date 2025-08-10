
## resumo do problema

1. **Tabuleiro**: 2 linhas × N colunas.
2. **Fichas**: Cada linha tem M fichas (M ≤ N) que não podem mudar sua ordem relativa.
3. **Movimento**: Fichas podem deslizar para células vazias adjacentes (esquerda/direita), mas não podem pular outras fichas.
4. **Objetivo**: Maximizar a soma dos produtos das fichas alinhadas verticalmente.

## por que é de programação dinâmica (PD)?

- **Subproblemas sobrepostos**: O valor máximo para uma coluna depende das escolhas nas colunas anteriores.
- **Otimização**: PD evita recálculos desnecessários armazenando resultados intermediários.

## abordagem

1. **Defina os estados**:
	- `dp[i][j][k]`: Valor máximo considerando as primeiras `i` fichas da linha 1, `j` fichas da linha 2, e `k` colunas já processadas.
    - **Restrições**:
        - `i` e `j` não podem ultrapassar o número de fichas em suas linhas.
        - A diferença entre as posições das fichas deve respeitar as regras de movimento.
            
2. **Transição de estados**:
	- Para cada coluna `k`, decida se:
		- Alinha a ficha atual da linha 1 com a da linha 2 (se possível).
		- Move uma ficha para a esquerda/direita (respeitando as regras).
            
3. **Casos base**:
    - `dp[0][0][0] = 0` (nenhuma ficha alinhada).
    - Se uma linha acabar suas fichas, continue com zeros para o restante.
        
4. **Complexidade**: O(N³) devido aos três loops aninhados (linha 1, linha 2, colunas).

## caminho pra resolução

1. **Reformulação do Problema**:
    - O problema equivale a encontrar o emparelhamento máximo entre as fichas das duas linhas, preservando a ordem.
        
    - Cada par de fichas (uma de cada linha) contribui com o produto de seus valores.
        
    - Fichas não pareadas não contribuem para a soma.
2. **Definição do Estado de PD**:
    - `dp[i][j]`: valor máximo possível considerando as primeiras `i` fichas da primeira linha e as primeiras `j` fichas da segunda linha.
3. **Transições de Estado**:
    - **Caso 1**: Emparelhar a ficha `i` da primeira linha com a ficha `j` da segunda linha.
        - Contribuição: `valor = A[i-1] * B[j-1]`
        - Estado anterior: `dp[i-1][j-1]`
            
    - **Caso 2**: Ignorar a ficha `i` da primeira linha.
        - Estado anterior: `dp[i-1][j]`
            
    - **Caso 3**: Ignorar a ficha `j` da segunda linha.
        - Estado anterior: `dp[i][j-1]`
            
    - A transição completa:
        ```c
	dp[i][j] = max(
		dp[i-1][j-1] + A[i-1] * B[j-1],  // Emparelhar
		dp[i-1][j],                       // Ignorar ficha da linha 1
		dp[i][j-1]                        // Ignorar ficha da linha 2
	);
        ```
        
4. **Casos Base**
    - `dp[0][j] = 0` para todo `j` (nenhuma ficha da primeira linha processada)
    - `dp[i][0] = 0` para todo `i` (nenhuma ficha da segunda linha processada)
        
5. **Complexidade**:
    - O(M1 * M2), onde M1 e M2 são as quantidades de fichas em cada linha.
    - Como M1, M2 ≤ N ≤ 500, a complexidade máxima é 500² = 250,000 operações, que é eficiente.

---
### **Onde Estudar Programação Dinâmica**

1. **Livros**:
    - _Introduction to Algorithms_ (Cormen) - Capítulo 15.
    - _Competitive Programming 3_ (Halim) - Seção sobre PD.
        
2. **Cursos Online**:    
    - [Coursera: Algoritmos Especializados (UC San Diego)](https://www.coursera.org/learn/algorithms-part2)
    - [YouTube: Programação Dinâmica (CS50)](https://youtu.be/ENyox7kNKeY).
        
3. **Problemas Práticos** (do fácil ao difícil):
    - **Fácil**: Fibonacci, Coin Change.
    - **Intermediário**: Knapsack, Longest Common Subsequence.
    - **Difícil**: Edit Distance, Matrix Chain Multiplication.x'