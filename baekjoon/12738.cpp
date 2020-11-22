#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N, A[1000010], dp[1000010];
int main() {
  scanf("%d", &N);
  memset(dp, -1, sizeof(dp));
  for (int i=1; i<=N; i++) {
    scanf("%d", A+i);
    dp[i] = -1;
  }

  int len = 0;
  for (int i=1; i<=N; i++) {
    int head = 1;
    int tail = head + len;
    while (head < tail) {
      int mid = (head + tail) / 2;
      if (dp[mid] == -1 || dp[mid] >= A[i]) {
        tail = max(mid - 1, head);
      }
      else {
        head = mid + 1;
      }
    }

    if (dp[head] == -1) {
      len++;
      dp[head] = A[i];
    }
    else if (dp[head] >= A[i]) {
      dp[head] = A[i];
    }
    else {
      if (dp[head+1] == -1) {
        len++;
      }
      dp[head+1] = A[i];
    }
  }

  printf("%d\n", len);
}

// upper_bound 직접 구현
// LIS 구성하는 로직을 O(nlogn)으로 하는 12015번과 동일한 풀이
