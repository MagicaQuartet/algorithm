#include<cstdio>
#include<cstring>
#include<utility>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;
#define ll long long
#define CAR 0
#define TRAIN 1
#define pp pair<pair<ll, int>, int>
int N, A, B, C;
ll d[1010][1010];
ll ans[2][1010];
int main() {
  scanf("%d%d%d%d", &N, &A, &B, &C);
  memset(ans, -1, sizeof(ans));
  ans[0][1] = ans[1][1] = 0;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      scanf("%lld", &d[i][j]);
    }
  }
  priority_queue<pp, vector<pp >, greater<pp > > pq;
  for (int i=2; i<=N; i++) {
    pq.push({{d[1][i]*A, i}, CAR});
    pq.push({{d[1][i]*B+C, i}, TRAIN});
  }
  while (!pq.empty()) {
    pp info = pq.top();
    pq.pop();
    ll t = info.first.first;
    int city = info.first.second;
    int by = info.second;
    if (ans[by][city] != -1 && ans[by][city] <= t) {
      continue;
    }
    ans[by][city] = t;
    for (int i=1; i<=N; i++) {
      if (i == info.second) {
        continue;
      }
      if (by == CAR) {
        pq.push({{t + d[city][i]*A, i}, CAR});
      }
      pq.push({{t + d[city][i]*B+C, i}, TRAIN});
    }
  }
  printf("%lld\n", min(ans[CAR][N], ans[TRAIN][N]));
}
