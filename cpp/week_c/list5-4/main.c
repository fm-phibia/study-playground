#include <stdio.h>
 
int main(){
  char s1[4] = { 'a','b','c','\0' };  //  文字列"abc"
  char s2[] = "HelloWorld.";          //  文字列"HelloWorld."
  char s3[10];                        //  最大10文字まで入る文字列
  //  文字列の入力
  printf("文字列を入力してください。:");
  // メモ：ここではなぜか＆アンバサントがいらない
  scanf("%s",s3); //  文字列の入力

  printf("s1 = %s\n",s1);
  printf("s2 = %s\n",s2);
  printf("s3 = %s\n",s3);

  return 0;

  // MEMO: 文字列の最後の文字は0(ヌル文字)になっている
  // for (int i = 0; i < sizeof(s1); i++) {
  //   printf("s1[%d] = %c\n",i,s1[i]);
  // }
  // for (int i = 0; i < sizeof(s2); i++) {
  //   printf("s2[%d] = %c\n",i,s2[i]);
  // }
  // for (int i = 0; i < sizeof(s3); i++) {
  //   printf("s3[%d] = %c\n",i,s3[i]);
  // }
}