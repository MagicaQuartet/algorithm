#include<cstdio>
int M, N, h, map[500][500], dp[500][500];
int search(int i, int j) {
  if (i == M-1 && j == N-1) {
    return 1;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  
  int ret = 0;
  if (i+1 < M && map[i][j] > map[i+1][j]) {
    ret += search(i+1, j);
  }
  if (i-1 >= 0 && map[i][j] > map[i-1][j]) {
    ret += search(i-1, j);
  }
  if (j+1 < N && map[i][j] > map[i][j+1]) {
    ret += search(i, j+1);
  }
  if (j-1 >= 0 && map[i][j] > map[i][j-1]) {
    ret += search(i, j-1);
  }
  dp[i][j] = ret;
  return ret;
}
int main() {
  scanf("%d %d", &M, &N);
  for (int i=0; i<M; i++) {
    for (int j=0; j<N; j++) {
      scanf("%d", &h);
      map[i][j] = h;
      dp[i][j] = -1;
    }
  }
  printf("%d\n", search(0, 0));
}

/* 이러한 문제에서 각 지점의 dp값은 한 번 정해지면 절대로 바뀌지 않는다 */
/* 이를 이용하여 탐색하는 지점의 dp값이 이미 있으면 바로 반환하고, 없으면 가능한 경로를 계속 탐색한다. */