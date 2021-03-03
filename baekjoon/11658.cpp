#include<cstdio>
#include<algorithm>
using namespace std;
int segtree[2050][2050];
int N, M, w, a, b, c, d;
void construct() {
  for (int i=0; i<N; i++) {
    for (int j=N-1; j>=1; j--) {
      segtree[N+i][j] = segtree[N+i][2*j] + segtree[N+i][2*j+1];
    }
  }
  for (int i=N-1; i>=1; i--) {
    for (int j=1; j<=2*N-1; j++) {
      segtree[i][j] = segtree[2*i][j] + segtree[2*i+1][j];
    }
  }
}
void update(int x, int y, int c) {
  int xStep = N+x-1;
  int yStep = N+y-1;
  segtree[xStep][yStep] = c;
  yStep /= 2;
  while (yStep) {
    segtree[xStep][yStep] = segtree[xStep][2*yStep] + segtree[xStep][2*yStep+1];
    yStep /= 2;
  }
  xStep /= 2;
  while (xStep) {
    for (int i=1; i<=2*N+1; i++) {
      segtree[xStep][i] = segtree[2*xStep][i] + segtree[2*xStep+1][i];
    }
    xStep /= 2;
  }
}
int subquery(int row, int y1, int y2) {
  int ans = 0;
  int lidx = N+y1-1;
  int ridx = N+y2;
  while (lidx < ridx) {
    if (lidx%2) ans += segtree[row][lidx++];
    if (ridx%2) ans += segtree[row][--ridx];
    lidx /= 2;
    ridx /= 2;
  }
  return ans;
}
int query(int x1, int y1, int x2, int y2) {
  int ans = 0;
  int lidx = N+x1-1;
  int ridx = N+x2;
  while (lidx < ridx) {
    if (lidx%2) ans += subquery(lidx++, y1, y2);
    if (ridx%2) ans += subquery(--ridx, y1, y2);
    lidx /= 2;
    ridx /= 2;
  }
  return ans;
}
int main() {
  scanf("%d %d", &N, &M);
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      scanf("%d", &segtree[N+i][N+j]);
    }
  }
  construct();
  for (int i=0; i<M; i++) {
    scanf("%d %d %d %d", &w, &a, &b, &c);
    if (w) {
      scanf("%d", &d);
      printf("%d\n", query(min(a, c), min(b, d), max(a, c), max(b, d)));
    }
    else {
      update(a, b, c);
    }
  }
}