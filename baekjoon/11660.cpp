#include<cstdio>

int N, M, x1, y1, x2, y2;
int accSum[1025][1025];

int main() {
  scanf("%d %d", &N, &M);

  for (int i=0; i<=N; i++) {
    accSum[i][0] = accSum[0][i] = 0;
  }

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      scanf("%d", &accSum[i][j]);
      accSum[i][j] += accSum[i-1][j] + accSum[i][j-1] - accSum[i-1][j-1];
    }
  }

  while(M--) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    printf("%d\n", accSum[x2][y2]-accSum[x1-1][y2]-accSum[x2][y1-1] + accSum[x1-1][y1-1]);
  }
}