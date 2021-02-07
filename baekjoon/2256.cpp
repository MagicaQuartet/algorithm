#include<cstdio>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;
#define ll long long
#define INF (ll)32767*32767*1000
int K, N;
ll dp[1010][5010];
int main() {
  scanf("%d%d", &K, &N);
  for (int k=0; k<=K; k++) {
    for (int i=1; i<=N; i++) {
      dp[k][i] = INF;
    }
  }
  vector<int> chopsticks;
  chopsticks.reserve(N);
  for (int i=0; i<N; i++) {
    int len;
    scanf("%d", &len);
    chopsticks.push_back(len);
  }
  sort(chopsticks.begin(), chopsticks.end());
  for (int i=1; i<=N; i++) {
    dp[0][i] = 0;
  }
  for (int k=1; k<=K; k++) {
    for (int i=N-2; i>=1; i--) {
      dp[k][i] = min(dp[k][i+1], (N-i+1) >= 3*k ? dp[k-1][i+2] + (chopsticks[i]-chopsticks[i-1])*(chopsticks[i]-chopsticks[i-1]): INF);
    }
  }

  ll ans = INF;
  for (int i=1; i<=N; i++) {
    ans = min(ans, dp[K][i]);
  }
  printf("%lld\n", ans);
}