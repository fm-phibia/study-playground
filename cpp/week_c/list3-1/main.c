#include <stdio.h>

int main()
{
  int num;
  printf("数値を入力: ");
  // 入力した数値をnumに格納
  // 格納する際は[&]をつける。(アンバサント)
  scanf("%d", &num);

  if (num > 0) {
    printf("入力した数値は正の整数です。\n");
    printf("入力した数値は%dです。\n", num);
    printf("前置インクリメント:%d\n", ++num);
    printf("前置インクリメント後:%d\n", num);
    printf("後置インクリメント:%d\n", num++);
    printf("後置インクリメント後:%d\n", num);
  } else if (num < 0) {
    printf("入力した数値は負の整数です。\n");
  } else {
    printf("入力した値は正の整数でも負の整数でもありません。\n");
  }
}