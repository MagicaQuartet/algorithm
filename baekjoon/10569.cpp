#include<cstdio>
int T, V, E;
int main() {
  scanf("%d", &T);
  while(T--) {
    scanf("%d %d", &V, &E);
    printf("%d\n", 2-V+E);
  }
}
