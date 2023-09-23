#include<cstdio>
#include<cstring>
using namespace std;
int family[110][110];
int visited[110];
int n, a, b, m, x, y;
int dfs(int p) {
  if (p == b) {
    return 0;
  }
  visited[p] = 1;
  for (int i=1; i<=100; i++) {
    if (family[p][i] == 0) {
      continue;
    }
    if (visited[i] == 1) {
      continue;
    }
    int ret = dfs(i);
    if (ret >= 0) {
      return ret+1;
    }
  }
  return -1;
}
int main() {
  scanf("%d%d%d%d", &n, &a, &b, &m);
  memset(family, 0, sizeof(family));
  memset(visited, 0, sizeof(visited));
  while(m--) {
    scanf("%d%d", &x, &y);
    family[x][y] = 1;
    family[y][x] = 1;
  }
  printf("%d\n", dfs(a));
}
