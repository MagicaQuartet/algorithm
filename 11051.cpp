#include<cstdio>

using namespace std;

int main() {
  int N, K;
  scanf("%d %d", &N, &K);
  
  int **foo = new int*[N+1];
  for (int i=0; i<=N; i++) {
    foo[i] = new int[K+1];
  }
  
  for (int i=1; i<=N; i++) {
    foo[i][0] = 1;
    
    if (i <= K)
      foo[i][i] = 1;
  }
  
  for (int i=2; i<=N; i++) {
    for (int j=1; j<=K && j<i; j++) {
      foo[i][j] = (foo[i-1][j-1] + foo[i-1][j])%10007;
    }
  }
  
  printf("%d\n", foo[N][K]);
  
  return 0;
}

/* 이항계수의 특성에서 착안하여 2차원 Dynamic programming */