#include<cstdio>
#include<cstring>
#include<vector>
#include<utility>
#include<algorithm>
#define pii pair<int, int>
#define INF 987654321
using namespace std;

int N, A, B, C, K, D, E;
int minVal, maxVal;
vector<vector<pii > > graph;
int parents[100010][18];
int depth[100010];
pii dp[100010][18];

void dfs(int node) {
  for (auto child: graph[node]) {
    if (parents[node][0] == child.first) {
      continue;
    }

    depth[child.first] = depth[node] + 1;
    parents[child.first][0] = node;
    dp[child.first][0] = {child.second, child.second};
    dfs(child.first);
  }
}

void getParents() {
  for (int i=1; (1<<i)<=N; i++) {
    for (int n=1; n<=N; n++) {
      parents[n][i] = parents[parents[n][i-1]][i-1];
      dp[n][i] = {min(dp[n][i-1].first, dp[parents[n][i-1]][i-1].first), max(dp[n][i-1].second, dp[parents[n][i-1]][i-1].second)};
    }
  }
}

void LCA(int lhs, int rhs) {
  if (depth[lhs] < depth[rhs]) {
    swap(lhs, rhs);
  }

  int idx = 17;
  minVal = INF;
  maxVal = -INF;
  while (depth[lhs] > depth[rhs]) {
    while (depth[lhs]-(1<<idx) < depth[rhs]) {
      idx--;
    }
    minVal = min(minVal, dp[lhs][idx].first);
    maxVal = max(maxVal, dp[lhs][idx].second);
    lhs = parents[lhs][idx];
    idx--;
  }

  while (lhs != rhs) {
    for (int i=1; (1<<i)<=N; i++) {
      if (parents[lhs][i] == parents[rhs][i]) {
        minVal = min(minVal, min(dp[lhs][i-1].first, dp[rhs][i-1].first));
        maxVal = max(maxVal, max(dp[lhs][i-1].second, dp[rhs][i-1].second));
        lhs = parents[lhs][i-1];
        rhs = parents[rhs][i-1];
        break;
      }
    }
  }

  printf("%d %d\n", minVal, maxVal);
}

int main() {
  scanf("%d", &N);
  graph = vector<vector<pii > >(N+1, vector<pii >());
  memset(parents, 0, sizeof(parents));
  memset(depth, 0, sizeof(depth));

  for (int i=0; i<N-1; i++) {
    scanf("%d %d %d", &A, &B, &C);
    graph[A].push_back({B, C});
    graph[B].push_back({A, C});
  }

  depth[1] = 0;
  dfs(1);
  getParents();

  scanf("%d", &K);
  for (int i=0; i<K; i++) {
    scanf("%d %d", &D, &E);
    LCA(D, E);
  }
}

/*
  segtree를 사용하지 않는 O(N+KlogN) LCA 탐색 알고리즘 풀이
*/