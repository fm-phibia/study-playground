#include <stdio.h>
 
#define SIZE    5
   
int main(){
  //  サイズSIZEの配列を用意する。
  int ar1[SIZE];
  char ar2[SIZE];

  int i;
  int* p1 = NULL;
  char* p2 = NULL;
  
  //  値を代入
  for(i = 0; i < SIZE; i++){
      ar1[i] = i;
      ar2[i] = 'A'+i;
  }
  //  ポインタにアドレスを代入
  p1 = &ar1[0];
  p2 = &ar2[0];
  //  値を出力
  for(i = 0; i < SIZE; i++){
    // p1/p2のアドレス値は、最初に格納したのみだが、インクリメントすると次の配列の要素のアドレスを指している
    printf("ar1[%d]=%d *(p1+%d)=%d\n", i, ar1[i], i, *(p1+i));
    printf("ar2[%d]=%c *(p2+%d)=%c\n", i, ar2[i], i, *(p2+i));
    printf("\n");
  }

  return 0;
}