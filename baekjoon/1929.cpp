#include<cstdio>

int N, M;
int sieve[1000010];

int main() {
  scanf("%d %d", &M, &N);
  for (int i=2; i<=N; i++) {
    sieve[i] = 1;
  }

  for (int i=2; i<=N; i++) {
    if (!sieve[i]) continue;
    
    if (i >= M) {
      printf("%d\n", i);
    }
    for (int j=2; i*j<=N; j++) {
      sieve[i*j] = 0;
    }
  }
}
