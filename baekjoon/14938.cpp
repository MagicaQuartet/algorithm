#include<cstdio>
#include<cstring>
int n, m, r;
int items[101], d[101][101];
int main() {
  scanf("%d %d %d", &n, &m, &r);
  memset(d, -1, sizeof(d));
  for (int i=1; i<=n; i++) {
    int t;
    scanf("%d", &t);
    items[i] = t;
    d[i][i] = 0;
  }
  for (int i=0; i<r; i++) {
    int a, b, l;
    scanf("%d %d %d", &a, &b, &l);
    d[a][b] = d[a][b] == -1 || l < d[a][b] ? l : d[a][b];
    d[b][a] = d[b][a] == -1 || l < d[b][a] ? l : d[b][a];
  }
  for (int k=1; k<=n; k++) {
    for (int i=1; i<=n; i++) {
      for (int j=1; j<=n; j++) {
        if (d[i][k] == -1 || d[k][j] == -1) {
          continue;
        }
        int l1 = d[i][j];
        int l2 = d[i][k] + d[k][j];
        if (l1 == -1 || l2 < l1) {
          d[i][j] = l2;
        }
      }
    }
  }

  int ans = 0;
  for (int i=1; i<=n; i++) {
    int sum = 0;
    for (int j=1; j<=n; j++) {
      if (d[i][j] != -1 && d[i][j] <= m) {
        sum += items[j];
      }
    }
    if (ans < sum) {
      ans = sum;
    }
  }
  printf("%d\n", ans);
}
