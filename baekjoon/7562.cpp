#include<cstdio>
#include<queue>
#include<utility>
using namespace std;
#define INF 987654321
#define pii pair<int, int>
#define ppiii pair<pii, int>
#define mk make_pair
int board[310][310];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int t, n, srcx, srcy, dstx, dsty;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d %d %d", &n, &srcx, &srcy, &dstx, &dsty);
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        board[i][j] = INF;
      }
    }
    queue<ppiii> q;
    q.push(mk(mk(srcx, srcy), 0));
    while (!q.empty()) {
      int x = q.front().first.first;
      int y = q.front().first.second;
      int dist = q.front().second;
      q.pop();
      if (dist >= board[x][y]) continue;
      if (x == dstx && y == dsty) {
        printf("%d\n", dist);
        break;
      }

      board[x][y] = dist;
      for (int i=0; i<8; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (dist+1 >= board[nx][ny]) continue;
        q.push(mk(mk(nx, ny), dist+1));
      }
    }
  }
}
