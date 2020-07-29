#include<cstdio>
#include<vector>
using namespace std;

int N, sum = 0;

void dfs(const vector<vector<int> >& tree, vector<int>& visited, int node, int depth) {
  int isLeaf = 1;
  visited[node] = 1;

  for (auto neighbor: tree[node]) {
    if (visited[neighbor]) {
      continue;
    }

    isLeaf = 0;
    dfs(tree, visited, neighbor, depth+1);
  }

  if (isLeaf) {
    sum += depth;
  }
}

int main() {
  scanf("%d", &N);
  vector<vector<int> > tree(N, vector<int>());
  vector<int> visited(N, 0);

  for (int i=0; i<N-1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);

    tree[a-1].push_back(b-1);
    tree[b-1].push_back(a-1);
  }

  dfs(tree, visited, 0, 0);
  printf("%s\n", sum%2 ? "Yes" : "No");
}