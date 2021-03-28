#include<cstdio>
#include<vector>
using namespace std;
#define vi vector<int>
int N;
int ans[100010];
void dfs(vector<vi >& graph, int node, int parent) {
  ans[node] = parent;
  for (int child: graph[node]) {
    if (child == parent) {
      continue;
    }
    dfs(graph, child, node);
  }
}
int main() {
  scanf("%d", &N);
  vector<vi > graph(N+1, vi());
  for (int i=0; i<N-1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  dfs(graph, 1, -1);
  for (int i=2; i<=N; i++) {
    printf("%d\n", ans[i]);
  }
}
