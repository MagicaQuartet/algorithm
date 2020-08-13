#include<cstdio>
int N, K;
int sieve[1010];

int main() {
  scanf("%d %d", &N, &K);
  for (int i=2; i<=N; i++) {
    sieve[i] = i;
  }

  int idx = 2;
  while(idx <= N) {
    if (sieve[idx] > 0) {
      for (int i=1; i*idx<=N; i++) {
        if (sieve[i*idx] > 0) {
          K--;
          sieve[i*idx] = 0;

          if (!K) {
            printf("%d\n", i*idx);
            return 0;
          }
        }
      }
    }
    idx++;
  }
}