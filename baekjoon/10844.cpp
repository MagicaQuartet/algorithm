#include<cstdio>
#define INF 1000000000
int N, dp[10][101];
int main() {
  scanf("%d", &N);
  for (int i=1; i<=9; i++) {
    dp[i][1] = 1;
  }
  dp[0][1] = 0;

  for (int n=2; n<=N; n++) {
    for (int i=0; i<=9; i++) {
      int sum = 0;
      if (i >= 1) {
        sum += dp[i-1][n-1];
      }
      if (i <= 8) {
        sum += dp[i+1][n-1];
      }
      dp[i][n] = sum % INF;
    }
  }
  int ans = 0;
  for (int i=0; i<=9; i++) {
    ans = (ans + dp[i][N]) % INF;
  }
  printf("%d\n", ans);
}
