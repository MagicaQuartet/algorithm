#include<cstdio>
#define ll long long
ll S, acc, ans;
int main() {
  scanf("%lld", &S);
  ll ans = 1;
  while (ans * (ans + 1) / 2 <= S) {
    ans++;
  }
  printf("%lld\n", ans - 1);
}
