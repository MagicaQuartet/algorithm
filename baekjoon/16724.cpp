#include<iostream>
#include<string>
using namespace std;
int N, M;
int board[1010][1010];
int solve(int x, int y, int idx) {
    if (x < 0 || y < 0 || x >= N || y >= M) {
        return idx;
    }
    if (board[x][y] < 0) {
        return board[x][y];
    }
    int cell = board[x][y];
    board[x][y] = idx;
    int ret = idx;
    switch (cell) {
    case 'L':
        ret = solve(x, y - 1, idx);
        break;
    case 'R':
        ret = solve(x, y + 1, idx);
        break;
    case 'U':
        ret = solve(x - 1, y, idx);
        break;
    case 'D':
        ret = solve(x + 1, y, idx);
        break;
    }
    return board[x][y] = ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            board[i][j] = s[j];
        }
    }
    int idx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] < 0) {
                continue;
            }
            idx++;
            if (solve(i, j, -idx) != -idx) {
                idx--;
            }
        }
    }
    printf("%d\n", idx);
}
