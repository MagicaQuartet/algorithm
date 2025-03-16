#include<cstdio>
#include<queue>
#include<utility>
using namespace std;
int N, M;
int board[51][51];
int dist[51][51][6];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
enum Status {
  STATUS_NONE,
  STATUS_TOP,
  STATUS_MIDDLE,
  STATUS_BOT,
  STATUS_INVALID
};
queue<pair<pair<int, int>, pair<int, int>>> q;
int main() {
  scanf("%d %d", &N, &M);
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      scanf("%d", &board[i][j]);
      for (int st=STATUS_NONE; st<=STATUS_BOT; st++) {
        dist[i][j][st] = -1;
      }
    }
  }
  q.push(make_pair(make_pair(0, STATUS_NONE), make_pair(0, 0)));
  while (!q.empty()) {
    int len = q.front().first.first;
    int status = q.front().first.second;
    int x = q.front().second.first;
    int y = q.front().second.second;
    q.pop();
    bool jaeum = board[x][y] <= 13;
    Status new_status;
    int new_len;
    switch (status) {
        case STATUS_NONE:
          new_status = jaeum ? STATUS_TOP : STATUS_INVALID;
          new_len = len;
          break;
        case STATUS_TOP:
          new_status = jaeum ? STATUS_INVALID : STATUS_MIDDLE;
          new_len = len + 1;
          break;
        case STATUS_MIDDLE:
          new_status = jaeum ? STATUS_BOT : STATUS_INVALID;
          new_len = len;
          break;
        case STATUS_BOT:
          new_status = jaeum ? STATUS_TOP : STATUS_MIDDLE;
          new_len = jaeum ? len : len+1;
          break;
        default:
          new_status = STATUS_INVALID;
    }
    if (new_status == STATUS_INVALID) {
      continue;
    }
    if (dist[x][y][new_status] != -1 && dist[x][y][new_status] <= new_len) {
      continue;
    }
    dist[x][y][new_status] = new_len;
    if (x == N-1 && y == M-1) {
      continue;
    }
    for (int i=0; i<4; i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
        continue;
      }
      q.push(make_pair(make_pair(new_len, new_status), make_pair(nx, ny)));
      if (new_status == STATUS_BOT) {
        q.push(make_pair(make_pair(new_len, STATUS_TOP), make_pair(nx, ny)));
      }
    }
  }
  int ans = -1;
  if (ans == -1 || (dist[N-1][M-1][STATUS_MIDDLE] != -1 && ans > dist[N-1][M-1][STATUS_MIDDLE])) {
    ans = dist[N-1][M-1][STATUS_MIDDLE];
  }
  if (ans == -1 || (dist[N-1][M-1][STATUS_BOT] != -1 && ans > dist[N-1][M-1][STATUS_BOT])) {
    ans = dist[N-1][M-1][STATUS_BOT];
  }
  if (ans == -1) {
    printf("BAD\n");
  }
  else {
    printf("%d\n", ans);
  }
}
