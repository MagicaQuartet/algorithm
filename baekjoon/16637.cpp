#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
int N;
string s;
ll calc(ll a, ll b, char c) {
  if (c == '+') {
    return a+b;
  }
  else if (c == '-') {
    return a-b;
  }
  else {
    return a*b;
  }
}
ll solve(vector<ll>& vl, vector<char>& vc, int idx, bool flag) {
  if (idx >= N-1) {
    vl.push_back(flag ? 0 : s[N-1]-'0');
    ll ret = vl[0];
    for (int i=1; i<vl.size(); i++) {
      ret = calc(ret, vl[i], vc[i-1]);
    }
    vl.pop_back();
    return ret;
  }

  ll ret;
  // no group
  vl.push_back(s[idx]-'0');
  vc.push_back(s[idx+1]);
  ret = solve(vl, vc, idx+2, false);
  vc.pop_back();
  vl.pop_back();
  // group
  ll d = calc(s[idx]-'0', s[idx+2]-'0', s[idx+1]);
  vl.push_back(d);
  vc.push_back(idx+2 == N-1 ? '+' : s[idx+3]);
  ret = max(solve(vl, vc, idx+4, idx+2 == N-1), ret);
  vc.pop_back();
  vl.pop_back();
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> s;
  vector<ll> vl;
  vector<char> vc;
  printf("%lld\n", solve(vl, vc, 0, false));
}
