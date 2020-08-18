#include<cstdio>
#include<algorithm>
#define INF 987654321
using namespace std;

int N, M;
int dist[501][501];
int reversedDist[501][501];

int main() {
  scanf("%d %d", &N, &M);

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      dist[i][j] = reversedDist[i][j] = INF;
    }
    dist[i][i] = reversedDist[i][i] = 0;
  }

  for (int i=0; i<M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    dist[a][b] = reversedDist[b][a] = 1;
  }

  for (int k=1; k<=N; k++) {
    for (int i=1; i<=N; i++) {
      for (int j=1; j<=N; j++) {
        if (i==j) continue;

        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        reversedDist[i][j] = min(reversedDist[i][j], reversedDist[i][k] + reversedDist[k][j]);
      }
    }
  }

  int ans = 0;
  for (int i=1; i<=N; i++) {
    int isValid = 1;
    for (int j=1; j<=N; j++) {
      if (dist[i][j] == INF && reversedDist[i][j] == INF) {
        isValid = 0;
        break;
      }
    }

    if (isValid) {
      ans++;
    }
  }

  printf("%d\n", ans);
}
