#include<cstdio>
#include<algorithm>
#define INF 987654321
using namespace std;

int V, E;
int graph[401][401];

int main() {
  scanf("%d %d", &V, &E);

  for (int i=1; i<=V; i++) {
    for (int j=1; j<=V; j++) {
      graph[i][j] = i == j ? 0 : INF;
    }
  }

  for (int i=0; i<E; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    graph[a][b] = min(graph[a][b], c);
  }

  for (int k=1; k<=V; k++) {
    for (int i=1; i<=V; i++) {
      for (int j=1; j<=V; j++) {
        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
      }
    }
  }

  int minVal = INF;
  for (int i=1; i<=V; i++) {
    for (int j=1; j<=V; j++) {
      if (i == j) {
        continue;
      }

      minVal = min(minVal, graph[i][j] + graph[j][i]);
    }
  }

  printf("%d\n", minVal < INF ? minVal : -1);
}
