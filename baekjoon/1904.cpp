#include<cstdio>
int dp[3], N, ans;
int main() {
  scanf("%d", &N);
  dp[0] = 1;
  dp[1] = 2;
  if (N > 2) {
    for (int i=3; i<=N; i++) {
      dp[2] = (dp[0] + dp[1])%15746;
      dp[0] = dp[1];
      dp[1] = dp[2];
    }
    ans = dp[2];
  }
  else {
    ans = dp[N-1];
  }
  printf("%d\n", ans);

  
  /* 잘 생각해보면 피보나치수 찾는 문제랑 같다 */