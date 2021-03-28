#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
#define pii pair<int, int>
#define vpii vector<pii >
#define mk make_pair
int V;
pii dfs(vector<vpii >& graph, vector<int>& visited, int node) {
  int depth1 = 0;
  int depth2 = 0;
  int diameter = 0;
  visited[node] = 1;
  for (pii child: graph[node]) {
    if (visited[child.first]) {
      continue;
    }

    pii ret = dfs(graph, visited, child.first);
    if (ret.first + child.second >= depth1) {
      depth2 = depth1;
      depth1 = ret.first + child.second;
    }
    else if (ret.first + child.second > depth2) {
      depth2 = ret.first + child.second;
    }
    if (ret.second > diameter) {
      diameter = ret.second;
    }
  }
  visited[node] = 0;
  return mk(depth1, max(diameter, depth1+depth2));
}
int main() {
  scanf("%d", &V);
  vector<vpii > graph(V+1, vpii());
  vector<int> visited(V+1, 0);
  for (int i=1; i<=V; i++) {
    int node, v, d;
    scanf("%d", &node);
    while (1) {
      scanf("%d", &v);
      if (v == -1) {
        break;
      }
      scanf("%d", &d);
      graph[node].push_back(mk(v, d));
    }
  }
  pii ret = dfs(graph, visited, 1);
  printf("%d\n", ret.second);
}
