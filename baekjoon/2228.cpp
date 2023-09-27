#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MIN -3276800
int dp[110][110][55];
int num[110], sum[110];
int N, M;
int solve(int l, int r, int m) {
  if (l > r) {
    return MIN;
  }
  if (m <= 0) {
    return MIN;
  }
  if (r-l+1 < m) {
    return MIN;
  }
  if (dp[l][r][m] != MIN) {
    return dp[l][r][m];
  }
  int ret = MIN;
  if (m == 1) {
    ret = sum[r] - sum[l-1];
  }
  for (int i=1; l+i<=r; i++) {
    if ((r-l-i+1+1)/2 < m) {
      break;
    }
    ret = max(ret, solve(l+i, r, m));
  }
  for (int i=1; r-i>=l; i++) {
    if ((r-i-l+1+1)/2 < m) {
      break;
    }
    ret = max(ret, solve(l, r-i, m));
  }
  for (int i=0; l+i<=r-2; i++) {
    if ((r-l-2-i+1+1)/2 < m-1) {
      break;
    }
    int lhs = solve(l, l+i, 1);
    int rhs = solve(l+2+i, r, m-1);
    if (lhs == MIN || lhs == MIN) {
      continue;
    }
    ret = max(ret, lhs+rhs);
  }
  return dp[l][r][m] = ret;
}
int main() {
  scanf("%d%d", &N, &M);
  memset(dp, -1, sizeof(dp));
  sum[0] = 0;
  for (int i=1; i <= N; i++) {
    int x;
    scanf("%d", &x);
    num[i] = x;
    sum[i] = x + sum[i-1];
  }
  for (int i=1; i<=N; i++) {
    for (int j=i; j<=N; j++) {
      for (int k=1; k<=M; k++) {
        dp[i][j][k] = MIN;
      }
    }
  }
  printf("%d\n", solve(1, N, M));
}
