#include <stdio.h>

double dobro(double x);

int main() {
  double num, result;
  printf("Digite um número real: ");
  scanf("%lf", &num);
  result = dobro(num);
  printf("O dobro de %f é %f\n", num, result);
  return 0;
}

double dobro(double x) {
  return 2 * x;
}
