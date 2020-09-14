#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>
using namespace std;

int N, K, W, V;
pair<int, int> wv[101];
int dp[101][100010];

int solve(int idx, int capacity) {
  if (idx == N) {
    return 0;
  }

  if (dp[idx][capacity] != -1) {
    return dp[idx][capacity];
  }

  int ret;
  if (capacity - wv[idx].first >= 0) {
    ret = max(solve(idx+1, capacity), solve(idx+1, capacity-wv[idx].first) + wv[idx].second);
  }
  else {
    ret = 0;
  }
  return dp[idx][capacity] = ret;
}

int main() {
  scanf("%d %d", &N, &K);
  for (int i=0; i<N; i++) {
    scanf("%d %d", &W, &V);
    wv[i] = make_pair(W, V);
  }
  memset(dp, -1, sizeof(dp));
  sort(wv, wv+N);
  printf("%d\n", solve(0, K));
}