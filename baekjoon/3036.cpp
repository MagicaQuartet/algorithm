#include<cstdio>
#include<algorithm>
using namespace std;
int N, A, B, X1, X2;
int getGCD(int _a, int _b) {
  int a = max(_a, _b);
  int b = min(_a, _b);
  int r = a%b;
  int ans = b;
  while (r) {
    a = b;
    b = r;
    r = a%b;
    ans = b;
  }
  return ans;
}
int main() {
  scanf("%d %d", &N, &X2);
  A = B = 1;
  for (int i=2; i<=N; i++) {
    X1 = X2;
    scanf("%d", &X2);
    A *= X1;
    B *= X2;
    int gcd = getGCD(A, B);
    A /= gcd;
    B /= gcd;
    printf("%d/%d\n", A, B);
  }
}