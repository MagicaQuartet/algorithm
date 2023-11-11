#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
#define si set<int>
int N, M;
int A[200010], B[200010];
vector<si > graph(200010, si());
int visited[200010];
bool dfs(int n, int prev, int depth) {
  if (visited[n] != -1) {
    return !((depth - visited[n]) % 2);
  }
  visited[n] = depth;
  for (auto i: graph[n]) {
    if (i == prev) {
      continue;
    }
    if (!dfs(i, n, depth+1)) {
      return false;
    }
  }
  return true;
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i=0; i<M; i++) {
    scanf("%d", &A[i]);
  }
  for (int i=0; i<M; i++) {
    scanf("%d", &B[i]);
  }
  memset(visited, -1, sizeof(visited));
  for (int i=0; i<M; i++) {
    graph[A[i]].insert(B[i]);
    graph[B[i]].insert(A[i]);
  }
  for (int i=1; i<=N; i++){
    if (graph[i].size() == 0 || visited[i] != -1) {
      continue;
    }
    if (!dfs(i, -1, 0)) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
}
