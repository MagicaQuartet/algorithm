#include<cstdio>
int N, n, M, S, E, num[2000], cache[2000][2000];
int search(int start, int end) {
  if (start >= end) {
    return 1;
  }
  if (cache[start][end] != -1) {
    return cache[start][end];
  }
  
  int ret;
  if (num[start] == num[end]) {
    ret = search(start+1, end-1);
  }
  else {
    ret = 0;
  }
  cache[start][end] = ret;
  return ret;
}
int main() {
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    scanf("%d", &n);
    num[i] = n;
    for (int j=0; j<N; j++) {
      cache[i][j] = -1;
    }
  }
  
  scanf("%d", &M);
  while(M--) {
    scanf("%d %d", &S, &E);
    printf("%d\n", S < E ? search(S-1, E-1) : search(E-1, S-1));
  }
}