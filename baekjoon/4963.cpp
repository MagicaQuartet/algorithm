#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;

int w, h;
char graph[51][51];
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int main() {
  while(1) {
    scanf("%d%d", &w, &h);
    if (w == 0) {
      break;
    }
    memset(graph, 0, sizeof(graph));
    for (int i=0; i<h; i++) {
      for (int j=0; j<w; j++) {
        scanf("%d", &graph[i][j]);
      }
    }

    int ans = 0;
    queue<pair<int, int>> q;
    for (int i=0; i<h; i++) {
      for (int j=0; j<w; j++) {
        if (graph[i][j] < 1) {
          continue;
        }

        q.push({i, j});
        while(!q.empty()) {
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          if (graph[x][y] < 1) {
            continue;
          }
          graph[x][y] = -1;
          for (int i=0; i<8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
              continue;
            }
            if (graph[nx][ny] < 1) {
              continue;
            }
            q.push({nx, ny});
          }
        }
        ans++;
      }
    }
    printf("%d\n", ans);
  }
}
