#include<cstdio>
#include<algorithm>
#define MAX 1000000001
using namespace std;
int N, M, K, cache[201][201];
void preCalc() {
  for (int i=0; i<=N+M; i++) {
    cache[i][0] = 1;
  }
  cache[1][1] = 1;
  for (int i=2; i<=N+M; i++) {
    for (int j=1; j<=i; j++) {
      cache[i][j] = min(MAX, cache[i-1][j-1] + cache[i-1][j]);
    }
  }
}
void solve(int n, int m) {
  if (n==0) {
    for (int i=0; i<m; i++) {
      printf("%c", 'z');
    }
    return;
  }
  if (m==0) {
    for (int i=0; i<n; i++) {
      printf("%c", 'a');
    }
    return;
  }
  
  if (cache[n+m-1][n-1] >= K) {
    printf("%c", 'a');
    solve(n-1, m);
  }
  else {
    K -= cache[n+m-1][n-1];
    printf("%c", 'z');
    solve(n, m-1);
  }
}
int main() {
  scanf("%d %d %d", &N, &M, &K);
  preCalc();
  if (cache[N+M][N] >= K) {
    solve(N, M);
    printf("\n");
  }
  else {
    printf("%d\n", -1);
  }
}

/* 종만북에 있는 예제와 똑같은 문제이다. 먼저 이항계수값을 계산해 놓은 다음, 각 선택지 내에 skip번 째 문자열이 들어있을지 판단하여 그때그때 문자를 출력한다. */
/* 근데 101*101 2차원 dp로도 풀이가 가능한가보다.... 억덕게?? */