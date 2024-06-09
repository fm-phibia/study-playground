#include <stdio.h>
#include <stdint.h>

int main(){
  char **pp = NULL;
  char *str[] = {"Hello", "World!!"};

  printf("str : 0x%x\n", str);          // strの中身を16進数で表示
  printf("str[0]: 0x%x\n", str[0]);     // str[0]の中身を16進数で表示
  printf("str[1]: 0x%x\n", str[1]);     // str[1]の中身を16進数で表示

  printf("&str: 0x%x\n", &str);         // strのアドレスを16進数で表示 (strと同じ値)
  printf("*str: %x\n", *str);           // strのポインタを16進数で表示 (= strが指し示すアドレス = str[0]の中身)

  // MEMO: 
  // strのポインタをズラす処理
  uintptr_t int_ptr = (uintptr_t)*str;
  int_ptr += 97;
  // 整数型から再びポインタ型にキャスト
  *str = (int*)int_ptr;
  

  printf("&str[0]: 0x%x\n", &str[0]);   // str[0]のアドレスを16進数で表示 (= strと同じ = strのアドレス)
  printf("*str[0]: 0x%x\n", *str[0]);     // str[0]の1文字目のASCIIコード
  printf("&*str[0]: 0x%x\n", &*str[0]);     // str[0]の1文字目のASCIIコード
  printf("&str[1]: 0x%x\n", &str[1]);
  printf("*str[1]: 0x%x\n", *str[1]); // str[1]の1文字目のASCIIコード

  printf("strの1つ目の文字列: %s\n", str[0]);
  printf("strの2つ目の文字列: %s\n", str[1]);

  printf("--------\n");
  
  // pp = str;
  // printf("pp[0]: %s\n", pp[0]);

  // printf("pp  : 0x%x, %ld\n", pp, sizeof(pp));
  // printf("*pp : 0x%x, %ld\n", *pp, sizeof(*pp));
  // printf("**pp: 0x%x, %ld\n", **pp, sizeof(**pp));
  // *pp++;
  // printf("pp  : 0x%x, %ld\n", pp, sizeof(pp));
  // printf("*pp : 0x%x, %ld\n", *pp, sizeof(*pp));
  // printf("**pp: 0x%x, %ld\n", **pp, sizeof(**pp));

  // printf("pp[0]: %s\n", pp[0]);

  return 0;
}
