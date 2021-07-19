#include<cstdio>
#include<vector>
#include<utility>
#include<queue>
#include<cstring>
#include<limits>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
typedef vector<pii > vpii;
#define INF numeric_limits<ll>::max()

int N, M, A, B, C, src, dest;

int main() {
  scanf("%d %d", &N, &M);
  vector<vpii > graph;
  priority_queue<pii> pq;
  ll d[100010];
  memset(d, -1, sizeof(d));
  for (int i=0; i<N; i++) {
    graph.push_back(vpii());
  }
  for (int i=0; i<M; i++) {
    scanf("%d %d %d", &A, &B, &C);
    graph[A-1].push_back(make_pair(C, B-1));
    graph[B-1].push_back(make_pair(C, A-1));
  }
  scanf("%d %d", &src, &dest);
  for (pii edge: graph[src-1]) {
    pq.push(edge);
  }
  d[src-1] = INF;  
  while(!pq.empty()) {
    ll val = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if (d[node] >= val) {
      continue;
    }
    d[node] = val;

    for (pii edge: graph[node]) {
      ll nextVal = min(val, edge.first);
      ll nextNode = edge.second;
      if (d[nextNode] >= nextVal) {
        continue;
      }
      pq.push(make_pair(nextVal, nextNode));
    }
  }

  printf("%lld\n", d[dest-1]);
}
