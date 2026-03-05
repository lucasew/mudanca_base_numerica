#include "basecalc.h"
#include <stdio.h>
#include <string.h>

// Obtem o valor correspondente a um char. Ex A é 10, B é 11
int decode_char(char c) {
  if (c >= 48 && c <= 57) { // Números
    return (int)c - 48;
  }
  if (c >= 65 && c <= 90) { // Letras maiúsculas
    return (int)c - 65 + 10;
  }
  if (c >= 97 && c <= 122) { // Letras minúsculas
    return (int)c - 97 + 10;
  }
  return 255;
}

// Transforma o valor de base 10 a char
char encode_char(int v) {
  if (v < 10) {
    return (char)(v + 48);
  } else {
    return (char)(v - 10 + 65);
  }
  return '_';
}

// printa o valor codificado
void encode_base(long int dec, int baseout) {
  if (dec >= baseout) {
    encode_base(dec / baseout, baseout);
  }
  printf("%c", encode_char(dec % baseout));
}

// Calcula a potência de números inteiros
long int ipow(int base, int exp) {
  long int res = 1;
  for (; exp > 0; exp--) {
    res *= base;
  }
  return res;
}

// decode_base: transforma o valor em string num long int para ser codificado na
// base de destino
long int decode_base(char *source, int basein) {
  if (source[0] == '\0')
    return 0;
  int n = decode_char(source[0]);
  if (n >= basein) {
    printf("Valores inválidos de entrada encontrados: %c.\nO resultado será "
           "prejudicado.\n",
           source[0]);
  };
  long int res = decode_base(source + 1, basein);
  res +=
      ipow(basein, strlen(source) - 1) * n; // Adiciona o valor daquela posição
  return res;
}
