#include<cstdio>
#define INF 987654321

int N, M;
int connected[101][101];

int main() {
  scanf("%d %d", &N, &M);
  
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      connected[i][j] = 0;
    }
    connected[i][i] = 1;
  }
  
  for (int i=0; i<M; i++) {
    int p, q;
    scanf("%d %d", &p, &q);
    
    connected[p][q] = 1;
  }
  
  for (int k=1; k<=N; k++) {
    for (int i=1; i<=N; i++) {
      for (int j=1; j<=N; j++) {
        connected[i][j] = (connected[i][j] || (connected[i][k] && connected[k][j])) ? 1 : 0;
      }
    }
  }
  
  for (int i=1; i<=N; i++) {
    int cnt = 0;
    for (int j=1; j<=N; j++) {
      if (!connected[i][j] && !connected[j][i]) {
        cnt++;
      }
    }
    printf("%d\n", cnt);
  }
}

/*
  플로이드-와샬 알고리즘 사용
*/