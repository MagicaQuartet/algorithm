#include<cstdio>
using namespace std;
#define ll long long
ll N;
ll power(ll n, ll cnt) {
  ll ret = 1;
  for (ll i=1; i<=cnt; i++) {
    ret *= n;
  }
  return ret;
}
int main() {
  scanf("%lld", &N);
  ll ans = -1;
  for (ll i=1; i<=N; i++) {
    ll p = power(i, i);
    if (p > N) {
      break;
    }
    if (p == N) {
      ans = i;
      break;
    }
  }
  printf("%lld\n", ans);
}
