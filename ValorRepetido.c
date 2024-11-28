#include <stdio.h>
#include <stdlib.h>

#define LINHAS 30
#define COLUNAS 20

void inicializarMatriz(int matriz[LINHAS][COLUNAS]) {
    int elementos[3][COLUNAS] = {
        {4, 17, 23, 48, 36, 17, 52, 67, 89, 48, 29, 14, 75, 83, 38, 56, 17, 91, 64, 71},
        {17, 48, 23, 48, 36, 52, 67, 89, 75, 38, 14, 29, 91, 56, 48, 64, 17, 89, 75, 29},
        {48, 4, 67, 17, 91, 29, 64, 52, 75, 89, 36, 56, 48, 14, 17, 23, 48, 67, 17, 91},
    };

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            matriz[i][j] = elementos[i % 3][j];
        }
    }
}

void exibirMatriz(int matriz[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int contarRepetidos(int array[], int tamanho) {
    int contagem[101] = {0};
    int totalRepetidos = 0;

    for (int i = 0; i < tamanho; i++) {
        contagem[array[i]]++;
    }

    for (int i = 1; i <= 100; i++) {
        if (contagem[i] > 1) {
            totalRepetidos += contagem[i] - 1;
        }
    }

    return totalRepetidos;
}

void identificarMaisRepetidos(int matriz[LINHAS][COLUNAS]) {
    int maxRepetidos = -1;
    int indice = -1;
    char orientacao = 'L';

    for (int i = 0; i < LINHAS; i++) {
        int repetidos = contarRepetidos(matriz[i], COLUNAS);
        if (repetidos > maxRepetidos) {
            maxRepetidos = repetidos;
            indice = i;
            orientacao = 'L';
        }
    }

    for (int j = 0; j < COLUNAS; j++) {
        int coluna[LINHAS];
        for (int i = 0; i < LINHAS; i++) {
            coluna[i] = matriz[i][j];
        }
        int repetidos = contarRepetidos(coluna, LINHAS);
        if (repetidos > maxRepetidos) {
            maxRepetidos = repetidos;
            indice = j;
            orientacao = 'C';
        }
    }

    if (orientacao == 'L') {
        printf("A linha com mais números repetidos é: %d\n", indice);
    } else {
        printf("A coluna com mais números repetidos é: %d\n", indice);
    }
}

int main() {
    int matriz[LINHAS][COLUNAS];

    inicializarMatriz(matriz);

    printf("Matriz:\n");
    exibirMatriz(matriz);

    identificarMaisRepetidos(matriz);

    return 0;
}