#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define vi vector<int>
#define vvi vector<vi >
int N;
int visited[300010];
int dfs(vvi &graph, int u) {
    visited[u] = 1;
  int ret = 0;
  for (auto v: graph[u]) {
    if (visited[v]) {
      continue;
    }
    ret += dfs(graph, v);
  }
  return ret + 1;
}
int main() {
  scanf("%d", &N);
  memset(visited, 0, sizeof(visited));
  vvi graph = vvi(N+1, vi());
  for (int i=0; i<N-1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int sum = 0;
  int maxSub = 0;
  visited[1] = 1;
  for (auto u: graph[1]) {
    int sub = dfs(graph, u);
    sum += sub;
    if (maxSub < sub) {
      maxSub = sub;
    }
  }
  printf("%d\n", sum - maxSub + 1);
}
