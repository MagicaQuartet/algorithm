#include<cstdio>
#define ll long long
ll S, acc, ans;
int main() {
  scanf("%lld", &S);
  acc = 0;

  for (ll cnt = 1; cnt <= S; cnt++) {
    acc += cnt;
    if (acc > S) {
      ans = cnt - 1;
      break;
    }
  }
  printf("%lld\n", ans);
}
