#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printb(unsigned int i) {

  // MEMO:
  // int i を2進数としてprintfする
  int BITE = 1;
  for (int j = BITE*CHAR_BIT-1; j >= 0; j--) {
    // (i >> j)　は　jビット右シフト
    // (i >> j) & 1　は　jビット右シフトと1のAND演算 ・・・1とのAND演算=対象の右端のビットが1かどうかを判定
    printf("%d", (i >> j) & 1);
    // i=15、j=7のとき、
    // iの2進数は「00001111」なので、
    // i >> j = 0 となる
    // (i >> j) & 1 = 0 となり、0が出力される(一番左端)
    // i=15、j=2のとき
    // i >> j = 11 となる
    // (i >> j) & 1 = 1 となり、1が出力される(右から3番目)
    if (j % 8 == 0) {
      printf(" ");
    }
  }
  printf("\n");
}
 
int main(){
  //  16進数
  unsigned char i = 0xf;  //  2進数：00001111
  unsigned char j = 0xff; //  2進数：11111111
  printf("%d:%x\n", i, i);
  printb(i);
  printf("%d:%x\n", j, j);
  printb(j);
  printf("---------------\n");
  printf("%xを1ビット左シフト\n", i);
  printf("%x << 1 = %x\n",i,i << 1);          //  1ビット左シフト： 2進数：00011110 = 0x1e0
  printb(i << 1);
  printf("%xを1ビット右シフト\n", i);
  printf("%x >> 1 = %x\n",i,i >> 1);          //  1ビット右シフト： 2進数：00000111 = 0x7
  printb(i >> 1);
  printf("%x | %x = %x\n",i,j,i | j);         //  OR演算  ： 2進数：11111111 = 0xff
  printf("%x & %x = %x\n",i,j,i & j);         //  AND演算 ： 2進数：00001111 = 0xf
  printf("~%x = %x\n",i,(unsigned char)~i);   //  NOT演算 ： 2進数：11110000 = 0xf0

  printf("---------------\n");
  printb(10);
  printb(20);
  printb(10 & 20);
  printb(10 | 20);
  printb(~20);

  return 0;
}