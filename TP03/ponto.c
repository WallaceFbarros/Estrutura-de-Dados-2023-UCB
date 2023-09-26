#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ponto.h"

Ponto criaPonto(float x, float y){
    Ponto vertice;
    vertice.x = x;
    vertice.y = y;
    return vertice;
}

void mostraPonto(Ponto vertice){
    printf("\nPonto(%.2f,%.2f)\n",vertice.x,vertice.y);
}

float calcularAreaTriangulo(Ponto a, Ponto b, Ponto c){
    float area, determinante;

    determinante = (a.x*b.y)+(a.y*c.x)+(b.x*c.y)-(c.x*b.y)-(c.y*a.x)-(b.x*a.y);


    if(determinante < 0){
        area = (-1*(determinante))/2;
    }else{
        area = determinante/2;
    }

    return area;
}

float calcularAreaPoligono(Ponto vetor[]){
    
    int i=0,qtdPontos=0;
    float area=0;

    while(vetor[i].x != 847362 && vetor[i].y != 382764){
        qtdPontos++;
        i++;
    }

    for(int i = 0; i < (qtdPontos-2); i++){
        area += calcularAreaTriangulo(vetor[0],vetor[i+1],vetor[i+2]);
    }

    return area;

}