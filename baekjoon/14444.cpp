#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int A[200010], r, p, ans;
string raw, s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> raw;
  s = "";
  for (auto c: raw) {
    s += '#';
    s += c;
  }
  s += '#';
  r = p = -1;
  ans = 0;
  for (int i=0; i<s.size(); i++) {
    if (i <= r) A[i] = min(r-i, A[2*p-i]);
    else A[i] = 0;
    while (i-A[i]-1 >= 0 && i+A[i]+1 < s.size() && s[i-A[i]-1] == s[i+A[i]+1]) A[i]++;
    ans = max(ans, (s[i] == '#') ? ((A[i]+1)/2)*2 : 1 + (A[i]/2)*2);
    if (r < i+A[i]) {
      r = i+A[i];
      p = i;
    }
  }
  cout << ans << "\n";
}