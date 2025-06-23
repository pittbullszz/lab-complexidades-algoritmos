#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

long long x_otimizado3(int n) {
    if (n <= 1) {
        return 1;
    }

    double phi = (1 + sqrt(5)) / 2;
    double psi = (1 - sqrt(5)) / 2;

    return (long long)round((pow(phi, n + 1) - pow(psi, n + 1)) / sqrt(5));
}

int main() {
    int n_value;
    int N_Max = 1000;
    double total_time;

    printf("--- Algoritmo Otimizado 3 (Formula Fechada - Binet) ---\n");
    printf("Digite o valor de n para testar: ");
    scanf("%d", &n_value);

    total_time = 0;

    for (int i = 0; i < N_Max; i++) {
        clock_t start = clock();
        x_otimizado3(n_value);
        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("Tempo medio para n=%d (Otimizado 3): %f segundos\n", n_value, total_time / N_Max);

    return 0;
}
