#include<cstdio>
#include<cmath>
long long X, Y, Z;
int main() {
  while (scanf("%lld %lld", &X, &Y) != EOF) {
    Z = 100*Y/X;
    if (Z >= 99) printf("-1\n");
    else printf("%lld\n", (X*Z+X-100*Y)%(99-Z) == 0 ? (X*Z+X-100*Y)/(99-Z) : (X*Z+X-100*Y)/(99-Z)+1);
  }
}

// 100Y/X = Z + k
// 100Y = XZ + Xk

// 100(Y+p) / (X+p) = Z+1
// 100Y + 100p = XZ+X+Zp+p
// p(99-Z) = -100Y+XZ+X

//p >= (XZ - 100Y) / (99-Z)