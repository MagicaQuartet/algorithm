#include<cstdio>
using namespace std;
int N, S, M, L, XL, XXL, XXXL, T, P;
int s(int n) {
  return (n+T-1)/T;
}
int main() {
  scanf("%d %d %d %d %d %d %d %d %d", &N, &S, &M, &L, &XL, &XXL, &XXXL, &T, &P);
  printf("%d\n", s(S)+s(M)+s(L)+s(XL)+s(XXL)+s(XXXL));
  printf("%d %d\n", N/P, N%P);
}
