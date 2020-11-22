#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N, A[1000010], dp[1000010], parent[1000010], ans[1000010];
int main() {
  scanf("%d", &N);
  memset(dp, -1, sizeof(dp));
  for (int i=1; i<=N; i++) {
    scanf("%d", A+i);
    parent[i] = dp[i] = -1;
  }

  int len = 0;
  for (int i=1; i<=N; i++) {
    int head = 1;
    int tail = head + len;
    while (head < tail) {
      int mid = (head + tail) / 2;
      if (dp[mid] == -1 || A[dp[mid]] >= A[i]) {
        tail = max(mid - 1, head);
      }
      else {
        head = mid + 1;
      }
    }

    if (dp[head] == -1) {
      len++;
      dp[head] = i;
      parent[i] = dp[head-1];
    }
    else if (A[dp[head]] >= A[i]) {
      dp[head] = i;
      parent[i] = dp[head-1];
    }
    else {
      if (dp[head+1] == -1) {
        len++;
      }
      dp[head+1] = i;
      parent[i] = dp[head];
    }
  }

  printf("%d\n", len);
  int idx = dp[len];
  for (int i=len; i>=1; i--) {
    ans[i] = A[idx];
    idx = parent[idx];
  }
  for (int i=1; i<=len; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
}

// upper_bound 직접 구현
