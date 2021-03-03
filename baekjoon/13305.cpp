#include<cstdio>
#define ll long long
int len[100010], N, minCost;
ll ans;
int min(int a, int b) {
  return a > b ? b : a;
}
int main() {
  scanf("%d", &N);
  for (int i=0; i<N-1; i++) {
    scanf("%d", len+i);
  }
  minCost = 1000000000;
  for (int i=0; i<N-1; i++) {
    int cost;
    scanf("%d", &cost);
    minCost = min(minCost, cost);
    ans += (ll)minCost*len[i];
  }
  printf("%lld\n", ans);
}
