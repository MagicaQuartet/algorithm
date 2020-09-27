#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int N, M;
int visited[2010];

int dfs(const vector<vector<int> >& tree, int node, int cnt) {
  if (cnt == 4) {
    return 1;
  }

  int ret = 0;
  visited[node] = 1;
  for (auto child: tree[node]) {
    if (visited[child]) {
      continue;
    }
    ret = dfs(tree, child, cnt+1);
    if (ret == 1) {
      break;
    }
  }
  visited[node] = 0;
  return ret;
}

int main() {
  scanf("%d %d", &N, &M);
  vector<vector<int> > tree(N, vector<int>());

  for (int i=0; i<M; i++) {
    int a,b;
    scanf("%d %d", &a, &b);
    
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  for (int i=0; i<N; i++) {
    memset(visited, 0, sizeof(visited));
    if (dfs(tree, i, 0)) {
      printf("1\n");
      return 0;
    }
  }

  printf("0\n");
  return 0;
}