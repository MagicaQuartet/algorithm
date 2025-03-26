#include<cstdio>
#include<cstring>
using namespace std;
int N;
int board[10][10];
int diagonal1[20], diagonal2[20];
int col_start(int row, bool mode) {
  return mode ? row%2 : (row%2+1)%2;
}
int chk_diagonal(int x, int y) {
  return diagonal1[x+y] + diagonal2[y-x+N-1];
}
void mark_diagonal(int x, int y, int val) {
  diagonal1[x+y] = diagonal2[y-x+N-1] = val;
}
int solve(int x, int y, bool mode) {
  if (y >= N) {
    return solve(x+1, col_start(x+1, mode), mode);
  }
  if (x >= N) {
    return 0;
  }
  if (chk_diagonal(x, y) > 0) {
    return solve(x, y+2, mode);
  }
  if (board[x][y] != 1) {
    return solve(x, y+2, mode);
  }
  int ret1 = solve(x, y+2, mode);
  mark_diagonal(x, y, 1);
  int ret2 = 1+solve(x, y+2, mode);
  mark_diagonal(x, y, 0);
  return ret1 > ret2 ? ret1 : ret2;
}
int main() {
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  memset(diagonal1, 0, sizeof(diagonal1));
  memset(diagonal2, 0, sizeof(diagonal2));
  int ans1 = solve(0, 0, true);
  int ans2 = solve(0, 1, false);
  printf("%d\n", ans1+ans2);
}
