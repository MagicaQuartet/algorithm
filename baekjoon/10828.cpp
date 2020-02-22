#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
int N, num;
char command[6];
stack<int> stk;
int main() {
  scanf("%d", &N);
  while (N--) {
    scanf("%s", command);
    if (!strncmp(command, "push", 4)) {
      scanf("%d", &num);
      stk.push(num);
    }
    else if (!strncmp(command, "top", 3)) {
      printf("%d\n", stk.empty() ? -1 : stk.top());
    }
    else if (!strncmp(command, "size", 4)) {
      printf("%d\n", stk.size());
    }
    else if (!strncmp(command, "empty", 5)) {
      printf("%d\n", stk.empty());
    }
    else if (!strncmp(command, "pop", 3)) {
      printf("%d\n", stk.empty() ? -1 : stk.top());
      if (!stk.empty())  stk.pop();
    }
  }
}