#include<cstdio>
#include<cstring>

int N;
int field[17][17];
int dp[17][17][3];

int solve(int x, int y, int direction) {
  if (x <= 0 || x > N || y <= 0 || y > N) {
    return 0;
  }

  if (field[x][y] == 1) {
    return 0;
  }

  if (direction == 1 && ((x > 1 && field[x-1][y] == 1) || (y > 1 && field[x][y-1] == 1))) {
    return 0;
  }

  if (x == N && y == N) {
    return 1;
  }

  if (dp[x][y][direction] != -1) {
    return dp[x][y][direction];
  }

  int ret = 0;

  if (direction == 0) {
    ret += solve(x, y+1, 0);
    ret += solve(x+1, y+1, 1);
  }
  else if (direction == 1) {
    ret += solve(x, y+1, 0);
    ret += solve(x+1, y+1, 1);
    ret += solve(x+1, y, 2);
  }
  else if (direction == 2) {
    ret += solve(x+1, y+1, 1);
    ret += solve(x+1, y, 2);
  }

  return dp[x][y][direction] = ret;
}

int main() {
  scanf("%d", &N);
  memset(dp, -1, sizeof(dp));

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      scanf("%d", &field[i][j]);
    }
  }

  printf("%d\n", solve(1, 2, 0));
}