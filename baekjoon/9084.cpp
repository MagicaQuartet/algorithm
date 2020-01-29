#include<cstdio>
#include<cstring>
int T, N, M, coin[20], cache[10001];
int main() {
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
      scanf("%d", &coin[i]);
    }
    scanf("%d", &M);
    memset(cache, 0, 4*(M+1));
    
    for (int i=0; i<N; i++) {
      cache[coin[i]]++;
      for (int j=coin[i]+1; j<=M; j++) {
        cache[j] += cache[j-coin[i]];
      }
    }
    printf("%d\n", cache[M]);
  }
}