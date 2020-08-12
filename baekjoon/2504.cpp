#include<iostream>
#include<string>
#include<stack>
using namespace std;

string s;
int ans, level;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  stack<char> stk;
  stack<pair<int, int> > calc;

  cin >> s;
  level = 0;
  for(auto c: s) {
    if (c == '(') {
      stk.push(c);
      level++;
    }
    else if (c == '[') {
      stk.push(c);
      level++;
    }
    else if (c == ')') {
      if (stk.empty() || stk.top() != '(') {
        cout << 0 << endl;
        return 0;
      }
      stk.pop();

      int val = 0;
      while(!calc.empty() && calc.top().second == level+1) {
        val += calc.top().first;
        calc.pop();
      }
      calc.push({(val > 0) ? 2*val : 2, level--});
    }
    else if (c == ']') {
      if (stk.empty() || stk.top() != '[') {
        cout << 0 << endl;
        return 0;
      }
      stk.pop();

      int val = 0;
      while(!calc.empty() && calc.top().second == level+1) {
        val += calc.top().first;
        calc.pop();
      }
      calc.push({(val > 0) ? 3*val : 3, level--});
    }
    else {
      cout << 0 << endl;
      return 0;
    }
  }

  ans = 0;
  if (stk.empty()) {
    ans = 0;
    while(!calc.empty()) {
      ans += calc.top().first;
      calc.pop();
    }
  }

  cout << ans << "\n";
}