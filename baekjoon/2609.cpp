#include<cstdio>

int x, y;

int GCD(int k, int l) {
  int i;
  int minVal = k < l ? k : l;
  for (i=minVal; i>=1; i--) {
    if (k%i==0 && l%i==0) {
      break;
    }
  }
  return i;
}

int main() {
  scanf("%d %d", &x, &y);
  int gcd = GCD(x,  y);
  printf("%d\n%d\n", gcd, x*y/gcd);
}