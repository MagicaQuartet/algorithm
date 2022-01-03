#include<cstdio>
#include<cstring>
#define ll long long
int N, r[501], c[501];
ll dp[501][501];
int main() {
  scanf("%d", &N);
  for (int i=1; i<=N; i++) {
    scanf("%d %d", &r[i], &c[i]);
  }
  memset(dp, -1, sizeof(dp));
  for (int i=1; i<=N; i++) {
    dp[i][i] = 0;
    if (i<N) {
      dp[i][i+1] = r[i]*c[i]*c[i+1];
    }
  }
  for (int j=2; j<N; j++) {
    for (int i=1; i+j<=N; i++) {
      for (int k=i; k<i+j; k++) {
        ll candidate = dp[i][k] + dp[k+1][i+j] + r[i]*c[k]*c[i+j];
        if (dp[i][i+j] == -1 || candidate < dp[i][i+j]) {
          dp[i][i+j] = candidate;
        }
      }
    }
  }
  printf("%lld\n", dp[1][N]);
}
