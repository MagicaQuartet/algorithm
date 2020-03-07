#include<cstdio>
#include<cstring>
int N, rows[15], diagonal1[30], diagonal2[30];
int solve(int row) {
  if (row == N) {
    return 1;
  }
  
  int ret = 0;
  for (int i=0; i<N; i++) {
    if (rows[i] == 1 || diagonal1[row + i] == 1 || diagonal2[row+N-1-i] == 1) {
      continue;
    }
    
    rows[i] = 1;
    diagonal1[row + i] = 1;
    diagonal2[row+N-1-i] = 1;
    ret += solve(row+1);
    rows[i] = 0;
    diagonal1[row + i] = 0;
    diagonal2[row+N-1-i] = 0;
  }
  
  return ret;
}
int main() {
  scanf("%d", &N);
  memset(rows, 0, sizeof(rows));
  memset(diagonal1, 0, sizeof(diagonal1));
  memset(diagonal2, 0, sizeof(diagonal2));
  printf("%d\n", solve(0));
}