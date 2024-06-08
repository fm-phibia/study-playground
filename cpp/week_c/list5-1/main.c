#include <stdio.h>

void normal();
void useArr();
 
int main(){
  normal();
  printf("-----------\n");
  useArr();
  return 0;
}

void normal() {
  double one,two,three;           //  変数の宣言
  double sum,avg; //  合計値、平均値を入れる変数
  one = 1.2,two = 3.7,three = 4.1;    //  変数の代入
  printf("%f %f %f\n",one,two,three);
  sum = one + two + three;    //  合計値の計算
  avg = sum / 3.0;            //  平均値の計算
  printf("合計値：%f\n",sum);
  printf("平均値：%f\n",avg);
}

void useArr() {
  // サイズ3の配列変数の宣言
  double d[3];
  double sum,avg; //  合計値、平均値を入れる変数
  int i;
  //  値を代入
  d[0] = 1.2;
  d[1] = 3.7;
  d[2] = 4.1;
  sum = 0.0;
  for(i = 0; i < 3; i++){
    printf("%f ",d[i]);
    sum += d[i];
  }
  printf("\n");
  avg = sum / 3.0;//  平均値の計算
  printf("合計値：%f\n",sum);
  printf("平均値：%f\n",avg);
}