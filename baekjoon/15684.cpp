#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 987654321
using namespace std;

int N, M, H;
int ladder[31][11];

int downward(int i) {
  int col = i;
  for (int j=1; j<=H; j++) {
    col -= ladder[j][col];
  }
  return col;
}

int construct() {
  int check = 1;
  for (int i=1; i<=N; i++) {
    int col = downward(i);
    if (col != i) {
      check = 0;
      break;
    }
  }
  return check;
}

int solve(int row, int col, int cnt) {
  if (row > H || cnt == 3) {
    return construct() ? cnt : INF;
  }

  if (col >= N) {
    return solve(row+1, 1, cnt);
  }

  if (ladder[row][col] == 1) {
    return solve(row, col+1, cnt);
  }
  if (ladder[row][col] == -1) {
    return solve(row, col+2, cnt);
  }
  if (ladder[row][col+1] == -1) {
    return solve(row, col+3, cnt);
  }

  int ret = INF;
  ret = min(ret, solve(row, col+1, cnt));
  ladder[row][col] = -1;
  ladder[row][col+1] = 1;
  ret = min(ret, solve(row, col+2, cnt+1));
  ladder[row][col] = ladder[row][col+1] = 0;
  return ret;
}

int main() {
  scanf("%d %d %d", &N, &M, &H);
  memset(ladder, 0, sizeof(ladder));

  while(M--) {
    int a, b;
    scanf("%d %d", &a, &b);
    ladder[a][b] = -1;
    ladder[a][b+1] = 1;
  }

  int ret = solve(1, 1, 0);
  printf("%d\n", ret < INF ? ret : -1);
}