#include<cstdio>
#include<cstring>
#define ll long long

int M, K, sum;
int colors[51];
ll binomial[51][51];

ll calculateBinomial(int n, int r) {
  if (n <= 1 || r == 0 || n == r) {
    return 1;
  }

  if (r == 1) {
    return n;
  }

  if (binomial[n][r] != -1) {
    return binomial[n][r];
  }

  return binomial[n][r] = calculateBinomial(n-1, r-1) + calculateBinomial(n-1, r);
}

int main() {
  scanf("%d", &M);
  memset(binomial, -1, sizeof(binomial));
  sum = 0;
  for (int i=0; i<M; i++) {
    scanf("%d", colors+i);
    sum += colors[i];
  }
  scanf("%d", &K);

  double ans = 0;
  for (int i=0; i<M; i++) {
    if (colors[i] < K) {
      continue;
    }

    ans += calculateBinomial(colors[i], K);
  }

  for (int k=1; k<=K; k++) {
    ans = ans*k/(sum-k+1);
  }

  printf("%0.10f\n", ans);
}