#include<cstdio>
#include<map>
#include<vector>
using namespace std;

int u, v, t;
map<int, vector<int> > graph;
map<int, int> inward;
map<int, int> visited;

int dfs(int node) {
  if (visited[node]) {
    return 0;
  }

  visited[node] = 1;
  vector<int> childs = graph[node];

  for (auto child: childs) {
    if (!dfs(child)) {
      return 0;
    }
  }

  return 1;
}

int main() {
  u = v = 0;
  t = 1;
  while(u != -1 && v != -1) {
    scanf("%d %d", &u, &v);
    if (u == 0 && v == 0) {
      int root;
      int rootCnt = 0;

      for (auto node: inward) {
        if (node.second == 0) {
          root = node.first;
          rootCnt++;
        }
      }

      if (rootCnt == 0) {
        printf("Case %d is %sa tree.\n", t, graph.size() == 0 ? "" : "not ");
      }
      else if (rootCnt > 1) {
        printf("Case %d is not a tree.\n", t);
      }
      else {
        int ret = dfs(root);
        int allVisited = 1;

        for (auto node: visited) {
          if (node.second == 0) {
            allVisited = 0;
            break;
          }
        }

        printf("Case %d is %sa tree.\n", t, ret && allVisited ? "" : "not ");
      }

      graph.clear();
      inward.clear();
      visited.clear();
      t++;
      continue;
    }

    if (graph.find(u) == graph.end()) {
      graph[u] = vector<int>();
    }
    if (inward.find(u) == inward.end()) {
      inward[u] = 0;
    }
    if (inward.find(v) == inward.end()) {
      inward[v] = 0;
    }
    if (visited.find(u) == visited.end()) {
      visited[u] = 0;
    }
    if (visited.find(v) == visited.end()) {
      visited[v] = 0;
    }

    graph[u].push_back(v);
    inward[v]++;
  }
}