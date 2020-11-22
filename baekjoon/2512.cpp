#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
int N, M, idx, budget[10010], cnt, head, tail, mid, sum;
ll prefixSum[10010];

int main() {
  scanf("%d", &N);
  budget[0] = prefixSum[0] = 0;
  for (int i=1; i<=N; i++) {
    scanf("%d", budget+i);
  }
  sort(budget+1, budget+N+1);
  for (int i=1; i<=N; i++) {
    prefixSum[i] = prefixSum[i-1] + budget[i];
  }
  scanf("%d", &M);

  for (idx=N; idx>=0; idx--) {
    cnt = N - idx;
    if (prefixSum[idx]-prefixSum[0] + cnt * budget[idx] <= M) {
      break;
    }
  }

  if (idx == N) {
    mid = budget[idx];
  }
  else {
    sum = prefixSum[idx]-prefixSum[0];
    head = budget[idx];
    tail = budget[idx+1];

    while (head <= tail) {
      mid = (head+tail)/2;
      if (sum + cnt * mid <= M) {
        head = mid + 1;
      }
      else {
        tail = mid - 1;
      }
    }

    if (sum + cnt * mid > M) {
      mid--;
    }
    else if (sum + cnt * (mid+1) <= M) {
      mid++;
    }
  }

  printf("%d\n", mid);
}
