#include<cstdio>

int N, M;
int minVal, sum;
int sieve[1000010];

int main() {
  scanf("%d %d", &M, &N);
  minVal = -1;
  sum = 0;
  for (int i=2; i<=N; i++) {
    sieve[i] = 1;
  }

  for (int i=2; i<=N; i++) {
    if (!sieve[i]) continue;
    
    if (i >= M) {
      if (minVal == -1) {
        minVal = i;
      }
      sum += i;
    }
    for (int j=2; i*j<=N; j++) {
      sieve[i*j] = 0;
    }
  }
  if (sum > 0) {
    printf("%d\n", sum);
  }
  printf("%d\n", minVal);
}
