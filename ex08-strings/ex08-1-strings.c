#include <stdio.h>
#include <string.h>

#define TAM_STR 5

void imprimirLetraPorLetra(char str[]);
void imprimirTabelaAscII(int naoImprimivel, int estendido);
void lerStr(char str[], int tam);

int main() {
  char frase[TAM_STR] = "Ola Turma!";
  printf("frase = '%s'\n\n", frase);
  imprimirLetraPorLetra(frase);
  printf("\n\n");
  imprimirTabelaAscII(1, 1);
  printf("\n\n");
  printf("Digite uma frase de até %d caracteres:\n", TAM_STR - 1);
  lerStr(frase, TAM_STR);
  printf("frase = -->%s<--\n\n", frase);
  printf("Digite uma frase de até %d caracteres:\n", TAM_STR - 1);
  lerStr(frase, TAM_STR);
  printf("frase = -->%s<--\n\n", frase);
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

void transformarMaiusculas(char str[]) {
  int difMaiusMinus = 'a' - 'A'; // mesmo que 32
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] = str[i] - difMaiusMinus;
    }
    i += 1;
  }
} 

void lerStr(char str[], int tam) {
  fgets(str, tam, stdin);
  int tamDigitado = strlen(str);
  if (str[tamDigitado - 1] == '\n') {
    str[tamDigitado - 1] = '\0';
  }
}