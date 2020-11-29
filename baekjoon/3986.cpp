#include<iostream>
#include<string>
#include<stack>
using namespace std;

int N, cnt;
string s;
stack<char> stk;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  cnt = 0;
  while(N--) {
    while(!stk.empty()) {
      stk.pop();
    }
    cin >> s;
    for (auto c: s) {
      if (!stk.empty() && stk.top() == c) {
        stk.pop();
      }
      else {
        stk.push(c);
      }
    }
    if (stk.empty()) {
      cnt++;
    }
  }
  cout << cnt << "\n";
}