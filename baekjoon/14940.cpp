#include<cstdio>
#include<queue>
#include<utility>
using namespace std;
int N, M, sx, sy;
int dist[1010][1010];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int num;
            scanf("%d", &num);
            dist[i][j] = -num;
            if (num == 2) {
                sx = i;
                sy = j;
            }
        }
    }
    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, make_pair(sx, sy)));
    while (!q.empty()) {
        int d = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        if (dist[x][y] >= 0 && dist[x][y] <= d) {
            continue;
        }
        dist[x][y] = d;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
                continue;
            }
            q.push(make_pair(d + 1, make_pair(nx, ny)));
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", dist[i][j] >= 0 ? dist[i][j] : -1);
        }
        printf("\n");
    }
}
