#include<cstdio>
#include<algorithm>
using namespace std;
int N, a, b, c, _a, _b, _c, maxdp[3] = {0,0,0}, mindp[3] = {0,0,0};
int main() {
  scanf("%d", &N);
  while(N--) {
    scanf("%d %d %d", &a, &b, &c);
    _a = maxdp[0];
    _b = maxdp[1];
    _c = maxdp[2];
    maxdp[0] = a + max(_a, _b);
    maxdp[1] = b + max(_a, max(_b, _c));
    maxdp[2] = c + max(_b, _c);
    _a = mindp[0];
    _b = mindp[1];
    _c = mindp[2];
    mindp[0] = a + min(_a, _b);
    mindp[1] = b + min(_a, min(_b, _c));
    mindp[2] = c + min(_b, _c);
  }
  printf("%d %d\n", max(maxdp[0], max(maxdp[1], maxdp[2])), min(mindp[0], min(mindp[1], mindp[2])));
}

/* i번째 줄에서 각 지점에 도달했을 때 얻을 수 있는 점수의 최댓값과 최솟값은 i-1번째 줄에서의 경우만 고려하면 얻을 수 있다. 따라서 입력을 한 줄씩 받을 때마다 최댓값과 최솟값을 저장하면 답을 구할 수 있다. */