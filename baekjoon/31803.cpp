#include<cstdio>
#define ll long long
using namespace std;
int N;
int main() {
  scanf("%d", &N);
  ll ans = 1;
  for (int i=N; i>=2; i=i-2) {
    if (i > N/2) {
      ans *= i;
    }
    if (i-1 > N/2) {
      ans *= i-1;
    }
    ans /= 2;
  }
  printf("%lld\n", ans);
}
