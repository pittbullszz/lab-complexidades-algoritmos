#include <stdio.h>
#include <time.h>

long long x_otimizado2(int n) {
    if (n <= 1) {
        return 1;
    }

    long long a = 1;
    long long b = 1;
    long long next_val;

    for (int i = 2; i <= n; i++) {
        next_val = a + b;
        a = b;
        b = next_val;
    }
    return b;
}

int main() {
    int n_value;
    int N_Max = 1000;
    double total_time;

    printf("--- Algoritmo Otimizado 2 (Iterativo) ---\n");
    printf("Digite o valor de n para testar: ");
    scanf("%d", &n_value);

    total_time = 0;

    for (int i = 0; i < N_Max; i++) {
        clock_t start = clock();
        x_otimizado2(n_value);
        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("Tempo medio para n=%d (Otimizado 2): %f segundos\n", n_value, total_time / N_Max);

    return 0;
}
