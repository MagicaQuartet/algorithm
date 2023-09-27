#include<cstdio>
#include<cstring>
using namespace std;
#define Q 1000000007
#define ll long long
ll dp[110][110][110];
int N, L, R;
ll solve(int n, int l, int r) {
  if (n < l || n < r) {
    return 0;
  }
  if (l == 0) {
    return 0;
  }
  if (r == 0) {
    return 0;
  }
  if (n == 1 && l == 1 && r == 1) {
    return 1;
  }
  if (dp[n][l][r] != -1) {
    return dp[n][l][r];
  }
  ll case1 = (solve(n-1, l, r)*(n-2))%Q;
  ll case2 = solve(n-1, l-1, r);
  ll case3 = solve(n-1, l, r-1);
  ll ret = ((case1+case2)%Q + case3)%Q;
  return dp[n][l][r] = ret;
}
int main() {
  scanf("%d%d%d", &N, &L, &R);
  memset(dp, -1, sizeof(dp));
  printf("%lld\n", solve(N, L, R));
}
