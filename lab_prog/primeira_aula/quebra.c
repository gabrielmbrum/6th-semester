// gerado pelo deepseek

#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int N;
    scanf("%d", &N);  // Número de colunas (não usado diretamente)

    // Leitura da primeira linha de fichas
    int M1;
    scanf("%d", &M1);
    int *A = (int *)malloc(M1 * sizeof(int));
    for (int i = 0; i < M1; i++) {
        scanf("%d", &A[i]);
    }

    // Leitura da segunda linha de fichas
    int M2;
    scanf("%d", &M2);
    int *B = (int *)malloc(M2 * sizeof(int));
    for (int i = 0; i < M2; i++) {
        scanf("%d", &B[i]);
    }

    // Alocação da matriz DP
    int **dp = (int **)malloc((M1 + 1) * sizeof(int *));
    for (int i = 0; i <= M1; i++) {
        dp[i] = (int *)malloc((M2 + 1) * sizeof(int));
    }

    // Casos base
    for (int i = 0; i <= M1; i++) dp[i][0] = 0;
    for (int j = 0; j <= M2; j++) dp[0][j] = 0;

    // Preenchimento da matriz DP
    for (int i = 1; i <= M1; i++) {
        for (int j = 1; j <= M2; j++) {
            int op1 = dp[i - 1][j - 1] + A[i - 1] * B[j - 1];  // Emparelhar
            int op2 = dp[i - 1][j];                             // Ignorar ficha linha 1
            int op3 = dp[i][j - 1];                             // Ignorar ficha linha 2
            dp[i][j] = max(max(op1, op2), op3);
        }
    }

    // Resultado final
    printf("%d\n", dp[M1][M2]);

    // Liberação de memória
    free(A);
    free(B);
    for (int i = 0; i <= M1; i++) free(dp[i]);
    free(dp);

    return 0;
}