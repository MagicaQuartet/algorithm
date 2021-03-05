#include<cstdio>
#include<cstring>
#include<deque>
#include<algorithm>
using namespace std;
int N, M, ans;
deque<int> dq;
void lshift(int cnt) {
  for (int i=0; i<cnt; i++) {
    dq.push_back(dq.front());
    dq.pop_front();
  }
}
void rshift(int cnt) {
  for (int i=0; i<cnt; i++) {
    dq.push_front(dq.back());
    dq.pop_back();
  }
}
int main() {
  scanf("%d %d", &N, &M);
  ans = 0;
  for (int i=1; i<=N; i++) {
    dq.push_back(i);
  }
  while (M--) {
    int target;
    scanf("%d", &target);
    int cnt1 = 0;
    int cnt2 = 0;
    while (target != dq.front()) {
      lshift(1);
      cnt1++;
    }
    rshift(cnt1);
    while (target != dq.front()) {
      rshift(1);
      cnt2++;
    }
    lshift(cnt2);
    if (cnt1 <= cnt2) {
      ans += cnt1;
      lshift(cnt1);
    }
    else {
      ans += cnt2;
      rshift(cnt2);
    }
    dq.pop_front();
  }
  printf("%d\n", ans);
}