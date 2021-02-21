#include<cstdio>
#define ll long long
int T, x, y;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &x, &y);
    int L = y-x;
    int k = 1;
    while ((ll)k*k <= L) {
      k++;
    }
    k--;
    int ans = 2*k-1;
    if (0 < L-k*k && L-k*k <= k) {
      ans += 1;
    }
    else if (k < L-k*k) {
      ans += 2;
    }
    printf("%d\n", ans);
  }
}