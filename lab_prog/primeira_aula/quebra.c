// link => https://olimpiada.ic.unicamp.br/pratique/p2/2020/f2/quebra/#

#include <stdio.h>
#include <stdlib.h>

void print_vector(int *v, int n) {
	for (int i = 0; i < n; i++) {
		printf("v[%d] = %d\n", i, v[i]);
	}
	printf("\n");
}

int main () {
	// N = number of pieces, M1 = number of pieces in the first set, M2 = number of pieces in the second set
	// quebra_cabeca = array to store the pieces
	int N, M1, M2;
	int *quebra_cabeca;

	// reading the input
	scanf("%d", &N);

	quebra_cabeca = (int *) malloc(N * 2 * sizeof(int));
	
	scanf("%d", &M1);

	for (int i = 0; i < M1; i++) {
		scanf("%d", &quebra_cabeca[i]);
	}
	for (int i = M1; i < N; i++) {
		quebra_cabeca[i] = 0;
	}

	scanf("%d", &M2);

	for (int i = 0; i < M2; i++) {
		scanf("%d", &quebra_cabeca[N + i]);
	}
	for (int i = M2; i < N; i++) {
		quebra_cabeca[N + i] = 0;
	}

	print_vector(quebra_cabeca, N*2);
	
	free(quebra_cabeca);

	return 0;
}
