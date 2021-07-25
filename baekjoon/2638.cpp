#include<cstdio>
#include<cstring>
int N, M;
int board[101][101], visited[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool dfs(int x, int y, int t) {
  visited[x][y]++;
  if (board[x][y] == 0) {
    if (visited[x][y] < 2) {
      return false;
    }
    board[x][y] = t+1;
    visited[x][y] = 0;
    return true;
  }

  int ret = false;
  for (int i=0; i<4; i++) {
    int nx = x+dx[i];
    int ny = y+dy[i];
    if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
      continue;
    }
    if (board[nx][ny] > t) {
      continue;
    }
    if (board[nx][ny] != 0 && visited[nx][ny]) {
      continue;
    }
    ret = dfs(nx, ny, t) || ret;
  }
  return ret;
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      scanf("%d", &board[i][j]);
      board[i][j] = !board[i][j];
    }
  }

  int ans = 0;
  while (1) {
    memset(visited, 0, sizeof(visited));
    if (!dfs(0, 0, ans+1)) {
      break;
    }
    ans++;
  }
  printf("%d\n", ans);
}
