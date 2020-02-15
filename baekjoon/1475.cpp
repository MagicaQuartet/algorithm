#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N, idx, ans, cnt[10];
int main() {
  scanf("%d", &N);
  ans = 1;
  while(N>0) {
    idx = N%10;
    if (idx == 6 || idx == 9) {
      idx = cnt[6] < cnt[9] ? 6 : 9;
    }
    cnt[idx]++;
    ans = max(ans, cnt[idx]);
    N /= 10;
  }
  printf("%d\n", ans);
}

/* N이 0인 경우만 까먹지 않으면 된다 */