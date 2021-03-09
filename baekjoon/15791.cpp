#include<cstdio>
#define ll long long
#define INF 1000000007
int N, K;
int solve(int x, ll r) {
  if (r == 1) {
    return x;
  }

  int divided = solve(x, r/2);
  int ret = ((ll)divided*divided)%INF;
  if (r % 2) {
    ret = ((ll)ret * x)%INF;
  }
  return ret;
}
int main() {
  scanf("%d %d", &N, &K);
  int A = 1, B = 1;
  for (int i=1; i<=N; i++) {
    A = ((ll)A*i)%INF;
    if (i == K) {
      B = ((ll)A*B)%INF;
    }
    if (i == (N-K)) {
      B = ((ll)A*B)%INF;
    }
  }

  printf("%d\n", ((ll)A*solve(B, INF-2))%INF);
}
