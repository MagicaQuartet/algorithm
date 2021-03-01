#include <iostream>
#include <string>
using namespace std;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    ans++;
    if (c == 'c') {
      if (i < s.size() - 1 && (s[i+1] == '=' || s[i+1] == '-')) {
        i++;
      }
    }
    else if (c == 'd') {
      if (i < s.size() - 1 && s[i+1] == '-') {
        i++;
      }
      else if (i < s.size() - 2 && s[i+1] == 'z' && s[i+2] == '=') {
        i += 2;
      }
    }
    else if (i < s.size() - 1 && (c == 'l' || c == 'n') && s[i+1] == 'j') {
      i++;
    }
    else if (i < s.size() - 1 && (c == 's' || c == 'z') && s[i+1] == '=') {
      i++;
    }
  }
  cout << ans << "\n";
}