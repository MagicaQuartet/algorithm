#include<cstdio>

int N, ans;
int sieve[250000];
int prefixCnt[250000];

int main() {
  prefixCnt[1] = 0;
  for (int i=2; i<250000; i++) {
    sieve[i] = 1;
  }
  for (int i=2; i<250000; i++) {
    prefixCnt[i] = prefixCnt[i-1] + sieve[i];
    if (!sieve[i]) continue;
    for (int j=2; i*j<250000; j++) {
      sieve[i*j] = 0;
    }
  }

  while(1) {
    scanf("%d", &N);
    if (N == 0) break;
    printf("%d\n", prefixCnt[2*N] - prefixCnt[N]);
  }
}
