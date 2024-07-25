// https://atcoder.jp/contests/abc180/tasks/abc180_c
// 約数列挙

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> v;

    // nの約数の中央値は√nである
    for (long long i = 1; i <= sqrt(n) ; i++) {
        if (n % i == 0) {
            cout << i << endl;
            if (i != sqrt(n)) {
                v.insert(v.begin(), n/i);
            }
        }
    }
    for (long long i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    return 0;
}