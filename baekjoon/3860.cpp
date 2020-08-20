#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#define INF 987654321
#define pii pair<int, int>
using namespace std;

int W, H, G, X, Y, E, X1, Y1, X2, Y2, T;
int graveyard[31][31];
int dist[910][31][31];
int buffer[31][31];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<pair<pii , pii>, int>> edges;

int main() {
  while(1) {
    scanf("%d %d", &W, &H);
    if (W == 0 && H == 0) {
      break;
    }
    edges.clear();
    edges.reserve(4*W*H);

    for (int i=0; i<W; i++) {
      for (int j=0; j<H; j++) {
        graveyard[i][j] = 0;
        dist[0][i][j] = buffer[i][j] = INF;
      }
    }

    scanf("%d", &G);
    for (int i=0; i<G; i++) {
      scanf("%d %d", &X, &Y);
      graveyard[X][Y] = -1;
    }

    scanf("%d", &E);
    for (int i=0; i<E; i++) {
      scanf("%d %d %d %d %d", &X1, &Y1, &X2, &Y2, &T);
      graveyard[X1][Y1] = 1;
      edges.push_back({{{X1, Y1}, {X2, Y2}}, T});
    }

    for (int i=0; i<W; i++) {
      for (int j=0; j<H; j++) {
        if (i == W-1 && j == H-1) {
          break;
        }

        if (graveyard[i][j] == 0) {
          for (int d=0; d<4; d++) {
            int nx = i+dx[d];
            int ny = j+dy[d];
            if (nx < 0 || ny < 0 || nx >= W || ny >= H) {
              continue;
            }
            if (graveyard[nx][ny] == -1) {
              continue;
            }
            edges.push_back({{{i, j}, {nx, ny}}, 1});
          }
        }
      }
    }

    dist[0][0][0] = buffer[0][0] = 0;
    for (int k=1; k<=W*H; k++) {
      for (auto e: edges) {
        pii src = e.first.first;
        pii dst = e.first.second;
        int w = e.second;

        if (buffer[dst.first][dst.second] == INF && dist[k-1][src.first][src.second] == INF) {
          buffer[dst.first][dst.second] = INF;
        }
        else {
          buffer[dst.first][dst.second] = min(buffer[dst.first][dst.second], dist[k-1][src.first][src.second]+w);
        }
      }

      for (int i=0; i<W; i++) {
        for (int j=0; j<H; j++) {
          dist[k][i][j] = buffer[i][j];
        }
      }
    }

    int isInfinite = 0;
    for (int i=0; i<W; i++) {
      for (int j=0; j<H; j++) {
        if (dist[W*H-1][i][j] != dist[W*H][i][j]) {
          isInfinite = 1;
          break;
        }
      }
      if (isInfinite) {
        break;
      }
    }

    if (isInfinite) {
      printf("Never\n");
    }
    else if (dist[W*H-1][W-1][H-1] == INF) {
      printf("Impossible\n");
    }
    else {
      printf("%d\n", dist[W*H-1][W-1][H-1]);
    }
  }
}