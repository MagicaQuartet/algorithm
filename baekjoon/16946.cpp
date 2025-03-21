#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;
int board[1010][1010];
map<int, int> cnt;
int dfs_idx = 2;
int dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= M) {
        return 0;
    }
    if (board[x][y] >= 1) {
        return 0;
    }
    board[x][y] = dfs_idx;
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        ans += dfs(nx, ny);
    }
    return ans + 1;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            board[i][j] = s[j] - '0';
        }
    }
    // 연결된 셀 표시
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] >= 1) {
                continue;
            }
            int ret = dfs(i, j);
            cnt[dfs_idx++] = ret;
        }
    }
    // 벽마다 인접한 연결된 셀 확인
    set<int> visited;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] != 1) {
                printf("0");
                continue;
            }
            visited.clear();
            int ans = 1;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
                    continue;
                }
                if (board[nx][ny] <= 1) {
                    continue;
                }
                if (visited.count(board[nx][ny]) > 0) {
                    continue;
                }
                ans += cnt[board[nx][ny]];
                visited.insert(board[nx][ny]);
            }
            printf("%d", ans % 10);
        }
        printf("\n");
    }
}
