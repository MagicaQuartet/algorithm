#include<cstdio>
#include<cstring>
#define ll long long
#define INF 1000000000
int N, dp[101][10][1024];
int main() {
  scanf("%d", &N);
  memset(dp, 0, sizeof(dp));
  for (int i=1; i<=9; i++) {
    dp[1][i][1<<i] = 1;
  }
  for (int i=2; i<=N; i++) {
    for (int j=0; j<=9; j++) {
      for (int k=0; k<1024; k++) {
        if ((k & (1<<j)) == 0) {
          continue;
        }
        if (j >= 1) {
          dp[i][j][k] = (dp[i-1][j-1][k]+dp[i-1][j-1][k^(1<<j)]) % INF;
        }
        if (j <= 8) {
          dp[i][j][k] += (dp[i-1][j+1][k]+dp[i-1][j+1][k^(1<<j)]) % INF;
        }
        dp[i][j][k] %= INF;
      }
    }
  }
  int ans = 0;
  for (int i=0; i<=9; i++) {
    ans = (ans + dp[N][i][1023]) % INF;
  }
  printf("%d\n", ans);
}
