#include "test_basecalc.h"
#include "../src/basecalc.h"
#include <assert.h>
#include <stdio.h>

void test_encode_char() {
  assert(encode_char(1) == '1');
  assert(encode_char(10) == 'A');
  assert(encode_char(15) == 'F');
  assert(encode_char(35) == 'Z');
}

void test_decode_base() {
  assert(decode_base("aa20", 16) == 43552);
  assert(decode_base("fffa", 16) == 65530);
  assert(decode_base("416", 8) == 270);
  assert(decode_base("1110", 2) == 14);
}

void test_decode_char() {
  assert(2 == decode_char('2'));
  assert(9 == decode_char('9'));
  assert(0 == decode_char('0'));
  assert(10 == decode_char('A'));
  assert(10 == decode_char('a'));
}

void test_ipow() {
  assert(ipow(2, 2) == 4);
  assert(ipow(3, 2) == 9);
  assert(ipow(4, 3) == 64);
}

void test() {
  test_ipow();
  test_decode_char();
  test_decode_base();
  test_encode_char();
  encode_base(43552, 16);
  printf("\n");
}
