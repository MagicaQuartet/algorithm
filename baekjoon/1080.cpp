#include<cstdio>
int N, M, ans;
int dx[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2}, dy[9] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
char A[50][50], B[50][50];
int main() {
  scanf("%d %d", &N, &M);
  ans = 0;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      while((A[i][j]=getchar())=='\n');
    }
  }
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      while((B[i][j]=getchar())=='\n');
    }
  }
  
  for (int i=0; i+2<N; i++) {
    for (int j=0; j+2<M; j++) {
      if (A[i][j] != B[i][j]) {
        for (int k=0; k<9; k++) {
          A[i+dx[k]][j+dy[k]] = '0' + '1' - A[i+dx[k]][j+dy[k]];
        }
        ans++;
      }
    }
  }
  
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      if (A[i][j] != B[i][j]) {
        ans = -1;
        break;
      }
    }
  }
  
  printf("%d\n", ans);
}