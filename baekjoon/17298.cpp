#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
int N, arr[1000010], ans[1000010];
int main() {
  scanf("%d", &N);
  stack<int> stk;
  memset(ans, -1, sizeof(ans));
  for (int i=0; i<N; i++) {
    scanf("%d", arr+i);
    while (!stk.empty() && arr[stk.top()] < arr[i]) {
      ans[stk.top()] = arr[i];
      stk.pop();
    }
    stk.push(i);
  }
  for (int i=0; i<N; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
}