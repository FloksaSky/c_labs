#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int* CreateMatirx(int n, int m) {
    int* matrix = (int*)calloc(n*m, sizeof(int));
    for (int i = 0; i < n * m; ++i) {
        matrix[i] = rand() % 10 + 1;
    }
    return matrix;
}
 
int* TransposedCopy(int* matrix, int n, int m) {
    int* transposed = (int*)calloc(m * n, sizeof(int));
    for (int k = 0; k < n * m; ++k) {
        int i = k / m;
        int j = k % m;
        transposed[j * n + i] = matrix[i * m + j];
    }
    return transposed;
}
 
int* Multyply(int* transposed, int* matrix, int n, int m) {
    int* multyplied = (int*)calloc(m * m, sizeof(int));
    for (int k = 0; k < m * m; ++k) {
        int i = k / m;
        int j = k % m;
        multyplied[i * m + j] = 0;
        for (int v = 0; v < n; ++v) {
            multyplied[i * m + j] += transposed[i * n + v] * matrix[v * m + j];
        }
    }
    return multyplied;
}
 
void PrintMatrix(int* matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%5d", matrix[i * m + j]);
        }
        printf("\n");
    }
    printf("\n");
}
 
int main()
{
    srand(time(NULL));
    int n;
    int m;
    printf("Insert n and m\n");
    scanf("%d%d", &n, &m);
    int* matrix = CreateMatirx(n, m);
    int* transposed = TransposedCopy(matrix, n, m);
    int* multyplied = Multyply(transposed, matrix, n, m);
    PrintMatrix(matrix, n, m);
    PrintMatrix(transposed, m, n);
    PrintMatrix(multyplied, m, m);
    free(matrix);
    free(transposed);
    free(multyplied);
}