#include<cstdio>
#define INF 987654321

int N, M, A, B, ans, sumMin;
int distance[101][101];

int main() {
  scanf("%d %d", &N, &M);
  
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      distance[i][j] = INF;
    }
  }
  
  for (int i=0; i<M; i++) {
    scanf("%d %d", &A, &B);
    distance[A][B] = 1;
    distance[B][A] = 1;
  }
  
  for (int k=1; k<=N; k++) {
    for (int i=1; i<=N; i++) {
      for (int j=1; j<=N; j++) {
        if (distance[i][j] > distance[i][k] + distance[k][j]) {
          distance[i][j] = distance[i][k] + distance[k][j];
        }
      }
    }
  }
  
  ans = 0;
  sumMin = INF;
  for (int i=1; i<=N; i++) {
    int sum = 0;
    for (int j=1; j<=N; j++) {
      if (distance[i][j] != INF) {
        sum += distance[i][j];
      }
    }
    
    if (sumMin > sum) {
      ans = i;
      sumMin = sum;
    }
  }
  
  printf("%d\n", ans);
}