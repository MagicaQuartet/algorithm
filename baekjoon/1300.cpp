#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
ll N, K;
int main() {
  scanf("%lld %lld", &N, &K);
  ll head = 1;
  ll tail = N*N;
  ll ans = tail;
  while (head < tail) {
    ll mid = (head+tail)/2;
    ll cnt = 0;
    int found = 0;
    for (int i=1; i<=N; i++) {
      if (i*N >= mid && mid%i == 0) {
        found = 1;
      }
      cnt += min(mid/i, (ll)N);
    }
    if (cnt < K) {
      head = mid+1;
    }
    else {
      if (found) {
        ans = mid;
      }
      tail = mid;
    }
  }
  printf("%lld\n", ans);
}
