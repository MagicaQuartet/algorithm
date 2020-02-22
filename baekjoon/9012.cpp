#include<iostream>
#include<cstring>
#include<stack>
#include<string>
using namespace std;
int N;
stack<char> stk;
string str;
int main() {
  cin.sync_with_stdio(false);
  cin >> N;
  while (N--) {
    cin >> str;
    for (auto c : str) {
      if (c == '(') {
        stk.push(c);
      }
      else {
        if (stk.empty()) {
          stk.push(c);
          break;
        }
        else {
          stk.pop();
        }
      }
    }
    
    if (stk.empty()) {
      printf("YES\n");
    }
    else {
      printf("NO\n");
      while(!stk.empty()) stk.pop();
    }
  }
}

/*
  대표적인 스택 연습문제
*/