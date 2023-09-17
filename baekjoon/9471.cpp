#include<cstdio>
int P, N, M, ans;
int a, b, tmp;
int brute() {
  a = 1;
  b = 1;
  for (int i=3; i <= 500005; i++) {
    tmp = a;
    a += b;
    b = tmp;
    a %= M;
    if (a == 0 && b == 1) {
      return i;
    }
  }
  return -1;
}
int main() {
  scanf("%d", &P);
  while(P--) {
    scanf("%d %d", &N, &M);
    printf("%d %d\n", N, brute());
  }
}
