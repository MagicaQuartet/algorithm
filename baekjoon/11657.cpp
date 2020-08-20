#include<cstdio>
#include<algorithm>
#define INF 987654321
using namespace std;

int N, M, A, B, C;
int dist[510][510];
int edge[6010][3];
int buffer[510];

int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  for (int i=0; i<M; i++) {
    scanf("%d %d %d", &A, &B, &C);
    edge[i][0] = A;
    edge[i][1] = B;
    edge[i][2] = C;
  }
  
  dist[0][1] = buffer[1] = 0;
  for (int i=2; i<=N; i++) {
    dist[0][i] = buffer[i] = INF;
  }

  for (int k=1; k<=N; k++) {
    for (int e=0; e<M; e++) {
      int src = edge[e][0];
      int dst = edge[e][1];
      int w = edge[e][2];
      if (dist[k-1][src] == INF) {
        continue;
      }

      buffer[dst] = min(buffer[dst], dist[k-1][src]+w);
    }

    for (int i=1; i<=N; i++) {
      dist[k][i] = buffer[i];
    }
  }

  int isInfinite = 0;
  for (int i=1; i<=N; i++) {
    if (dist[N-1][i] != dist[N][i]) {
      isInfinite = 1;
      break;
    }
  }

  if (isInfinite) {
    printf("-1\n");
  }
  else {
    for (int i=2; i<=N; i++) {
      printf("%d\n", dist[N-1][i] != INF ? dist[N-1][i] : -1);
    }
  }
}