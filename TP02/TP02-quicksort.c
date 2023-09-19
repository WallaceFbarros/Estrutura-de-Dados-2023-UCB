#include <stdio.h>
#include <string.h>

void troca(char *arr[], int i, int j) {
    char *temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int dividirArray(char *arr[], int menor, int maior) {
    char *pivot = arr[maior];
    int i = menor - 1;

    for (int j = menor; j < maior; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            troca(arr, i, j);
        }
    }

    troca(arr, i + 1, maior);
    return i + 1;
}

void quicksort(char *arr[], int menor, int maior, int *comparacoes, int *trocas) {
    if (menor < maior) {
        int pivotIndex = dividirArray(arr, menor, maior);
        quicksort(arr, menor, pivotIndex - 1, comparacoes, trocas);
        quicksort(arr, pivotIndex + 1, maior, comparacoes, trocas);
        (*comparacoes) += (maior - menor);
        (*trocas) += (maior - menor);
    }
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limão", "manga", "abacate", "kiwi",
        "cereja", "morango", "pêssego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };

    int comparacoes = 0;
    int trocas = 0;
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, tamanho - 1, &comparacoes, &trocas);

    printf("Vetor Ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("(%d) %s\n", i+1,arr[i]);
    }

    printf("\nNúmero de comparações: %d\n", comparacoes);
    printf("Número de trocas: %d\n", trocas);

    // Mediana
    char *mediana = arr[tamanho / 2];
    printf("Mediana: %s\n", mediana);

    // Gerar arquivo de saída
    FILE *outputFile;
    outputFile = fopen("saida.txt", "w");

    fprintf(outputFile, "Vetor Ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        fprintf(outputFile, "(%d) %s\n", i+1,arr[i]);
    }

    fprintf(outputFile, "\nNúmero de comparações: %d\n", comparacoes);
    fprintf(outputFile, "Número de trocas: %d\n", trocas);
    fprintf(outputFile, "Mediana: %s\n", mediana);

    fclose(outputFile);

    return 0;
}
