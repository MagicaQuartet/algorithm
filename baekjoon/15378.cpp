#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
int T;
ll N;
ll cnt[11][1000];
ll sum[11][1000];
void init() {
  memset(cnt, 0, sizeof(cnt));
  memset(sum, 0, sizeof(sum));
  for (int len=1;;len++) {
    cnt[0][len] = 1;
    for (int num=1; num<=9; num++) {
      cnt[num][len] = cnt[num-1][len] + cnt[num][len-1];
    }
    if (cnt[9][len] >= 1000000000000000000) {
      break;
    }
  }
  for (int len=1;;len++) {
    bool end = false;
    sum[0][len] = sum[9][len-1];
    for (int num=1; num<=9; num++) {
      if (cnt[num][len] <= 0) {
        end = true;
        break;
      }
      sum[num][len] = sum[num-1][len] + cnt[num][len];
    }
    if (end) {
      break;
    }
  }
}
void _solve(ll target, int len) {
  if (len == 0) {
    return;
  }
  ll _sum = 0;
  for (int num=0; num<=9; num++) {
    _sum += cnt[num][len];
    if (_sum >= target) {
      printf("%d", num);
      ll new_target = len == 1 ? target : target - _sum + cnt[num][len];
      return _solve(new_target, len-1);
    }
  }
  printf("WRONG");
}
void solve(ll target) {
  for (int len=1; len<=411; len++) {
    for (int num=1; num<=9; num++) {
      if (sum[num][len] == 0) {
        printf("WRONG\n");
        return;
      }
      if (sum[num][len] >= target) {
        printf("%d", num);
        _solve(target - sum[num-1][len], len-1);
        return;
      }
    }
  }
  printf("WRONG\n");
}
int main() {
  scanf("%d", &T);
  init();
  while(T--) {
    scanf("%lld", &N);
    solve(N);
    printf("\n");
  }
}
