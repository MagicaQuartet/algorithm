#include<iostream>
#include<string>
using namespace std;

string s;
int ans = 0;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> s;

  int offset = 1;
  for (int i=0; i < s.size(); i++) {
    char c = s[s.size()-1-i];
    int num = 0;
    if ('0' <= c && c <= '9'){
      num = c-'0';
    }
    else if ('A' <= c && c <= 'Z') {
      num = 10 + c - 'A';
    }
    ans += num * offset;
    offset *= 16;
  }
  cout << ans;
}
