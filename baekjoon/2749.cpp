#include<cstdio>
#include<vector>
using namespace std;
#define ll long long
ll N;
int a, b, tmp;
int main() {
  scanf("%lld", &N);
  if (N == 0) {
    printf("0\n");
    return 0;
  }
  if (N == 1) {
    printf("1\n");
    return 0;
  }
  N %= 1500000;
  a = 1;
  b = 0;
  for (ll i=2; i<=N; i++) {
    tmp = a;
    a += b;
    b = tmp;
    a %= 1000000;
  }
  printf("%d\n", a);
}

// 피사노 주기
