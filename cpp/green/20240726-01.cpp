// https://atcoder.jp/contests/abc203/tasks/abc203_c
// 11 TLEに注意
#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>

#define rp(i, n) for(ll i=0; i < n; i++)

using namespace std;

typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> v;
    rp(i, n) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    ll count = k;
    rp(i, n) {
        if (v[i][0] <= count) {
            count += v[i][1];
        }
    }
    cout << count << endl;
}