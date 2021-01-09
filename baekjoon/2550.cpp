#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N, lislen;
int zeroToSwitch[10001], switchToZero[10001], target[10001], lis[10001], parent[10001], ans[10001];
int main() {
  scanf("%d", &N);
  for (int i=1; i<=N; i++) {
    scanf("%d", zeroToSwitch+i);
    switchToZero[zeroToSwitch[i]] = i;
  }
  for (int i=1; i<=N; i++) {
    int num;
    scanf("%d", &num);
    target[i] = switchToZero[num];
  }
  target[0] = 0;
  lislen = 0;
  memset(lis, 0, sizeof(lis));
  memset(parent, -1, sizeof(parent));
  for (int i=1; i<=N; i++) {
    int head = 1;
    int tail = lislen;
    while (head < tail) {
      int mid = (head+tail)/2;
      if (target[i] <= target[lis[mid]]) {
        tail = mid;
      }
      else {
        head = mid+1;
      }
    }
    if (target[lis[tail]] < target[i]) tail++;
    lislen = max(lislen, tail);
    parent[i] = lis[tail-1];
    lis[tail] = i;
  }
  printf("%d\n", lislen);
  int step = lis[lislen];
  int idx = 0;
  while (step != -1) {
    ans[idx++] = zeroToSwitch[target[step]];
    step = parent[step];
  }
  sort(ans, ans+lislen);
  for (int i=0; i<lislen; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
}
