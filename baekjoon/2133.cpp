#include<cstdio>
#include<cstring>
int N, dp[31];
int main() {
  scanf("%d", &N);
  if (N%2 == 1) {
    printf("0\n");
    return 0;
  }
  
  memset(dp, 0, 124);
  for (int i=1; i<=N; i++) {
    for (int j=2; j<=N; j+=2) {
      int delta = j==2 ? 3 : 2;
      if (i==j) {
        dp[i] += delta;
      }
      else if (i > j) {
        dp[i] += dp[i-j] * delta;
      }
    }
  }
  printf("%d\n", dp[N]);
}

/* 단위가 2, 4, 6, ... (2의 배수)인 동전으로 N원을 만드는 문제로 바꾸어 생각할 수 있다. */
/* 그리고 뽑은 동전의 종류가 같아도 순서가 같으면 다른 경우의 수로 간주한다! */