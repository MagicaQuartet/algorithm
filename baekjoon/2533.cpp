#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define vi vector<int>
int N, dp[1000010][2];
int dfs(const vector<vi >& tree, int node, int mode, int parent) {
  if (dp[node][mode] != -1) return dp[node][mode];
  int ret = 0;
  for (int child: tree[node]) {
    if (child == parent) continue;
    ret += min(dfs(tree, child, 1, node), mode ? dfs(tree, child, 0, node) : 987654321);
  }
  return dp[node][mode] = ret + (mode ? 1 : 0);
}
int main() {
  scanf("%d", &N);
  memset(dp, -1, sizeof(dp));
  vector<vi > tree(N+1, vi());
  for (int i=0; i<N-1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  printf("%d\n", min(dfs(tree, 1, 0, -1), dfs(tree, 1, 1, -1)));
}