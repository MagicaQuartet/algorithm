#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int N, M;
int graph[1010][1010];
int dfs(int x, int y, int cur) {
    if (x < 0 || x >= N || y < 0 || y >= M || graph[x][y] == 0 || graph[x][y] == cur) {
        return cur;
    }
    if (graph[x][y] < 0 && graph[x][y] > cur) {
        return graph[x][y];
    }
    int direction = graph[x][y];
    graph[x][y] = cur;
    int ret = cur;
    switch (direction) {
    case 'S':
        ret = dfs(x + 1, y, cur);
        break;
    case 'W':
        ret = dfs(x, y - 1, cur);
        break;
    case 'E':
        ret = dfs(x, y + 1, cur);
        break;
    case 'N':
        ret = dfs(x - 1, y, cur);
        break;
    default:
        break;
    }
    graph[x][y] = ret;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(graph, 0, sizeof(graph));
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            graph[i][j] = s[j];
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] == 0) {
                continue;
            }
            int ret = dfs(i, j, -(ans + 1));
            if (ret == -(ans + 1)) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
}