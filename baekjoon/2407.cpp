#include<cstdio>
#include<utility>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define mk make_pair
#define UNIT 100000000000000000
int N, M;
pll dp[101][101];
pll add(pll a, pll b) {
  if (a.second+b.second < UNIT) {
    return mk(a.first+b.first, a.second+b.second);
  }
  else {
    return mk(a.first+b.first+1, a.second-UNIT+b.second);
  }
}
pll solve(int n, int m) {
  if (n == m || m == 0) {
    return mk(0, 1);
  }
  if (dp[n][m].first != 0 || dp[n][m].second != 0) {
    return dp[n][m];
  }
  return dp[n][m] = add(solve(n-1, m-1), solve(n-1, m));
}
int main() {
  scanf("%d %d", &N, &M);
  for (int i=1; i<=N; i++) {
    for (int j=0; j<=i; j++) {
      dp[i][j] = mk(0, 0);
    }
  }
  pll ret = solve(N, M);
  if (ret.first == 0) {
    printf("%lld\n", ret.second);
  }
  else {
    printf("%lld%017lld\n", ret.first, ret.second);
  }
}
