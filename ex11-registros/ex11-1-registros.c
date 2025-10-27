#include <stdio.h>
#include <string.h>

#define TAM_NOME 256

struct Pessoa {
  char nome[TAM_NOME];
  double peso;
  double altura;
};

void lerStr(char str[], int tam);

int main() {
  struct Pessoa p;
  double imc;

  printf("Digite o seu nome: ");
  lerStr(p.nome, TAM_NOME);
  printf("Digite o seu peso: ");
  scanf("%lf", &p.peso);
  printf("Digite a sua altura: ");
  scanf("%lf", &p.altura);

  imc = p.peso / (p.altura * p.altura);

  printf("A pessoa %s com peso %.2f e altura %.2f tem IMC = %.2f\n",
    p.nome, p.peso, p.altura, imc);

  return 0;
}

void lerStr(char str[], int tam) {
  fgets(str, tam, stdin);
  int tamDigitado = strlen(str);
  if (str[tamDigitado - 1] == '\n') {
    str[tamDigitado - 1] = '\0';
  }
}