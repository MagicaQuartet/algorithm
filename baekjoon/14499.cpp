#include<cstdio>
int N, M, x, y, K;
int board[21][21];
int dice[6], buf[6];
int dx[5] = {0, 0, 0, -1, 1}, dy[5] = {0, 1, -1, 0, 0};
const int EAST = 1, WEST = 2, NORTH = 3, SOUTH = 4;
const int TOP = 0, BOT = 4;
void roll(int direction) {
  if (direction == EAST) {
    buf[0] = dice[1];
    buf[1] = dice[4];
    buf[2] = dice[2];
    buf[3] = dice[0];
    buf[4] = dice[3];
    buf[5] = dice[5];
  }
  else if (direction == WEST) {
    buf[0] = dice[3];
    buf[1] = dice[0];
    buf[2] = dice[2];
    buf[3] = dice[4];
    buf[4] = dice[1];
    buf[5] = dice[5];
  }
  else if (direction == NORTH) {
    buf[0] = dice[2];
    buf[1] = dice[1];
    buf[2] = dice[4];
    buf[3] = dice[3];
    buf[4] = dice[5];
    buf[5] = dice[0];
  }
  else if (direction == SOUTH) {
    buf[0] = dice[5];
    buf[1] = dice[1];
    buf[2] = dice[0];
    buf[3] = dice[3];
    buf[4] = dice[2];
    buf[5] = dice[4];
  }
  dice[0] = buf[0];
  dice[1] = buf[1];
  dice[2] = buf[2];
  dice[3] = buf[3];
  dice[4] = buf[4];
  dice[5] = buf[5];
}
int main() {
  scanf("%d%d%d%d%d", &N, &M, &x, &y, &K);
  dice[0] = 0;
  dice[1] = 0;
  dice[2] = 0;
  dice[3] = 0;
  dice[4] = 0;
  dice[5] = 0;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  for (int i=0; i<K; i++) {
    int d;
    scanf("%d", &d);
    int nx = x + dx[d], ny = y + dy[d];
    if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
      continue;
    }
    roll(d);
    if (board[nx][ny] == 0) {
      board[nx][ny] = dice[BOT];
    }
    else {
      dice[BOT] = board[nx][ny];
      board[nx][ny] = 0;
    }
    printf("%d\n", dice[TOP]);
    x = nx;
    y = ny;
  }
}
