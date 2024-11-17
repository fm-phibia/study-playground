// https://atcoder.jp/contests/abc186/tasks/abc186_c
// N進数変換

#include <iostream>
#include <vector>
using namespace std;

vector<int> int2BaseNum (int val, int base) {
  vector<int> v;
  while (val > 0) {
    v.push_back(val % base);
    val /= base;
  }
  return v;
}

int main () {
  int n;
  cin >> n;

  int count = 0;

  for (int i = 1; i <= n; i++) {
    // iに7を含むか判定する
    int temp = i;
    bool seven = false;
    while (temp > 0) {
      if (temp % 10 == 7) {
        seven = true;
        break;
      }
      temp /= 10;
    }
    if(seven) {
      continue;
    }
    vector<int> v = int2BaseNum(i, 8);
    for(int j = 0; j < v.size(); j++) {
      if (v[j] == 7) {
        seven = true;
        break;
      }
    }
    if (!seven) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}