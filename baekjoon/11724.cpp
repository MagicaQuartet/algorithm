#include<cstdio>
#include<vector>
#include<list>
using namespace std;

int N, M, u, v, cnt;

void dfs(const vector<list<int> >& graph, vector<int>& visited, int node) {
  visited[node] = 1;
  
  for (auto i : graph[node]) {
    if (!visited[i]) {
      dfs(graph, visited, i);
    }
  }
  
  return;
}

int main() {
  scanf("%d %d", &N, &M);
  
  vector<list<int> > g(N+1, list<int>());
  vector<int> visited(N+1, 0);
  
  for (int i=0; i<M; i++) {
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  
  cnt = 0;
  
  for (int i=1; i<=N; i++) {
    if (!visited[i]) {
      dfs(g, visited, i);
      cnt++;
    }
  }
  
  printf("%d\n", cnt);
}

/*
  DFS
*/