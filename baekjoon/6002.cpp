#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
#define INF 987654321
#define pii pair<int, int>
#define vpii vector<pii >
int D, P, C, F, S, A, B, J, K, T;
int dist[230], originalDist[230];
int main() {
  scanf("%d%d%d%d%d", &D, &P, &C, &F, &S);
  vector<vpii > graph(C+1, vpii());
  for (int i=1; i<=C; i++) dist[i] = -INF;
  for (int i=0; i<P; i++) {
    scanf("%d%d", &A, &B);
    graph[A].push_back({B, D});
  }
  for (int i=0; i<F; i++) {
    scanf("%d%d%d", &J, &K, &T);
    graph[J].push_back({K, D-T});
  }
  dist[S] = D;
  for (int i=0; i<C-1; i++) {
    for (int src=1; src<=C; src++) {
      for (pii edge: graph[src]) {
        int dst = edge.first;
        int cost = edge.second;
        if (dist[src] == -INF) continue;
        dist[dst] = max(dist[dst], dist[src]+cost);
      }
    }
  }
  for (int i=1; i<=C; i++) originalDist[i] = dist[i];
  for (int src=1; src<=C; src++) {
    for (pii edge: graph[src]) {
      int dst = edge.first;
      int cost = edge.second;
      if (dist[src] == -INF) continue;
      dist[dst] = max(dist[dst], dist[src]+cost);
    }
  }
  int ans = 0;
  for (int i=1; i<=C; i++) {
    if (dist[i] > originalDist[i]) {
      ans = -1;
      break;
    }
    ans = max(ans, dist[i]);
  }
  printf("%d\n", ans);
}