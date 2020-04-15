#include<cstdio>
#include<cstring>

int N, dp[50010];

int main() {
  scanf("%d", &N);
  memset(dp, 0, 4*N);
    
  for (int i=1; i*i<=N; i++) {
    dp[i*i] = 1;
  }
  
  for (int i=2; i<=N; i++) {    
    for (int j=1; j*j<=i; j++) {
      if (dp[i] == 1) {
        continue;
      }
      
      if (dp[i] == 0 || dp[i-j*j] + 1 < dp[i]) {
        dp[i] = dp[i-j*j] + 1;
      }
    }
  }
  
  printf("%d\n", dp[N]);
}