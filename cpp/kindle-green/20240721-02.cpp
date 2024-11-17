// https://atcoder.jp/contests/abc192/tasks/abc192_c
// 関数の実装

#include <iostream>
#include <vector>
using namespace std;

// vector<int> viの要素を昇順に並び替える処理
vector<int> sortVector(vector<int> vi, bool asc) {
    for (int i = 0; i < vi.size(); i++) {
        for (int j = i + 1; j < vi.size(); j++) {
            bool swap = asc && vi[i] > vi[j] || !asc && vi[i] < vi[j];
            if (swap) {
                int tmp = vi[i];
                vi[i] = vi[j];
                vi[j] = tmp;
            }
        }
    }
    return vi;
}

vector<int> int2Vec(int v) {
    vector<int> vec;
    while (v > 0) {
        vec.push_back(v % 10);
        v /= 10;
    }
    return vec;
}

int vec2Int(vector<int> vec) {
    int v = 0;
    for (int i = 0; i < vec.size(); i++) {
        v = v * 10 + vec[i];
    }
    return v;
}

int calc (int input) {
    vector<int> v = sortVector2(int2Vec(input), false);
    int g1 = vec2Int(v);
    vector<int> v2 = sortVector2(int2Vec(input), true);
    int g2 = vec2Int(v2);
    return g1 - g2;
}

int main() {
    int n, k;
    cin >> n >> k;

    int temp = n;
    for (int i = 0; i < k; i++) {
        temp = calc(temp);
    }
    cout << temp << endl;
}