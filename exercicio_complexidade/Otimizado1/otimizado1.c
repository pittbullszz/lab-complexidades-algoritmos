#include <stdio.h>
#include <time.h>
#include <stdlib.h>

long long *memo_table;

long long x_otimizado1(int n) {
    if (n <= 1) {
        return 1;
    }
    if (memo_table[n] != -1) {
        return memo_table[n];
    }
    memo_table[n] = x_otimizado1(n - 1) + x_otimizado1(n - 2);
    return memo_table[n];
}

int main() {
    int n_value;
    int N_Max = 1000;
    double total_time;

    printf("--- Algoritmo Otimizado 1 (Recursivo com Memoizacao) ---\n");
    printf("Digite o valor de n para testar: ");
    scanf("%d", &n_value);

    memo_table = (long long *)malloc((n_value + 1) * sizeof(long long));
    if (memo_table == NULL) {
        printf("Erro: Nao foi possivel alocar memoria para n=%d.\n", n_value);
        return 1;
    }

    total_time = 0;

    for (int i = 0; i < N_Max; i++) {
        for (int j = 0; j <= n_value; j++) {
            memo_table[j] = -1;
        }
        clock_t start = clock();
        x_otimizado1(n_value);
        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("Tempo medio para n=%d (Otimizado 1): %f segundos\n", n_value, total_time / N_Max);

    free(memo_table);
    return 0;
}
