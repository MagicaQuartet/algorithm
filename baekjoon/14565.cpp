#include<cstdio>
#include<utility>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
ll N, A;
pair<ll, pll > xGCD(ll a, ll b) {
  if (b == 0) {
    return {a, {1, 0}};
  }
  pair<ll, pll > ret = xGCD(b, a%b);
  return {ret.first, {ret.second.second, ret.second.first-(a/b)*ret.second.second}};
}
ll mod_inverse(ll a, ll n) {
  pair<ll, pll > ret = xGCD(a, n);
  if (ret.first > 1) {
    return -1;
  }
  return (ret.second.first+n)%n;
}
int main() {
  scanf("%lld%lld", &N, &A);
  printf("%lld %lld\n", N-A, mod_inverse(A, N));
}
