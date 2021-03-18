#include<iostream>
#include<cstring>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
#define INF 987654321
#define pii pair<int, int>
#define ppp pair<pii, pii >
#define mk make_pair
int board[1010][1010];
int dist[1010][1010][2];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i=1; i<=n; i++) {
    string row;
    cin >> row;
    for (int j=1; j<=m; j++) {
      board[i][j] = row[j-1]-'0';
      dist[i][j][0] = dist[i][j][1] = INF;
    }
  }
  queue<ppp > q;
  q.push(mk(mk(1, 1), mk(1, 0)));
  while (!q.empty()) {
    int x = q.front().first.first;
    int y = q.front().first.second;
    int d = q.front().second.first;
    int used = q.front().second.second;
    q.pop();
    if (d >= dist[x][y][used]) continue;
    dist[x][y][used] = d;
    for (int i=0; i<4; i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
      if (board[nx][ny] == -1) continue;
      if (board[nx][ny] == 1) {
        if (!used && d+1 < dist[nx][ny][1]) {
          q.push(mk(mk(nx, ny), mk(d+1, 1)));
        }
        continue;
      }
      if (d+1 >= dist[nx][ny][used]) continue;
      q.push(mk(mk(nx, ny), mk(d+1, used)));
    }
  }
  int ans = min(dist[n][m][0], dist[n][m][1]);
  printf("%d\n", ans==INF ? -1 : ans);
}
