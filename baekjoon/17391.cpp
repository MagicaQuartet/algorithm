#include<cstdio>
#include<algorithm>
#define INF 987654321
using namespace std;
int N, M, data[300][300], dp[300][300];
int solve(int x, int y) {
  if (x == N-1 && y == M-1) {
    return 0;
  }
  if (dp[x][y] != INF) {
    return dp[x][y];
  }
  
  int ret = INF;
  for (int i=1; i<=data[x][y] && x+i<N; i++) {
    ret = min(ret, solve(x+i, y)+1);
  }
  for (int j=1; j<=data[x][y] && y+j<M; j++) {
    ret = min(ret, solve(x, y+j)+1);
  }
  dp[x][y] = ret;
  return ret;
}
int main() {
  scanf("%d %d", &N, &M);
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      scanf("%d", &data[i][j]);
      dp[i][j] = INF;
    }
  }
  
  printf("%d", solve(0, 0));
}