#include<cstdio>
#include<cstring>
#include<vector>
#include<utility>
#define pii pair<int, int>
#define ll long long
using namespace std;

int N, C, x, y, Q, mode, A;
// 기존 인덱스 사용
int depth[200010];
int parents[200010];
int origToNew[200010];
pii subRange[200010];
vector<vector<int> > graph;
// 새 인덱스 사용
int idx;
int segtree[800010];

void dfs(int node) {
  origToNew[node] = idx;
  subRange[node].first = idx;
  idx++;

  for (auto child: graph[node]) {
    if (parents[node] == child) {
      continue;
    }

    depth[child] = depth[node] + 1;
    parents[child] = node;
    dfs(child);
  }

  subRange[node].second = idx-1;
}

int increment(int node, int nodeLeft, int nodeRight, int target) {
  if (target < nodeLeft || nodeRight < target) {
    return 0;
  }

  if (nodeLeft == nodeRight) {
    segtree[node] += 1;
    return 1;
  }

  int mid = (nodeLeft + nodeRight) / 2;
  int retLeft = increment(2*node, nodeLeft, mid, target);
  int retRight = increment(2*node+1, mid+1, nodeRight, target);
  segtree[node] += retLeft + retRight;
  return retLeft + retRight;
}

int query(int node, int nodeLeft, int nodeRight, int left, int right) {
  if (nodeRight < left || right < nodeLeft) {
    return 0;
  }

  if (left <= nodeLeft && nodeRight <= right) {
    return segtree[node];
  }

  int mid = (nodeLeft + nodeRight) / 2;
  int retLeft = query(2*node, nodeLeft, mid, left, right);
  int retRight = query(2*node+1, mid+1, nodeRight, left, right);
  return retLeft + retRight;
}

int main() {
  scanf("%d %d", &N, &C);
  memset(parents, 0, sizeof(parents));
  memset(segtree, 0, sizeof(segtree));
  graph = vector<vector<int> >(N+1, vector<int>());

  for (int i=1; i<=N; i++) {
    subRange[i] = {-1, -1};
  }

  for (int i=0; i<N-1; i++) {
    scanf("%d %d", &x, &y);
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  idx = 1;
  depth[C] = 1;
  dfs(C);

  scanf("%d", &Q);
  for (int i=0; i<Q; i++) {
    scanf("%d %d", &mode, &A);
    if (mode == 1) {
      increment(1, 1, N, origToNew[A]);
    }
    else {
      printf("%lld\n", ((ll)depth[A])*query(1, 1, N, subRange[A].first, subRange[A].second));
    }
  }
}

/*
  기똥찬 방법을 하나 배울 수 있었던 문제였다.
  트리에서 한 노드의 서브트리에 대해 세그트리를 이용한 구간값 구하기를 하고 싶을 때
  DFS 순서대로 노드 번호를 새로 지정하면 각 서브트리의 정보를 연속된 구간에 저장할 수 있다.
  더 찾아보니 HLD니 뭐니하는, 트리를 선형인 것처럼 쓰고 싶을 때 활용하는 알고리즘이 있던데 어려워보여서 자세히 보지는 않았다.
*/