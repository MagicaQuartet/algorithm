#include<cstdio>
#include<cstring>
int cnt[1000010];
int n, x;
long long ans;
int main() {
  scanf("%d", &n);
  memset(cnt, 0, sizeof(cnt));
  ans = 0;
  for (int i=0; i<n; i++) {
    int num;
    scanf("%d", &num);
    cnt[num]++;
  }
  scanf("%d", &x);

  int idx = 1;
  if (x > 1000000) idx = x - 1000000;
  for (; idx <= x/2; idx++) {
    if (idx != x-idx) ans += cnt[idx]*cnt[x-idx];
    else ans += cnt[idx]*(cnt[idx]-1)/2;
  }
  printf("%lld\n", ans);
}