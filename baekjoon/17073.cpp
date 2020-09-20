#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int N, W, leafCnt;
int visited[500010];

double dfs(const vector<vector<int> >& tree, int node, double p) {
  int childrenCnt = 0;
  visited[node] = 1;

  for (auto child: tree[node]) {
    childrenCnt += !visited[child];
  }

  if (childrenCnt == 0) {
    leafCnt++;
    return p;
  }
  
  double ret = 0;

  for (auto child: tree[node]) {
    if (visited[child]) {
      continue;
    }

    ret += dfs(tree, child, p/childrenCnt);
  }

  return ret;
}

int main() {
  scanf("%d %d", &N, &W);
  vector<vector<int> > tree(N, vector<int>());
  memset(visited, 0, sizeof(visited));

  for (int i=0; i<N-1; i++) {
    int U, V;
    scanf("%d %d", &U, &V);
    tree[U-1].push_back(V-1);
    tree[V-1].push_back(U-1);
  }

  leafCnt = 0;
  printf("%f\n", dfs(tree, 0, W)/leafCnt);
}
