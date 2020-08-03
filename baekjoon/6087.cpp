#include<cstdio>
#include<queue>
#include<utility>
#include<algorithm>
#define INF 987654321
#define pii pair<int, int>
using namespace std;

int W, H;
int cx, cy;
int minCnt;
int map[110][110];
int deltaX[4] = {-1, 0, 1, 0};
int deltaY[4] = {0, 1, 0, -1};

int main() {
  scanf("%d %d", &W, &H);
  queue<pair<pair<pii, pii>, int> > q;  // (((현재 좌표), (델타값), 거울 수)

  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      char c;
      c = getchar();
      if (c == '\n') c = getchar();

      if (c == 'C') {
        cx = i;
        cy = j;
        map[i][j] = INF;
      }
      else if (c == '.') {
        map[i][j] = -1;
      }
      else {
        map[i][j] = -INF;
      }
    }
  }

  map[cx][cy] = 0;
  q.push({{{cx, cy}, {0, 0}}, 0});
  minCnt = INF;

  while (!q.empty()) {
    pair<pair<pii, pii>, int> item = q.front();
    q.pop();

    int x = item.first.first.first;
    int y = item.first.first.second;
    int dx = item.first.second.first;
    int dy = item.first.second.second;
    int cnt = item.second;

    if (map[x][y] == INF) {
      minCnt = min(minCnt, cnt);
      continue;
    }

    if (cnt >= minCnt) {
      continue;
    }

    for (int i=0; i<4; i++) {
      if (x+deltaX[i] < 0 || x+deltaX[i] >= H || y+deltaY[i] < 0 || y+deltaY[i] >= W) {
        continue;
      }

      int deltaCnt = (dx == 0 && dy == 0) || (dx == deltaX[i] && dy == deltaY[i]) ? 0 : 1;

      //printf("... try to %d %d -> %d %d (current cnt: %d)\n", x, y, x+deltaX[i], y+deltaY[i], map[x+deltaX[i]][y+deltaY[i]]);
      if (map[x+deltaX[i]][y+deltaY[i]] != -1 && map[x+deltaX[i]][y+deltaY[i]] < cnt+deltaCnt) {
        continue;
      }

      //printf(">>> %d %d -> %d %d (dx: %d, dy: %d, cnt: %d -> %d)\n", x, y, x+deltaX[i], y+deltaY[i], dx, dy, cnt, cnt+deltaCnt);
      q.push({{{x+deltaX[i], y+deltaY[i]}, {deltaX[i], deltaY[i]}}, cnt+deltaCnt});
      
      if (map[x+deltaX[i]][y+deltaY[i]] != INF) {
        map[x+deltaX[i]][y+deltaY[i]] = cnt+deltaCnt;
      }
    }
  }

  printf("%d\n", minCnt);
}

/*
  약간의 아이디어가 필요한 BFS였다.
  최단 거리가 같아도 필요한 거울의 수가 다를 수 있다.
*/