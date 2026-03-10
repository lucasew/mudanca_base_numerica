#ifndef BASECALC_H
#define BASECALC_H

int decode_char(char c);
char encode_char(int v);
void encode_base(long int dec, int baseout);
long int ipow(int base, int exp);
long int decode_base(char *source, int basein);

#endif
