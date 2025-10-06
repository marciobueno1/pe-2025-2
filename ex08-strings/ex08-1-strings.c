#include <stdio.h>
#include <string.h>

void imprimirLetraPorLetra(char str[]);
void imprimirTabelaAscII(int naoImprimivel, int estendido);

int main() {
  char frase[50] = "Ola Turma!";
  printf("frase = '%s'\n\n", frase);
  imprimirLetraPorLetra(frase);
  printf("\n\n");
  imprimirTabelaAscII(1, 1);
  printf("\n\n");
  return 0;
}

void imprimirLetraPorLetra(char str[]) {
  int tam = strlen(str);
  for (int i = 0; i < tam; i += 1) {
    printf("'%c' %3d\n", str[i], str[i]);
  }
}

void imprimirTabelaAscII(int naoImprimivel, int estendido) {
  int inicio = 32, fim = 127;
  if (naoImprimivel) {
    inicio = 0;
  }
  if (estendido) {
    fim = 255;
  }
  for (int i = inicio; i <= fim; i += 1) {
    printf("%3d '%c'\n", i, i);
  }
}
