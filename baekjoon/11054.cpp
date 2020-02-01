#include<cstdio>
#include<algorithm>
using namespace std;
int N, A[1000], cache[1000], invCache[1000];
int solve(int idx) {
  if (idx == N) {
    return 0;
  }
  if (idx != -1 && cache[idx] != -1) {
    return cache[idx];
  }
  
  int ret = 1;
  for (int i=idx+1; i<N; i++) {
    if (idx == -1 || A[idx] > A[i]) {
      ret = max(ret, solve(i)+1);
    }
  }
  if (idx > -1) {
    cache[idx] = ret;
  }
  return ret;
}
int invSolve(int idx) {
  if (idx < 0) {
    return 0;
  }
  if (idx != N && invCache[idx] != -1) {
    return invCache[idx];
  }
  
  int ret = 1;
  for (int i=idx-1; i>=0; i--) {
    if (idx == N || A[idx] > A[i]) {
      ret = max(ret, invSolve(i)+1);
    }
  }
  if (idx < N) {
    invCache[idx] = ret;
  }
  return ret;
}
int main() {
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    scanf("%d", &A[i]);
    cache[i] = invCache[i] = -1;
  }
  
  solve(-1);
  invSolve(N);
  int ret = 0;
  for (int i=0; i<N; i++) {
    ret = max(ret, cache[i]+invCache[i]-1);
  }
  printf("%d\n", ret);
}

/* i번째 자리에서 시작하여 왼쪽/오른쪽 방향으로 진행하며 만들 수 있는 LDS의 길이를 합한 값 중 최댓값을 찾는다. */