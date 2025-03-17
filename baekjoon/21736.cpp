#include<iostream>
#include<string>
#include<queue>
#include<utility>
using namespace std;
int N, M, sx, sy;
char board[610][610];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    string row;
    for (int i = 0; i < N; i++) {
        cin >> row;
        for (int j = 0; j < M; j++) {
            board[i][j] = row[j];
            if (row[j] == 'I') {
                sx = i;
                sy = j;
            }
        }
    }
    int ans = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (board[x][y] == 'X') {
            continue;
        }
        if (board[x][y] == 'P') {
            ans++;
        }
        board[x][y] = 'X';
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
                continue;
            }
            q.push(make_pair(nx, ny));
        }
    }
    if (ans == 0) {
        cout << "TT\n";
    }
    else {
        cout << ans << "\n";
    }
}
