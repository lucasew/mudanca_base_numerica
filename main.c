/*
 * Calculadora de bases numéricas
 * By: Lucas Eduardo Wendt
 * A ideia é calcular qualquer base até a 36
 */

#include "src/basecalc.h"
#include "tests/test_basecalc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc > 1 && strcmp(argv[1], "--test") == 0) {
    test();
    return 0;
  }

#define ISBASEVALIDA(base)                                                     \
  if (base > 35) {                                                             \
    printf("E: Base inválida!\n");                                             \
    abort();                                                                   \
  }

  printf("Digite o número da base de origem: ");
  int basein;
  scanf("%i", &basein);
  ISBASEVALIDA(basein)
  printf("Digite o número da base de saída: ");
  int baseout;
  scanf("%i", &baseout);
  ISBASEVALIDA(baseout);
  printf("Pronto para digitar valores, pressione Ctrl+C para parar.\n");
  char entrada[50];
  while (1) {
    printf("Valor -> ");
    scanf("%49s", entrada);
    long int decoded = decode_base(entrada, basein);
    encode_base(decoded, baseout);
    printf("\n");
  }
}
