#include<iostream>
#include<string>
#include<stack>
using namespace std;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  while(1) {
    getline(cin, s);
    if (s.size() == 1 && s[0] == '.') break;
    stack<char> stk;
    for (auto c: s) {
      if (c=='('||c== '[') stk.push(c);
      else if (c==')') (!stk.empty()&&stk.top()=='(')?stk.pop():stk.push(c);
      else if (c==']') (!stk.empty()&&stk.top()=='[')?stk.pop():stk.push(c);
    }
    cout << (stk.empty()?"yes":"no") << "\n";
  }
}