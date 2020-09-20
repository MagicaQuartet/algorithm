#include<cstdio>
#include<stack>
#include<vector>
using namespace std;

stack<char> ops;
vector<char> result;

int main() {
  char c;

  while ((c=getchar()) != '\n') {
    if (c == '(') {
      ops.push(c);
    }
    else if (c == ')') {
      while (ops.top() != '(') {
        result.push_back(ops.top());
        ops.pop();
      }
      ops.pop();
    }
    else if (c == '+' || c == '-') {
      while (!ops.empty() && ops.top() != '(') {
        result.push_back(ops.top());
        ops.pop();
      }
      ops.push(c);
    }
    else if (c == '*' || c == '/') {
      if (!ops.empty() && ops.top() != '(' && ops.top() != '+' && ops.top() != '-') {
        result.push_back(ops.top());
        ops.pop();
      }
      ops.push(c);
    }
    else {
      result.push_back(c);
    }
  }

  while (!ops.empty()) {
    result.push_back(ops.top());
    ops.pop();
  }

  for (auto c: result) {
    printf("%c", c);
  }
  printf("\n");
}