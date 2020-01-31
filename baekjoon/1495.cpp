#include<cstdio>
#include<algorithm>
using namespace std;
int N, S, M, V[100], cache[1001][101];
int solve(int volume, int idx) {
  if (volume < 0 || volume > M) {
    return -1;
  }
  if (idx == N) {
    return volume;
  }
  if (cache[volume][idx] != -2) {
    return cache[volume][idx];
  }
  
  int ret = max(solve(volume+V[idx], idx+1), solve(volume-V[idx], idx+1));
  cache[volume][idx] = ret;
  return ret;
}

int main() {
  scanf("%d %d %d", &N, &S, &M);
  for (int i=0; i<=M; i++) {
    for (int j=0; j<=N; j++) {
      cache[i][j] = -2;
    }
  }
  for (int i=0; i<N; i++) {
    scanf("%d", &V[i]);
  }
  
  printf("%d\n", solve(S, 0));
}

/* 2차원 dp 배열을 만들어서 풀었는데, 다른 사람의 풀이를 보니 1001*101 크기의 배열을 가지고 있을 필요 없이 입력을 받을 때마다 쓰는 임시 1차원 dp 배열과 임시 dp 배열의 결과를 반영하는 진짜 1차원 dp 배열만 있으면 가능한 문제였다. */