#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    x--;
    y--;
    vector<string> s(h);
    int ans = -3; // 重複してs[x][y]を数えてしまうので初期値を-3にしておく

    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }

    // xyから下方向に探索
    for (int i = x; i < h; i++) {
        if (s[i][y] == '#') {
            break;
        } else {
            ans++;
        }
    }

    // xyから上方向に探索
    for (int i = x; 0 <= i; i--) {
        if (s[i][y] == '#') {
            break;
        } else {
            ans++;
        }
    }

    // xyから右方向に探索
    for (int i = y; i < w; i++) {
        if (s[x][i] == '#') {
            break;
        } else {
            ans++;
        }
    }

    // xyから左方向に探索
    for (int i = y; 0 <= i; i--) {
        if (s[x][i] == '#') {
            break;
        } else {
            ans++;
        }
    }
    cout << ans << endl;
}
