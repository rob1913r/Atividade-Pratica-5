#include <stdio.h>
#include <stdlib.h>

void initialize_matrix(int **A, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = i + j;
        }
    }
}

int sum_matrix(int **A, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += A[i][j];
        }
    }
    return sum;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <tamanho da matriz>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int **A = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
        A[i] = (int *)malloc(n * sizeof(int));
    }

    initialize_matrix(A, n);
    int result = sum_matrix(A, n);

    printf("Soma dos elementos: %d\n", result);

    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);

    return 0;
}
