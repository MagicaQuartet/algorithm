#include<cstdio>
#define INF 100000
#define ll long long

int w, h;
ll dp[101][101][2];

// prev -> 0: 이전에 2 이상, 1: 이전에 1만큼
// mode -> 0: 이번에 w쪽 사용, 1: 이번에 h쪽 사용
ll solve(int wleft, int hleft, int prev, int mode) {
  if (dp[wleft][hleft][mode] != -1) {
    return dp[wleft][hleft][mode];
  }

  ll ret = 0;

  if (wleft == 0) {
    ret = 1;
  }
  else if (hleft == 0) {
    ret = 1;
  }
  else {
    if (mode) {
      for (int i=prev+1; i<=hleft; i++) {
        ret += solve(wleft, hleft-i, 1, 1-mode) % INF;
      }
    }
    else {
      for (int i=prev+1; i<=wleft; i++) {
        ret += solve(wleft-i, hleft, 1, 1-mode) % INF;
      }
    }
  }
  return dp[wleft][hleft][mode] = ret;
}

int main() {
  scanf("%d %d", &w, &h);

  for (int i=0; i<w; i++) {
    for (int j=0; j<h; j++) {
      dp[i][j][0] = dp[i][j][1] = -1;
    }
  }

  printf("%lld\n", (solve(w-1, h-1, 0, 0) + solve(w-1, h-1, 0, 1)) % INF);
}