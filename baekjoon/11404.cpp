#include<cstdio>
#define INF 987654321

int n, m, a, b, c;
int cost[101][101];

int main() {
  scanf("%d %d", &n, &m);
  
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      cost[i][j] = INF;
    }
  }
  
  for (int i=0; i<m; i++) {
    scanf("%d %d %d", &a, &b, &c);
    
    if (cost[a][b] > c) {
      cost[a][b] = c;
    }
  }
  
  for (int k=1; k<=n; k++) {
    for (int i=1; i<=n; i++) {
      for (int j=1; j<=n; j++) {
        if (i != j && cost[i][j] > cost[i][k] + cost[k][j]) {
          cost[i][j] = cost[i][k] + cost[k][j];
        }
      }
    }
  }
  
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      printf("%d ", cost[i][j] == INF ? 0 : cost[i][j]);
    }
    printf("\n");
  }
}