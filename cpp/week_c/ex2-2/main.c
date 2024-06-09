#include <stdio.h>
 
void show(int,int,int);
 
void main(){
  int a = 100;    //  整数型変数a
  int b = 200;    //  整数型変数b
  int c = 100000;
  int *p = NULL;  //  整数型のポインタ変数p

  // MEMO:
  // アドレスがNULLの状態で値を代入すると実行時エラーが発生する (Segmentation fault)
  // *p = 100;

  void address() {
    printf("aのアドレス:%x\n",&a);
    printf("bのアドレス:%x\n",&b);
    printf("dのアドレス:%x\n",&c);
    printf("pの値　　　:%x\n",p);
    printf("\n");
  }

  printf("初期値\n");
  printf("a = %d b = %d\n",a,b);
  address();

  printf("pにaのアドレスを代入\n");
  p = &a; //  pにaのアドレスを代入
  show(a,b,*p);
  address();

  printf("*pに値を代入\n");
  *p = 300;   //  *pに値を代入
  show(a,b,*p);
  address();

  printf("pにbのアドレスを代入\n");
  p = &b; //  pにbのアドレスを代入
  show(a,b,*p);
  address();

  printf("*pに値を代入\n");
  *p = 400;   //  *pに値を代入
  show(a,b,*p);
  address();

  // p+=5;
  printf("aとcのアドレスの差: %ld\n", &a-&c);
  // show(a,b,*p);
  printf("pにaのアドレスを代入し、aとcのアドレスの差分だけpをズラす\n");
  p = &a;
  p -= 2;
  show(a,b,*p);
  address();

}
 
void show(int n1,int n2,int n3){
  printf("a = %d b = %d *p = %d\n",n1,n2,n3);
}

// ポインタ変数はアドレスを保持できる変数
// pはアドレスを、*pはそのアドレスの値を保持する