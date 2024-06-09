#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main(){
  int a,b;
  // 乱数の初期化

  // MEMO:
  // 初期化をしないとrandの値が固定になってしまう
  srand((unsigned) time(NULL));

  printf("rand() = %d\n",rand());
  printf("RAND_MAX = %d\n",RAND_MAX);

  // 1から10までの乱数を発生させる
  a = rand() % 10 + 1;
  // 0から10までの乱数を発生させる
  b = rand() % (10 + 1);
  //    計算結果を出力
  printf("%d + %d = %d\n",a,b,a+b);
  return 0;
}