#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
using namespace std;
int t, n, m, arr[501], indegree[501], old[501];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    memset(indegree, 0, sizeof(indegree));
    vector<set<int> > graph(n+1, set<int>());

    for (int i=1; i<=n; i++) {
      scanf("%d", &arr[i]);
      old[arr[i]] = i;
    }
    for (int i=1; i<n; i++) {
      for (int j=i+1; j<=n; j++) {
        graph[arr[i]].insert(arr[j]);
        indegree[arr[j]]++;
      }
    }

    scanf("%d", &m);
    for (int i=1; i<=m; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      int head = (old[a] < old[b]) ? a : b;
      int tail = (old[a] < old[b]) ? b : a;
      graph[head].erase(tail);
      indegree[tail]--;
      graph[tail].insert(head);
      indegree[head]++;
    }

    vector<int> ans;
    ans.reserve(n);
    queue<int> q;
    for (int i=1; i<=n; i++) {
      if (indegree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
      int team = q.front();
      q.pop();
      ans.push_back(team);
      for (int next: graph[team]) {
        indegree[next]--;
        if (indegree[next] == 0) q.push(next);
      }
    }

    if (n == ans.size()) {
      for (int team: ans) {
        printf("%d ", team);
      }
      printf("\n");
    }
    else {
      printf("IMPOSSIBLE\n");
    }
  }
}