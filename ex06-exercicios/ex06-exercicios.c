#include <stdio.h>

#define QTD 15

void imprimirVetor(int v[], int tam);
void inserirValor(int v[], int *tam);
int buscaSequencial(int v[], int tam, int x);
void buscarValalores(int v[], int tam);
void insertionSort(int v[], int tam);

int main() {
  int numeros[QTD];
  int tam = 0, opcao;

  do {
    printf("\n\nMENU\n");
    printf("1 - Inserir valor no vetor\n");
    printf("2 - Imprimir o vetor\n");
    printf("3 - Buscar valores no vetor\n");
    printf("4 - Ordenar o vetor com Insertion Sort\n");
    printf("Digite a sua opção (0 p/ sair):\n");
    scanf("%d", &opcao);
    switch(opcao) {
      case 1:
        inserirValor(numeros, &tam);
        break;
      case 2:
        imprimirVetor(numeros, tam);
        break;
      case 3:
        buscarValalores(numeros, tam);
        break;
      case 4:
        insertionSort(numeros, tam);
        break;
      default:
        if (opcao != 0) {
          printf("Opção inválida!\n");
        }
        break;
    }
  } while (opcao != 0);
  printf("\nEncerrando o programa...\n");
  return 0;
}

void imprimirVetor(int v[], int tam) {
  printf("{");
  if (tam > 0) {
    printf(" %d", v[0]);
  }
  for (int i = 1; i < tam; i += 1) {
    printf(", %d", v[i]);
  }
  printf(" }\n");
}

void inserirValor(int v[], int *tam) {
  if (*tam >= QTD) {
    printf("\nVetor cheio!\n");
    return;
  }

  printf("Digite um número inteiro: ");
  scanf("%d", &v[*tam]);
  *tam += 1;
}

int buscaSequencial(int v[], int tam, int x) {
  for (int i = 0; i < tam; i += 1) {
    if (v[i] == x) {
      return i;
    }
  }
  return -1;
}

void buscarValalores(int v[], int tam) {
  char opcao;
  int valor;
  do {
    printf("Digite o valor a ser buscado:\n");
    scanf("%d", &valor);
    int pos = buscaSequencial(v, tam, valor);
    if (pos != -1) {
      printf("Valor %d foi encontrado na posição %d\n", valor, pos + 1);
    } else {
      printf("Valor %d não foi encontrado no vetor!\n", valor);
    }
    printf("Quer realizar outra busca (s/n):\n");
    scanf("%c", &opcao); // lê o ENTER da digitação anterior
    scanf("%c", &opcao);
  } while (opcao == 's');
}

void insertionSort(int v[], int tam) {
  for (int i = 1; i <= tam - 1; i += 1) {
    int chave = v[i];
    int j = i;
    while (j > 0 && chave < v[j - 1]) {
      v[j] = v[j - 1];
      j = j - 1;
    }
    v[j] = chave;
  }
}
