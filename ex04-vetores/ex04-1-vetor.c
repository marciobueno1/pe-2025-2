#include <stdio.h>

#define TAM 5

void preencherVetorDigitacao(int vetor[], int tam);
double calcularMediaVetor(int vetor[], int tam);
void imprimirValoresAcimaValor(int vetor[], int tam, double valor);

int main() {
  int numeros[TAM];
  preencherVetorDigitacao(numeros, TAM);
  double media = calcularMediaVetor(numeros, TAM);
  printf("A média dos números digitados é %.2f\n", media);
  printf("\nImpressão de todos os números acima da média\n");
  imprimirValoresAcimaValor(numeros, TAM, media);
  return 0;
}

void preencherVetorDigitacao(int vetor[], int tam) {
  for (int i = 0; i < tam; i += 1) {
    printf("Digite o %dº número inteiro: ", i + 1);
    scanf("%d", &vetor[i]);
  }
}

double calcularMediaVetor(int vetor[], int tam) {
  double soma = 0.0;
  for (int i = 0; i < TAM; i += 1) {
    soma += vetor[i];
  }
  return soma / TAM;
}

void imprimirValoresAcimaValor(int vetor[], int tam, double valor) {
  for (int i = 0; i < TAM; i += 1) {
    if (vetor[i] > valor) {
      printf("vetor[%d] = %d\n", i + 1, vetor[i]);
    }
  }
}
