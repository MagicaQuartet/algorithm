#include<cstdio>
int main() {
  int T, n;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    for (int i=0; n>0; i++) {
      if (n%2 == 1) {
        printf("%d ", i);
      }
      n >>= 1;
    }
  }
}