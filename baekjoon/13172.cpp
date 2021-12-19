#include<cstdio>
#define ll long long
#define X 1000000007

int M;
ll b, a;

ll sq(ll n, int r) {
  ll ans = 1;
  while (r) {
    if (r%2) {
      ans = (ans * n) % X;
    }
    n = (n * n) % X;
    r >>= 1;
  }
  return ans;
}

int main() {
  scanf("%d", &M);
  ll ans = 0;
  while (M--) {
    scanf("%lld %lld", &b, &a);
    ans += (a * sq(b, X-2)) % X;
    ans %= X;
  }
  printf("%lld\n", ans);
}
