#include<iostream>
#include<string>
#include<stack>
using namespace std;

string s;
stack<char> cstk;
stack<int> nstk;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> s;
  int ans = 0;
  for (auto c: s) {
    if (c == '(') {
      cstk.push(c);
      nstk.pop();
    }
    else if (c == ')') {
      int sublen = 0;
      while (cstk.top() != '(') {
        sublen += nstk.top();
        nstk.pop();
        cstk.pop();
      }
      cstk.pop();
      sublen *= (cstk.top() - '0');
      cstk.pop();
      nstk.push(sublen);
      cstk.push('x');
    }
    else {
      cstk.push(c);
      nstk.push(1);
    }
  }

  while (!nstk.empty()) {
    ans += nstk.top();
    nstk.pop();
  }
  cout << ans << '\n';
}
