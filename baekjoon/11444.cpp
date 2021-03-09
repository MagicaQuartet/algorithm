#include <cstdio>
#include <utility>
using namespace std;
#define INF 1000000007
#define ll long long
#define pplpl pair<pair<ll, ll>, pair<ll, ll> >
#define mp make_pair
ll N;
pplpl matmul(pplpl A, pplpl B) {
  ll a = A.first.first * B.first.first + A.first.second * B.second.first;
  ll b = A.first.first * B.first.second + A.first.second * B.second.second;
  ll c = A.second.first * B.first.first + A.second.second * B.second.first;
  ll d = A.second.first * B.first.second + A.second.second * B.second.second;
  return mp(mp(a % INF, b % INF), mp(c % INF, d % INF));
}
pplpl solve(ll n) {
  if (n == 0) {
    return mp(mp(1, 0), mp(0, 1));
  }
  if (n == 1) {
    return mp(mp(1, 1), mp(1, 0));
  }

  pplpl divided = solve(n / 2);
  pplpl ret = matmul(divided, divided);
  if (n % 2) {
    ret = matmul(ret, solve(1));
  }
  return ret;
}
int main() {
  scanf("%lld", &N);
  pplpl ret = solve(N-1);
  printf("%lld\n", (ret.second.first+ret.second.second) % INF);
}
