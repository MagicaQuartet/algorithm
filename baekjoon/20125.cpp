#include<iostream>
#include<string>
using namespace std;
int N, hx, hy;
char cookie[1010][1010];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    hx = hy = -1;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            cookie[i][j] = s[j];
            if (i > 0 && hx == -1 && cookie[i - 1][j] == '*') {
                hx = i;
                hy = j;
            }
        }
    }
    int la = 0;
    for (int j = hy - 1; j >= 0; j--) {
        if (cookie[hx][j] == '_') {
            break;
        }
        la++;
    }
    int ra = 0;
    for (int j = hy + 1; j < N; j++) {
        if (cookie[hx][j] == '_') {
            break;
        }
        ra++;
    }
    int w = 0;
    for (int i = hx + 1; i < N; i++) {
        if (cookie[i][hy] == '_') {
            break;
        }
        w++;
    }
    int ll = 0;
    for (int i = hx + w + 1; i < N; i++) {
        if (cookie[i][hy - 1] == '_') {
            break;
        }
        ll++;
    }
    int rl = 0;
    for (int i = hx + w + 1; i < N; i++) {
        if (cookie[i][hy + 1] == '_') {
            break;
        }
        rl++;
    }
    cout << hx + 1 << ' ' << hy + 1 << ' ' << '\n' << la << ' ' << ra << ' ' << w << ' ' << ll << ' ' << rl << '\n';
}