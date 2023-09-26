typedef struct{
    float x;
    float y;
} Ponto;

Ponto criarPonto(float x, float y);
void mostrarPonto (Ponto p);
float calcularAreaTriangulo(Ponto x, Ponto y, Ponto z);
float calcularAreaPoligono(Ponto vetor[]);

