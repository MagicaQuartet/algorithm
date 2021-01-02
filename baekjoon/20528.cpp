#include<iostream>
#include<string>
using namespace std;
string s;
int n, ans;
char c;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> s;
  c = s[0];
  ans = 1;
  while(--n) {
    cin >> s;
    if (c != s[0]) {
      ans = 0;
      break;
    }
  }
  cout << ans << "\n";
}