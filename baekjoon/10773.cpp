#include<cstdio>
#include<stack>
using namespace std;
int K, num;
int main() {
  scanf("%d", &K);
  stack<int> stk;
  while(K--) {
    scanf("%d", &num);
    if (num) stk.push(num);
    else stk.pop();
  }
  long long ans = 0;
  while (!stk.empty()) {
    ans += stk.top();
    stk.pop();
  }
  printf("%lld\n", ans);
}