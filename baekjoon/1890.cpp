#include<cstdio>
long long dp[100][100];
int board[100][100], N, num;
long long search(int x, int y) {
  if (x >= N || y >= N) {
    return 0;
  }
  if (board[x][y] == 0) {
    if (x == N-1 && y == N-1) {
      return 1;
    }
    else {
      return 0;
    }
  }
  if (dp[x][y] != -1) {
    return dp[x][y];
  }
  
  long long ret = search(x+board[x][y], y) + search(x, y+board[x][y]);
  dp[x][y] = ret;
  return ret;
}
int main() {
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      scanf("%d", &num);
      board[i][j] = num;
      dp[i][j] = -1;
    }
  }
  printf("%lld\n", search(0, 0));
}

/* 유의해야할 점이 여러 군데 있는 치사한 문제였다 */
/* 1. search 함수의 반환값 및 ret 변수는 long long 범위이다 */
/* 2. 끝나는 지점이 아니어도 0이 올 수 있어 그러한 경우를 걸러주어야 한다 */

/* (추가) 다른 사람의 풀이를 보니, 어차피 경로의 진행 방향은 항상 왼쪽 위에서 오른쪽 아래로 향한다는 점을 이용하여 이중 for-loop에서 입력을 받을 때마다 그 지점까지 도달 가능한 경로의 수를 그 지점에서 도달가능한 지점에 이르는 경로의 수에 더하는 방식으로 1개의 2차원 dp 배열로 해결하였다. */