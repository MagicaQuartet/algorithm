#include<cstdio>
#include<cstring>
using namespace std;
int room[55][55];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M, r, c, d;
int ans;
void dfs(int x, int y, int di) {
  if (room[x][y] == 0) {
    ans++;
    room[x][y] = 2;
  }
  int nd, nx, ny;
  bool found = false;
  for (int i=7; i>=4; i--) {
    nd = (i+di)%4;
    nx = x+dx[nd];
    ny = y+dy[nd];
    if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
      continue;
    }
    if (room[nx][ny] != 0) {
      continue;
    }
    found = true;
    break;
  }
  if (found) {
    dfs(nx, ny, nd);
  } else {
    nd = (di+2)%4;
    nx = x+dx[nd];
    ny = y+dy[nd];
    if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
      return;
    }
    if (room[nx][ny] == 1) {
      return;
    }
    dfs(nx, ny, di);
  }
}
int main() {
  scanf("%d%d%d%d%d", &N, &M, &r, &c, &d);
  for (int i=0; i < N; i++) {
    for (int j=0; j<M; j++) {
      scanf("%d", &room[i][j]);
    }
  }
  ans = 0;
  dfs(r, c, d);
  printf("%d\n", ans);
}
