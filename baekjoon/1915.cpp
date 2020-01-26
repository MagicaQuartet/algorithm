#include<cstdio>
int n, m, board[1000][1000], dp[1000][1000], max=0;
char num;
int search(int x, int y) {
  if (x >= n || y >= m) {
    return 0;
  }
  if (board[x][y] == 0) {
    return 0;
  }
  if (dp[x][y] != -1) {
    return dp[x][y];
  }
  
  int ret, sub1, sub2, sub3;
  sub1 = search(x+1, y);
  sub2 = search(x+1, y+1);
  sub3 = search(x, y+1);
  ret = sub1 < sub2 ? sub1 < sub3 ? sub1 : sub3 : sub2 < sub3 ? sub2 : sub3;
  dp[x][y] = ++ret;
  if (max < ret) {
    max = ret;
  }
  return ret;  
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      while((num=getchar())=='\n' || num==EOF);
      board[i][j] = num - 0x30;
      dp[i][j] = -1;
    }
  }
  
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      search(i, j);
    }
  }
  printf("%d\n", max*max);
}

/* 입력을 모두 받은 뒤에, 각 지점을 정사각형의 왼쪽 위 꼭지점으로 간주하여 그 점을 포함하는 가장 큰 정사각형의 크기를 DP로 찾는 풀이이다. 다른 풀이를 보니 더 효율적인 방법이 가능한 듯 하다. */

/* (추가) ...! 나는 왼쪽 위 꼭지점을 기준으로 찾아야해서 모든 입력을 다 받은 후에 탐색이 가능했던 거고 반대로 오른쪽 아래 꼭지점을 기준으로 하면 입력을 받는 동시에 해결을 할 수 있는 것이었다! */