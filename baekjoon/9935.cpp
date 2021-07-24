#include<iostream>
#include<string>
#include<stack>
#include<utility>
using namespace std;
typedef pair<char, int> pci;
string str, bomb;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> str >> bomb;
  stack<pci > stk;
  stk.push(make_pair('\0', bomb.size()));
  for (int i=str.size()-1; i>=0; i--) {
    char c = str[i];
    int idx = stk.empty() ? bomb.size()-1 : stk.top().second-1;
    if (c != bomb[idx]) {
      idx = bomb.size()-1;
      if (c != bomb[idx]) {
        idx = bomb.size();
      }
      stk.push(make_pair(c, idx));
      continue;
    }
    
    if (idx != 0) {
      stk.push(make_pair(c, idx));
      continue;
    }

    for (idx=1; idx<bomb.size(); idx++) {
      stk.pop();
    }
  }

  if (stk.top().first == '\0') {
    cout << "FRULA\n";
    return 0;
  }

  while (!stk.empty()) {
    if (stk.top().first == '\0') {
      break;
    }
    cout << stk.top().first;
    stk.pop();
  }
  cout << "\n";
}
