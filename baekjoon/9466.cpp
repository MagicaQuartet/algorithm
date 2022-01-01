#include<cstdio>
#include<stack>
using namespace std;
int T, n, choice[100010];
enum Status {NONE, SEARCHING, TEAM, NOTEAM};
Status status[100010];

int main() {
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
      scanf("%d", &choice[i]);
      status[i] = NONE;
    }
    stack<int> stk;
    for (int i=1; i<=n; i++) {
      if (status[i] != NONE) {
        continue;
      }
      int c = i;
      while (status[c] == NONE) {
        stk.push(c);
        status[c] = SEARCHING;
        c = choice[c];
      }
      if (status[c] == SEARCHING) {
        while (1) {
          int t = stk.top();
          status[t] = TEAM;
          stk.pop();
          if (c == t) {
            break;
          }
        }
      }
      while (!stk.empty()) {
        status[stk.top()] = NOTEAM;
        stk.pop();
      }
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
      ans += (status[i] == NOTEAM);
    }
    printf("%d\n", ans);
  }
}
