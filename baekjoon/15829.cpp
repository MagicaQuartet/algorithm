#include<iostream>
#include<string>
using namespace std;
#define M 1234567891
#define R 31
#define ll long long
int L;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> L >> s;
  ll ans = 0;
  ll factor = 1;
  for (char c: s) {
    int val = c-'a'+1;
    ans += val*factor;
    ans %= M;
    factor = (factor*R)%M;
  }
  cout << ans << "\n";
}