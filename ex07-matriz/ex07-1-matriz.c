#include <stdio.h>

#define QTD_LINHAS_1 2
#define QTD_COLUNAS_1 3
#define QTD_LINHAS_2 3
#define QTD_COLUNAS_2 4

void preencherMatrizDigitacao1(int matriz[][QTD_COLUNAS_1], int qtdLinhas, int qtdColunas);
void imprimirMatriz1(int m[][QTD_COLUNAS_1], int qtdLinhas, int qtdColunas);
void preencherMatrizDigitacao2(int matriz[][QTD_COLUNAS_2], int qtdLinhas, int qtdColunas);
void imprimirMatriz2(int m[][QTD_COLUNAS_2], int qtdLinhas, int qtdColunas);
void multiplicacao(
  int a[QTD_LINHAS_1][QTD_COLUNAS_1],
  int b[QTD_LINHAS_2][QTD_COLUNAS_2],
  int mult[QTD_LINHAS_1][QTD_COLUNAS_2]
);
void transposta(int a[QTD_LINHAS_2][QTD_COLUNAS_2], int at[QTD_COLUNAS_2][QTD_LINHAS_2]);

int main() {
  int a[QTD_LINHAS_1][QTD_COLUNAS_1], b[QTD_LINHAS_2][QTD_COLUNAS_2];
  int bt[QTD_COLUNAS_2][QTD_LINHAS_2];
  int mult[QTD_LINHAS_1][QTD_COLUNAS_2];
  printf("Preenchimento da matriz A\n");
  preencherMatrizDigitacao1(a, QTD_LINHAS_1, QTD_COLUNAS_1);

  printf("Preenchimento da matriz B\n");
  preencherMatrizDigitacao2(b, QTD_LINHAS_2, QTD_COLUNAS_2);

  printf("\nImpressão da Matriz A\n");
  imprimirMatriz1(a, QTD_LINHAS_1, QTD_COLUNAS_1);

  printf("\nImpressão da Matriz B\n");
  imprimirMatriz2(b, QTD_LINHAS_2, QTD_COLUNAS_2);

  transposta(b, bt);
  printf("\nImpressão da Matriz A transposta\n");
  imprimirMatriz1(bt, QTD_COLUNAS_2, QTD_LINHAS_2);

  multiplicacao(a, b, mult);
  printf("\nImpressão da Matriz Multiplicação\n");
  imprimirMatriz2(mult, QTD_LINHAS_1, QTD_COLUNAS_2);

  return 0;
}

void preencherMatrizDigitacao1(int m[][QTD_COLUNAS_1], int qtdLinhas, int qtdColunas) {
  for (int l = 0; l < qtdLinhas; l += 1) {
    for (int c = 0; c < qtdColunas; c += 1) {
      printf("Digite valor da posição (%d, %d): \n", l + 1, c + 1);
      scanf("%d", &m[l][c]);
    }
  }
}

void preencherMatrizDigitacao2(int m[][QTD_COLUNAS_2], int qtdLinhas, int qtdColunas) {
  for (int l = 0; l < qtdLinhas; l += 1) {
    for (int c = 0; c < qtdColunas; c += 1) {
      printf("Digite valor da posição (%d, %d): \n", l + 1, c + 1);
      scanf("%d", &m[l][c]);
    }
  }
}

void imprimirMatriz1(int m[][QTD_COLUNAS_1], int qtdLinhas, int qtdColunas) {
  for (int l = 0; l < qtdLinhas; l += 1) {
    for (int c = 0; c < qtdColunas; c += 1) {
      printf("%2d ", m[l][c]);
    }
    printf("\n");
  }
}

void imprimirMatriz2(int m[][QTD_COLUNAS_2], int qtdLinhas, int qtdColunas) {
  for (int l = 0; l < qtdLinhas; l += 1) {
    for (int c = 0; c < qtdColunas; c += 1) {
      printf("%2d ", m[l][c]);
    }
    printf("\n");
  }
}

void multiplicacao(
  int a[QTD_LINHAS_1][QTD_COLUNAS_1],
  int b[QTD_LINHAS_2][QTD_COLUNAS_2],
  int mult[QTD_LINHAS_1][QTD_COLUNAS_2]
) {
  for (int i = 0; i < QTD_LINHAS_1; i += 1) {
    for (int j = 0; j < QTD_COLUNAS_2; j += 1) {
      mult[i][j] = 0;
      for (int k = 0; k < QTD_COLUNAS_1; k += 1) {
        mult[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}

void transposta(int a[QTD_LINHAS_2][QTD_COLUNAS_2], int at[QTD_COLUNAS_2][QTD_LINHAS_2]) {
  for (int i = 0; i < QTD_LINHAS_2; i += 1) {
    for (int j = 0; j < QTD_COLUNAS_2; j += 1) {
      at[j][i] = a[i][j];
    }
  }
}