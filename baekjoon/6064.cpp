#include<cstdio>
int T, N, M, x, y;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d %d %d", &M, &N, &x, &y);
    int ans = -1;
    for (int i=0; i<=N; i++) {
      if ((M*i+x-1)%N == y-1) {
        ans = M*i+x-1+1;
        break;
      }
    }
    printf("%d\n", ans);
  }
}
