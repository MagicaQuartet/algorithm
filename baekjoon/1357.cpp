#include<cstdio>
int X, Y;
int rev(int n) {
  int ret = 0;
  while(n) {
    ret *= 10;
    ret += (n%10);
    n /= 10;
  }
  return ret;
}
int main() {
  scanf("%d %d", &X, &Y);
  printf("%d\n", rev(rev(X)+rev(Y)));
}
