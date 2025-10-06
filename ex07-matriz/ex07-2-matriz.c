#include <stdio.h>

#define ORDEM_MATRIZ 4

#define QTD_LINHAS_1 2
#define QTD_COLUNAS_1 3
#define QTD_LINHAS_2 3
#define QTD_COLUNAS_2 4

void preencherMatrizDigitacao(int m[][ORDEM_MATRIZ], int qtdLinhas, int qtdColunas);
void imprimirMatriz(int m[][ORDEM_MATRIZ], int qtdLinhas, int qtdColunas);
void multiplicacao(
  int a[][ORDEM_MATRIZ], int qtdLinhasA, int qtdColunasA,
  int b[][ORDEM_MATRIZ], int qtdLinhasB, int qtdColunasB,
  int mult[][ORDEM_MATRIZ]
);
void transposta(int a[][ORDEM_MATRIZ], int qtdLinhas, int qtdColunas, int at[][ORDEM_MATRIZ]);

int main() {
  int a[ORDEM_MATRIZ][ORDEM_MATRIZ], b[ORDEM_MATRIZ][ORDEM_MATRIZ];
  int at[ORDEM_MATRIZ][ORDEM_MATRIZ], bt[ORDEM_MATRIZ][ORDEM_MATRIZ];
  int mult[ORDEM_MATRIZ][ORDEM_MATRIZ];

  printf("Preenchimento da matriz A\n");
  preencherMatrizDigitacao(a, QTD_LINHAS_1, QTD_COLUNAS_1);

  printf("Preenchimento da matriz B\n");
  preencherMatrizDigitacao(b, QTD_LINHAS_2, QTD_COLUNAS_2);

  printf("\nImpressão da Matriz A\n");
  imprimirMatriz(a, QTD_LINHAS_1, QTD_COLUNAS_1);

  transposta(a, QTD_LINHAS_1, QTD_COLUNAS_1, at);
  printf("\nImpressão da Matriz A transposta\n");
  imprimirMatriz(at, QTD_COLUNAS_1, QTD_LINHAS_1);

  printf("\nImpressão da Matriz B\n");
  imprimirMatriz(b, QTD_LINHAS_2, QTD_COLUNAS_2);

  transposta(b, QTD_LINHAS_2, QTD_COLUNAS_2, bt);
  printf("\nImpressão da Matriz B transposta\n");
  imprimirMatriz(bt, QTD_COLUNAS_2, QTD_LINHAS_2);

  multiplicacao(a, QTD_LINHAS_1, QTD_COLUNAS_1, b, QTD_LINHAS_2, QTD_COLUNAS_2, mult);
  printf("\nImpressão da Matriz Multiplicação\n");
  imprimirMatriz(mult, QTD_LINHAS_1, QTD_COLUNAS_2);

  return 0;
}

void preencherMatrizDigitacao(int m[][ORDEM_MATRIZ], int qtdLinhas, int qtdColunas) {
  for (int l = 0; l < qtdLinhas; l += 1) {
    for (int c = 0; c < qtdColunas; c += 1) {
      printf("Digite valor da posição (%d, %d): \n", l + 1, c + 1);
      scanf("%d", &m[l][c]);
    }
  }
}

void imprimirMatriz(int m[][ORDEM_MATRIZ], int qtdLinhas, int qtdColunas) {
  for (int l = 0; l < qtdLinhas; l += 1) {
    for (int c = 0; c < qtdColunas; c += 1) {
      printf("%2d ", m[l][c]);
    }
    printf("\n");
  }
}

void multiplicacao(
  int a[][ORDEM_MATRIZ], int qtdLinhasA, int qtdColunasA,
  int b[][ORDEM_MATRIZ], int qtdLinhasB, int qtdColunasB,
  int mult[][ORDEM_MATRIZ]
) {
  if (qtdColunasA != qtdLinhasB) {
    printf("Não é possível multiplicar essas duas matrizes!");
    return;
  }

  for (int i = 0; i < qtdLinhasA; i += 1) {
    for (int j = 0; j < qtdColunasB; j += 1) {
      mult[i][j] = 0;
      for (int k = 0; k < qtdColunasA; k += 1) {
        mult[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}

void transposta(int a[][ORDEM_MATRIZ], int qtdLinhas, int qtdColunas, int at[][ORDEM_MATRIZ]) {
  for (int i = 0; i < qtdLinhas; i += 1) {
    for (int j = 0; j < qtdColunas; j += 1) {
      at[j][i] = a[i][j];
    }
  }
}