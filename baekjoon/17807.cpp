#include<cstdio>
#include<cstring>
#define ll long long
#define Q 1000000007
using namespace std;
int A, B, K, C;
ll dp[1010][1010];
ll solve(int n, int m) {
  if (m == n || m == 0) {
    return 1;
  }
  if (m < 0 || m > n) {
    return 0;
  }
  if (dp[n][m] != -1) {
    return  dp[n][m];
  }
  return dp[n][m] = (solve(n-1, m-1)+ solve(n-1, m))%Q;
}
int main() {
  scanf("%d %d %d %d", &A, &B, &K, &C);
  memset(dp, -1, sizeof(dp));
  if (K == 0 || A != C && B != C) {
    printf("0\n");
    return 0;
  }
  if (A != B) {
    ll ret = 0;
    for (int i=0; i<=K; i++) {
      ret = (ret + solve(K, i)*i)%Q;
    }
    printf("%lld\n", ret);
  }
  else {
    printf("%d\n", K);
  }
}
