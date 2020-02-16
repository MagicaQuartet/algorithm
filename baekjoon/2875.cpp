#include<cstdio>
int N, M, K, ans;
int main() {
  scanf("%d %d %d", &N, &M, &K);
  
  if (N >= 2*M) {
    K -= N-2*M;
    N = 2*M;
  }
  else {
    K -= M-N/2;
    M = N/2;
    if (N%2) {
      N -= 1;
      K -= 1;
    }
  }
  
  ans = M - (K>0 ? (K-1)/3 + 1 : 0);
  printf("%d\n", ans);
}

/*
  우선 N=2*M이 되도록 N, M, K 값을 조정한 뒤에 남은 K를 가지고 가능한 팀 수를 구한다.
*/