#include<cstdio>
#include<cstring>
using namespace std;
int N, M;
int map[110][110];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main() {
  scanf("%d%d", &N, &M);
  memset(map, 0, sizeof(map));
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) {
      scanf("%d", &map[i][j]);
    }
  }
  int ans = 0;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) {
      if (map[i][j] > 0) {
        ans += 2;
        for (int k=0; k<4; k++) {
          if (map[i][j] > map[i+dx[k]][j+dy[k]]) {
            ans += map[i][j] - map[i+dx[k]][j+dy[k]];
          }
        }
      }
    }
  }
  printf("%d\n", ans);
}
