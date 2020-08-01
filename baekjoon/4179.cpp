#include<cstdio>
#include<queue>
#include<utility>
#define INF 987654321
using namespace std;

int R, C;
int miro[1001][1001];

int main() {
  scanf("%d %d", &R, &C);
  queue<pair<pair<int, int>, int> > qFire;
  queue<pair<pair<int, int>, int> > qJihoon;

  for (int i=0; i<R; i++) {
    for (int j=0; j<C; j++) {
      char c = getchar();
      if (c == '\n') c = getchar();

      if (c == '#') {
        miro[i][j] = -INF;
      }
      else {
        if (c == 'J') {
          qJihoon.push({{i, j}, 0});
        }
        else if (c == 'F') {
          qFire.push({{i, j}, 0});
        }
        miro[i][j] = -1;
      }
    }
  }

  // fire BFS
  while (!qFire.empty()) {
    pair<int, int> coord = qFire.front().first;
    int x = coord.first;
    int y = coord.second;
    int timestamp = qFire.front().second;
    qFire.pop();

    if (miro[x][y] == timestamp) {
      continue;
    }

    miro[x][y] = timestamp;

    if (x > 0 && (miro[x-1][y] == -1 || miro[x-1][y] > timestamp+1)) {
      qFire.push({{x-1, y}, timestamp+1});
    }
    if (y > 0 && (miro[x][y-1] == -1 || miro[x][y-1] > timestamp+1)) {
      qFire.push({{x, y-1}, timestamp+1});
    }
    if (x < R-1 && (miro[x+1][y] == -1 || miro[x+1][y] > timestamp+1)) {
      qFire.push({{x+1, y}, timestamp+1});
    }
    if (y < C-1 && (miro[x][y+1] == -1 || miro[x][y+1] > timestamp+1)) {
      qFire.push({{x, y+1}, timestamp+1});
    }
  }

  // jihoon BFS
  while (!qJihoon.empty()) {
    pair<int, int> coord = qJihoon.front().first;
    int x = coord.first;
    int y = coord.second;
    int timestamp = qJihoon.front().second;
    qJihoon.pop();

    if (x == 0 || y == 0 || x == R-1 || y == C-1) {
      printf("%d\n", timestamp+1);
      return 0;
    }

    if (miro[x][y] == -INF) {
      continue;
    }

    miro[x][y] = -INF;

    if (x > 0 && (miro[x-1][y] == -1 || miro[x-1][y] > timestamp+1)) {
      qJihoon.push({{x-1, y}, timestamp+1});
    }
    if (y > 0 && (miro[x][y-1] == -1 || miro[x][y-1] > timestamp+1)) {
      qJihoon.push({{x, y-1}, timestamp+1});
    }
    if (x < R-1 && (miro[x+1][y] == -1 || miro[x+1][y] > timestamp+1)) {
      qJihoon.push({{x+1, y}, timestamp+1});
    }
    if (y < C-1 && (miro[x][y+1] == -1 || miro[x][y+1] > timestamp+1)) {
      qJihoon.push({{x, y+1}, timestamp+1});
    }
  }

  printf("IMPOSSIBLE\n");
}

/*
  BFS를 이용해 불이 각 타일에 퍼지는 시간을 기록한 뒤
  다시 BFS를 이용해 지훈이가 불이 퍼지는 시간보다 빠르게 도달할 수 있는 타일을 찾도록 한다.
  탐색 중 가장자리에 도착하면 미로를 탈출할 수 있다.
*/