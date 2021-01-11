#include<cstdio>
#define ll long long
ll dp[15][15];
int t, k, n;
int main() {
  scanf("%d", &t);
  for (int i=1; i<=14; i++) {
    dp[0][i] = i;
    dp[i][0] = 0;
  }
  for (int i=1; i<=14; i++) {
    for (int j=1; j<=14; j++) {
      dp[i][j] = dp[i][j-1] + dp[i-1][j];
    }
  }
  while(t--) {
    scanf("%d %d", &k, &n);
    printf("%lld\n", dp[k][n]);
  }
}