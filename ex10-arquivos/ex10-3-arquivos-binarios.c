#include <stdio.h>
#include <string.h>

#define TAM 256

void lerStr(char str[], int tam);
void inserirFinalArquivo(char nomeArq[]);
void listarArquivo(char nomeArq[]);
void lerPosicaoEspecifica(char nomeArq[]);

int main() {
  char nomeArq[TAM];
  int opcao;
  printf("Digite o nome do arquivo: ");
  lerStr(nomeArq, TAM);
  while(strlen(nomeArq) == 0) {
    printf("Nome vazio é inválido!\n");
    printf("Digite o nome do arquivo: ");
    lerStr(nomeArq, TAM);
  }
  do {
    printf("\n\nMENU\n");
    printf("1 - Gravar um número no final do arquivo\n");
    printf("2 - Listar o conteúdo do arquivo\n");
    printf("3 - Imprimir valor específico\n");
    printf("Digite a sua opção (0 p/ finalizar): ");
    scanf("%d", &opcao);
    switch (opcao) {
      case 1:
        inserirFinalArquivo(nomeArq);
        break;
      case 2:
        printf("---------------- Listagem ----------------\n");
        listarArquivo(nomeArq);
        printf("------------------------------------------\n");
        break;
      case 3:
        lerPosicaoEspecifica(nomeArq);
        break;
      default:
        if (opcao != 0) {
          printf("Opção inválida!\n");
        }
      }
  } while (opcao != 0);
  return 0;
}

void lerStr(char str[], int tam) {
  fgets(str, tam, stdin);
  int tamDigitado = strlen(str);
  if (str[tamDigitado - 1] == '\n') {
    str[tamDigitado - 1] = '\0';
  }
}

void inserirFinalArquivo(char nomeArq[]) {
  int status;
  double num;
  FILE *arq = fopen(nomeArq, "ab");
  if (arq == NULL) {
    printf("Não pode abrir o arquivo!\n");
    return;
  }
  printf("Digite um número real: ");
  scanf("%lf", &num);
  status = fwrite(&num, sizeof(double), 1, arq);
  if (status == 1) {
    printf("Valor armazenado com sucesso!\n");
  } else {
    printf("Erro ao gravar o valor no arquivo!\n");
  }
  fclose(arq);
}

void listarArquivo(char nomeArq[]) {
  int status;
  double num;
  FILE *arq = fopen(nomeArq, "rb");
  if (arq == NULL) {
    printf("Não pode abrir o arquivo!\n");
    return;
  }
  status = fread(&num, sizeof(double), 1, arq);
  while (!feof(arq)) {
    if (status != 1) {
      printf("Erro na leitura do registro");
    } else {
      printf("%.3f\n", num);
    }
    status = fread(&num, sizeof(double), 1, arq);
  }
  fclose(arq);
}

void lerPosicaoEspecifica(char nomeArq[]) {
  int status, pos;
  double num;
  FILE *arq = fopen(nomeArq, "rb");
  if (arq == NULL) {
    printf("Não pode abrir o arquivo!\n");
    return;
  }

  printf("Você quer mover para que posição: ");
  scanf("%d", &pos);

  status = fseek(arq, (pos - 1) * sizeof(double), SEEK_SET);
  if (status != 0 || feof(arq)) {
    printf("Essa é uma posição inválida!");
    fclose(arq);
    return;
  }

  status = fread(&num, sizeof(double), 1, arq);
  if (status != 1) {
    printf("Erro na leitura do registro");
  } else {
    printf("%.3f\n", num);
  }
  fclose(arq);
}