#include<cstdio>
int N, K, cache[11][11];
int solve(int n, int k) {
  if (cache[n][k] != -1) {
    return cache[n][k];
  }
  int ret = solve(n-1, k-1)+solve(n-1, k);
  cache[n][k] = ret;
  return ret;
}
int main() {
  scanf("%d %d", &N, &K);
  for (int i=0; i<=N; i++) {
    cache[i][0] = 1;
    for (int j=1; j<=i; j++) {
      cache[i][j] = -1;
    }
  }
  cache[1][1] = 1;
  printf("%d\n", solve(N, K));
}