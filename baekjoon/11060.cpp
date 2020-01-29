#include<cstdio>
#include<cstring>
int N, num, cache[1000];
int main() {
  scanf("%d", &N);
  memset(cache, -1, 4*N);
  cache[0] = 0;
  for (int i=0; i<N; i++) {
    scanf("%d", &num);
    if (cache[i] != -1) {
      for (int j=1; j<=num; j++) {
        if (i+j < N && (cache[i+j] == -1 || cache[i]+1 < cache[i+j])) {
          cache[i+j] = cache[i]+1;
        }
      }
    }
  }
  printf("%d\n", cache[N-1]);
}