#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
#define INF 1000000001
#define pii pair<int, int>
#define vpii vector<pii >
#define ll long long
int N, S, D, M, u, v, w;
int visited[110];
ll profit[110], dist[110], originalDist[110];
void dfs(vector<vpii >& graph, int node, int mode) {
  visited[node] = mode ? 2 : 1;
  if (mode) dist[node] = -INF;
  for (pii edge: graph[node]) {
    int dst = edge.first;
    int nextMode = mode || dist[node] == -INF ? 1 : 0;
    if (!visited[dst] || visited[dst] == 1 && nextMode) dfs(graph, dst, nextMode);
  }
}
int main() {
  scanf("%d %d %d %d", &N, &S, &D, &M);
  vector<vpii > graph(N, vpii());
  for (int i=0; i<M; i++) {
    scanf("%d %d %d", &u, &v, &w);
    graph[u].push_back({v, w});
  }
  for (int i=0; i<N; i++) {
    scanf("%d", profit+i);
    visited[i] = 0;
    originalDist[i] = dist[i] = INF;
  }
  for (int i=0; i<N; i++) {
    for (pii edge: graph[i]) {
      graph[i].push_back({edge.first, edge.second-profit[edge.first]});
    }
  }
  originalDist[S] = dist[S] = -profit[S];
  for (int i=0; i<N; i++) {
    for (int src=0; src<N; src++) {
      for (pii edge: graph[src]) {
        int dst = edge.first;
        int cost = edge.second;
        originalDist[dst] = dist[dst] = min(dist[dst], dist[src]+cost);
      }
    }
  }

  for (int src=0; src<N; src++) {
    for (pii edge: graph[src]) {
      int dst = edge.first;
      int cost = edge.second;
      dist[dst] = min(dist[dst], dist[src]+cost);
    }
  }
  
  for (int i=0; i<N; i++) {
    if (originalDist[i] != dist[i]) {
      dist[i] = -INF;
    }
  }
  dfs(graph, S, 0);
  if (!visited[D]) printf("gg\n");
  else if (dist[D] == -INF) printf("Gee\n");
  else printf("%lld\n", -dist[D]);
}