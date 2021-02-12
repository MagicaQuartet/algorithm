#include<cstdio>
#include<cstring>
#define INF 1000000000
int N, positive[1000010], negative[1000010];
int pconstruct(int n) {
  if (positive[n] != INF) return positive[n];
  return positive[n] = ((long long)pconstruct(n-1) + pconstruct(n-2)) % INF;
}
int nconstruct(int n) {
  if (negative[n] != INF) return negative[n];
  return negative[n] = ((long long)nconstruct(n-2) - nconstruct(n-1)) % INF;
}
int main() {
  scanf("%d", &N);
  for (int i=2; i<=1000000; i++) {
    positive[i] = negative[i] = INF;
  }
  positive[0] = negative[0] = 0;
  positive[1] = negative[1] = 1;
  int ans = N >= 0 ? pconstruct(N) : nconstruct(-N);
  printf("%d\n", ans == 0 ? 0 : (ans > 0) ? 1 : -1);
  printf("%d\n", ans >= 0 ? ans : -ans);
}