#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long
#define vi vector<int>
int T, N, K, W, cost[1010], indegree[1010], visited[1010];
ll total[1010];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &N, &K);
    vector<vi > graph(N+1, vi());
    queue<int> q;
    for (int i=1; i<=N; i++) {
      scanf("%d", cost+i);
      indegree[i] = visited[i] = 0;
      total[i] = cost[i];
    }
    for (int i=0; i<K; i++) {
      int X, Y;
      scanf("%d%d", &X, &Y);
      graph[X].push_back(Y);
      indegree[Y]++;
    }
    for (int i=1; i<=N; i++) {
      if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
      int node = q.front();
      q.pop();
      visited[node] = 1;
      for (int child: graph[node]) {
        total[child] = max(total[child], total[node] + cost[child]);
        if (--indegree[child] == 0) q.push(child);
      }
    }
    scanf("%d", &W);
    printf("%lld\n", total[W]);
  }
}