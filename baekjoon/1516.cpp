#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, ans;
int indegree[501];
int cost[501], originalCost[501];

int main() {
  scanf("%d", &N);
  memset(indegree, 0, sizeof(indegree));
  vector<vector<int> >graph(N+1, vector<int>());
  queue<int> q;
  for (int i=1; i<=N; i++) {
    int c, b;
    scanf("%d", &c);
    cost[i] = originalCost[i] = c;

    while(1) {
      scanf("%d", &b);
      if (b == -1) {
        break;
      }

      indegree[i]++;
      graph[b].push_back(i);
    }
  }

  for (int i=1; i<=N; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  ans = 0;
  while(!q.empty()) {
    int b = q.front();
    q.pop();

    for (auto i: graph[b]) {
      indegree[i]--;
      cost[i] = max(cost[i], cost[b]+originalCost[i]);
      if (!indegree[i]) {
        q.push(i);
      }
    }
  }

  for (int i=1; i<=N; i++) {
    printf("%d\n", cost[i]);
  }
}