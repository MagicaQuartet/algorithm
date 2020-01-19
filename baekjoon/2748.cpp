#include<cstdio>
long long fibo[91];
int N;
int main() {
  fibo[0] = 0;
  fibo[1] = 1;
  scanf("%d", &N);
  if (N > 1) {
    for (int i=2; i<=N; i++) {
      fibo[i] = fibo[i-1] + fibo[i-2];
    }
  }
  printf("%lld\n", fibo[N]);
}