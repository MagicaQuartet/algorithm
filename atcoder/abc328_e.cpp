#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ppii pair<ll, pii >
int N, M;
ll K;
int visited[10];
ll graph[10][10];
ll solve(vector<int>& v, ll sum) {
  for (auto n: v) {
    for (int i=1; i<=N; i++) {
      if (visited[i])
    }
  }
}
int main() {
  scanf("%d%d%lld", &N, &M, &K);
  memset(visited, 0, sizeof(visited));
  memset(graph, -1, sizeof(graph));
  while (M--) {
    int u, v;
    ll w;
    scanf("%d%d%lld", &u, &v, &w);
    graph[u][v] = w;
    graph[v][u] = w;
  }
  visited[1] = 1;
  vector<int> v(1,1);
  printf("%lld\n", solve(v, 0));
}
