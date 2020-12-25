#include<cstdio>
int T, N;
int sieve[10001];

int main() {
  scanf("%d", &T);
  for (int i=2; i<=10000; i++) {
    sieve[i] = 1;
  }
  for (int i=2; i<=10000; i++) {
    if (!sieve[i]) continue;
    for (int j=2; i*j<=10000; j++) {
      sieve[i*j] = 0;
    }
  }
  while(T--) {
    scanf("%d", &N);
    for (int i=N/2; i>=2; i--) {
      if (sieve[i] && sieve[N-i]) {
        printf("%d %d\n", i, N-i);
        break;
      }
    }
  }
}