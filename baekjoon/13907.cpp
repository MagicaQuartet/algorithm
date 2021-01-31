#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
using namespace std;
#define INF 98765432198
#define pii pair<ll, int>
#define pipii pair<int, pii >
#define vpii vector<pii >
#define ll long long
struct cmp {
  bool operator() (pipii lhs, pipii rhs) {
    return lhs.second.first > rhs.second.first;
  }
};
int N, M, K, S, D, a, b, w, p, acc;
ll dist[1010][1010];
int checkPossibleDist(int node, int cnt, ll val) {
  int possible = true;
  for (int i=cnt-1; i>=0; i--) {
    if (dist[node][i] != INF) {
      possible = val < dist[node][i];
      break;
    }
  }
  return possible;
}
ll getMinDist() {
  ll ans = INF;
  for (int i=0; i<=N; i++) {
    ans = min(ans, dist[D][i] + acc*i);
  }
  return ans;
}
int main() {
  scanf("%d %d %d %d %d", &N, &M, &K, &S, &D);
  vector<vpii > graph(N+1, vpii());
  for (int i=0; i<M; i++) {
    scanf("%d %d %d", &a, &b, &w);
    graph[a].push_back({b, w});
    graph[b].push_back({a, w});
  }
  for (int i=1; i<=N; i++) {
    for (int j=0; j<=N; j++) {
      dist[i][j] = INF;
    }
  }
  dist[S][0] = 0;
  priority_queue<pipii, vector<pipii >, cmp> pq;
  for (pii edge: graph[S]) {
    int dst = edge.first;
    ll cost = edge.second;
    pq.push({dst, {cost, 1}});
  }
  while(!pq.empty()) {
    int dst = pq.top().first;
    ll cost = pq.top().second.first;
    int usedEdges = pq.top().second.second;
    pq.pop();
    if (dist[dst][usedEdges] < cost || !checkPossibleDist(dst, usedEdges, cost)) continue;
    dist[dst][usedEdges] = cost;
    for (pii edge: graph[dst]) {
      int nextDst = edge.first;
      ll nextCost = dist[dst][usedEdges]+edge.second;
      if (dist[nextDst][usedEdges+1] < nextCost || !checkPossibleDist(nextDst, usedEdges+1, nextCost)) continue;
      pq.push({nextDst, {nextCost, usedEdges+1}});
    }
  }
  acc = 0;
  printf("%lld\n", getMinDist());
  for (int i=0; i<K; i++) {
    scanf("%d", &p);
    acc += p;
    printf("%lld\n", getMinDist());
  }
}