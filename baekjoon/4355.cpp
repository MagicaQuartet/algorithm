#include<cstdio>
#include<vector>
#define ll long long
using namespace std;
ll n, _n, ans;
// 소수 목록 구하기
int main() {
  while (1) {
    scanf("%lld", &n);
    if (!n) break;
    _n = n;
    ans = 1;
    bool prime = true;
    for (ll i = 2; i * i <= n; i++) {
      if (_n == 1) {
        break;
      }
      if (_n % i) {
        continue;
      }
      prime = false;
      while (_n % i == 0) {
        ans *= i;
        _n /= i;
      }
      ans = (ans / i) * (i - 1);
    }
    if (prime) {
      ans = n - 1;
    }
    printf("%lld\n", ans);
  }
}