#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string raw, s;
int r, p, n, A[4000010];
long long ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> raw;
  s = "";
  for (auto c: raw) {
    s += '#';
    s += c;
  }
  n = s.size();
  r = p = -1;
  ans = 0;
  for (int i=0; i<n; i++) {
    A[i] = (i <= r) ? min(r-i, A[2*p-i]) : 0;
    while (i-A[i]-1 >= 0 && i+A[i]+1 < n && s[i-A[i]-1] == s[i+A[i]+1]) {
      A[i]++;
    }
    if (r < i+A[i]) {
      r = i+A[i];
      p = i;
    }
    ans += (s[i] == '#') ? (A[i]+1)/2 : A[i]/2+1;
  }
  printf("%lld\n", ans);
}