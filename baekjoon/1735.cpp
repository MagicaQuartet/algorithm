#include<cstdio>
#include<algorithm>
using namespace std;
int A, B, C, D;

int getGCD(int a, int b) {
  return b > 0 ? getGCD(b, a%b) : a;
}

int main() {
  scanf("%d %d %d %d", &A, &B, &C, &D);
  int d = B*D;
  int n = A*D + B*C;
  int gcd = getGCD(max(n, d), min(n, d));

  printf("%d %d\n", n/gcd, d/gcd);
}