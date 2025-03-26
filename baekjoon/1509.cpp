#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string s;
int pal[2510][2510];
int dp[2510];
bool is_pal(int lhs, int rhs) {
  if (lhs >= rhs) {
    return true;
  }
  if (pal[lhs][rhs] != -1) {
    return pal[lhs][rhs] == 1;
  }
  if (s[lhs] != s[rhs]) {
    pal[lhs][rhs] = 0;
    return false;
  }
  return pal[lhs][rhs] = is_pal(lhs+1, rhs-1);
}
int solve(int lhs) {
  if (lhs >= s.size()) {
    return 0;
  }
  if (dp[lhs] != -1) {
    return dp[lhs];
  }
  if (is_pal(lhs, s.size()-1)) {
    return 1;
  }
  int ret = -1;
  for (int i=lhs; i<s.size(); i++) {
    if (!is_pal(lhs, i)) {
      continue;
    }
    int _ret = 1 + solve(i+1);
    if (ret == -1 || ret > _ret) {
      ret = _ret;
    }
  }
  return dp[lhs] = ret;
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> s;
  memset(pal, -1, sizeof(pal));
  memset(dp, -1, sizeof(dp));
  printf("%d\n", solve(0));
}
