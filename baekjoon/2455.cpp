#include<cstdio>
#include<algorithm>
using namespace std;
int cur, ans, a, b;
int main() {
  cur = ans = 0;
  for (int i=0; i<4; i++) {
    scanf("%d %d", &a, &b);
    cur += (b-a);
    ans = max(ans, cur);
  }
  printf("%d\n", ans);
}