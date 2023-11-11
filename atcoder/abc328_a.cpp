#include<cstdio>
using namespace std;
int N, X;
int main() {
  int ans = 0;
  scanf("%d%d", &N, &X);
  while(N--) {
    int s;
    scanf("%d", &s);
    if (s <= X) {
      ans += s;
    }
  }
  printf("%d\n", ans);
}
