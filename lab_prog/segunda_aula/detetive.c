#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct 
}

void printMatrix(int **mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int E, I, V;
    int **mat;
    int *vdd;
    int *raizes;
    
    scanf("%d %d %d", &E, &I, &V);

    mat = (int **)malloc(I * sizeof(int *));
    for (int i = 0; i < I; i++) {
        mat[i] = (int *)malloc(2 * sizeof(int));
    }

    vdd = (int *)malloc(V * sizeof(int));

    int qtd_raizes = 0;
    for (int i = 0; i < I; i++) {
        scanf("%d %d", &mat[i][0], &mat[i][1]);
        raizes[qtd_raizes++] = mat[i][0];
    }

    for (int i = 0; i < V; i++) {
        scanf("%d", &vdd[i]);
    }


    raizes = (int *)malloc(E * sizeof(int));
    for (int i = 0; i < I; i++) {
        raizes[qtd_raizes++] = mat[i][0];
    }

    printf("Matrix:\n");
    printMatrix(mat, I, 2);
    
    printf("Vector:\n");
    for (int i = 0; i < V; i++) {
        printf("%d ", vdd[i]);
    }
    printf("\n");

    return 0;
}
