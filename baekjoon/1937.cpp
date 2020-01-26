#include<cstdio>
#include<algorithm>
using namespace std;
int n, num, map[500][500], dp[500][500], ans=0;
int deltaX[4] = {1, -1, 0, 0};
int deltaY[4] = {0, 0, 1, -1};
int search(int x, int y, int prev) {
  if (x >= n || y >= n || x < 0 || y < 0 || prev >= map[x][y]) {
    return 0;
  }
  if (dp[x][y] != -1) {
    return dp[x][y];
  }
  
  int ret = 0, temp = map[x][y];
  map[x][y] = 0;
  for (int i=0; i<4; i++) {
    ret = max(ret, search(x+deltaX[i], y+deltaY[i], temp));
  }
  map[x][y] = temp;
  if (ans < ++ret) {
    ans = ret;
  }
  dp[x][y] = ret;
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      scanf("%d", &num);
      map[i][j] = num;
      dp[i][j] = -1;
    }
  }
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      search(i, j, -1);
    }
  }
  printf("%d\n", ans);
}

/* 각 지점에서 생존할 수 있는 최대 일 수를 한 번 알아내면 그 값은 절대 변하지 않는다. 이를 이용한 DFS+DP 풀이이다. */