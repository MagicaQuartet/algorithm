#include<cstdio>
#include<cstring>
using namespace std;
int N, es[24];
int main() {
  scanf("%d", &N);
  memset(es, 0, sizeof(es));
  while(N--) {
    int W, X;
    scanf("%d%d", &W, &X);
    es[X] += W;
  }
  int ans = 0;
  int sum = 0;
  for (int i=0; i<=8; i++) {
    ans += es[i];
    sum += es[i];
  }
  for (int i=1; i<=23; i++) {
    int j = (i+8)%24;
    sum = sum - es[i-1] + es[j];
    if (ans < sum) {
      ans = sum;
    }
  }
  printf("%d\n", ans);
}
