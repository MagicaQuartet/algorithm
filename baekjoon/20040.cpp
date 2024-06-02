#include<cstdio>
#include<cstring>
using namespace std;
int parent[500010];
int n, m;
int find(int x) {
  if (parent[x] == -1 || parent[x] == x) {
    return parent[x] = x;
  }
  return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
  int px = find(x);
  int py = find(y);
  if (px > py) {
    parent[px] = py;
  } else {
    parent[py] = px;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  memset(parent, -1, sizeof(parent));
  int ans = 0;
  for (int i=1; i<=m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (ans > 0) {
      continue;
    }
    int px = find(x);
    int py = find(y);
    if (px == py) {
      ans = i;
      continue;
    }
    merge(x, y);
  }
  printf("%d\n", ans);
}
