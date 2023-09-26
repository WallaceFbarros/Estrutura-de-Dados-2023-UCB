#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "ponto.h"

int main() {
    setlocale(LC_ALL, "Portuguese");

    FILE *arquivoEntrada;
    arquivoEntrada = fopen("./vertices.txt", "r");

    if (arquivoEntrada == NULL) {
        printf("\nErro ao abrir o arquivo\n");
        return 1;
    }
    printf("Arquivo aberto com sucesso\n");

    int numPoligonos = 0;

while (1) {
    int qtdPontos;
    if (fscanf(arquivoEntrada, "%d", &qtdPontos) == EOF) {
        break; // Termina se chegou ao final do arquivo
    }

    Ponto *poligono = malloc(qtdPontos * sizeof(Ponto));

    if (poligono == NULL) {
        printf("\nErro ao alocar memória para o polígono\n");
        fclose(arquivoEntrada);
        return 1;
    }

    // Lê as coordenadas dos vértices até encontrar os valores de sentinela
int i = 0;
while (1) {
    if (fscanf(arquivoEntrada, "%f %f", &poligono[i].x, &poligono[i].y) != 2) {
        printf("\nErro ao ler as coordenadas do polígono %d\n", numPoligonos + 1);
        free(poligono);
        fclose(arquivoEntrada);
        return 1;
    }
    // Verifique se os valores de sentinela foram alcançados
    if (poligono[i].x == -1 && poligono[i].y == -1) {
        break; // Polígono terminou
    }
    i++;
}

    // Calcula a área do polígono
    float area = calcularAreaPoligono(poligono);

    // Imprime a área do polígono no formato desejado
    printf("A área do polígono %d é %.0f\n", numPoligonos + 1, area);

    // Libera a memória alocada para o polígono
    free(poligono);

    numPoligonos++;
}

    fclose(arquivoEntrada);

    return 0;
}
