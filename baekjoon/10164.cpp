#include<cstdio>
int N, M, K, ans, cache[15][15];
int main() {
  scanf("%d %d %d", &N, &M, &K);
  for (int i=0; i<N; i++) {
    cache[i][0] = 1;
  }
  for (int j=0; j<M; j++) {
    cache[0][j] = 1;
  }
  
  for (int i=1; i<N; i++) {
    for (int j=1; j<M; j++) {
      cache[i][j] = cache[i-1][j] + cache[i][j-1];
    }
  }
  
  if (K == 0) {
    ans = cache[N-1][M-1];
  }
  else {
    int x1, y1, x2, y2;
    x1 = (K-1)/M;
    y1 = (K-1)%M;
    x2 = N - x1 - 1;
    y2 = M - y1 - 1;
    ans = cache[x1][y1]*cache[x2][y2];
  }
  printf("%d\n", ans);
}

/* 초등학교 때 경로 경우의 수 구하는 방법이 사실 동적 계획법이었구나! 그 때는 제대로 모르고 그냥 쓴거 같았는데... */