#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define vi vector<int>
int N, ans, indegree[10010], cost[10010], total[10010];
int main() {
  scanf("%d", &N);
  vector<vi > graph(N+1, vi());
  memset(indegree, 0, sizeof(indegree));
  for (int i=1; i<=N; i++) {
    int c, pre;
    scanf("%d %d", &c, &pre);
    cost[i] = total[i] = c;
    for (int j=0; j<pre; j++) {
      int num;
      scanf("%d", &num);
      graph[i].push_back(num);
      indegree[num]++;
    }
  }

  queue<int> q;
  ans = 0;
  for (int i=1; i<=N; i++) {
    if (indegree[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    int job = q.front();
    q.pop();
    ans = max(ans, total[job]);
    for (int next: graph[job]) {
      total[next] = max(total[next], total[job]+cost[next]);
      indegree[next]--;
      if (indegree[next] == 0) q.push(next);
    }
  }
  printf("%d\n", ans);
}