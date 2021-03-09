#include<cstdio>
#define ll long long
#define INF 1000000007
int M, N, K;
int factorial[4000010];
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
  scanf("%d", &M);
  int acc = 1;
  factorial[0] = 1;
  for (int i=1; i<=4000000; i++) {
    acc = ((ll)acc*i)%INF;
    factorial[i] = acc;
  }
  while (M--) {
    scanf("%d %d", &N, &K);
    int A = factorial[N];
    int B = ((ll)factorial[K]*factorial[N-K])%INF;

    printf("%d\n", ((ll)A*solve(B, INF-2))%INF);
  }
}
