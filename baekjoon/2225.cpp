#include<cstdio>
int N, K;
long long cache[201][201];
long long solve(int n, int k) {
  if (cache[n][k] != -1) {
    return cache[n][k];
  }
  
  long long ret = 0;
  for (int i=0; i<=n; i++) {
    ret += solve(n-i, k-1) % 1000000000;
    ret %= 1000000000;
  }
  cache[n][k] = ret;
  return ret;
}
int main() {
  scanf("%d %d", &N, &K);
  for (int i=0; i<=N; i++) {
    for (int j=0; j<=K; j++) {
      cache[i][j] = (i == 0 || j == 1) ? 1 : -1;
    }
  }
  printf("%lld\n", solve(N, K));
}

/* 다른 사람들은 1차원 dp 배열로 푸는데 그 원리를 잘 모르겠다... */
/* 참고) https://www.acmicpc.net/source/10927693 */