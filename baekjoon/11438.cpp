#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int N, M, a, b;
int segtree[800010];
vector<int> preorder;
vector<vector<int> > graph;
int visited[100010];
int depth[100010];
int leftmost[100010];

void dfs(int node, int d) {
  visited[node] = 1;
  depth[node] = d;
  leftmost[node] = preorder.size();

  preorder.push_back(node);
  for (auto child: graph[node]) {
    if (visited[child]) {
      continue;
    }

    dfs(child, d+1);
    preorder.push_back(node);
  }
}

int construct(int node, int nodeLeft, int nodeRight) {
  if (nodeLeft == nodeRight) {
    return segtree[node] = preorder[nodeLeft];
  }

  int mid = (nodeLeft + nodeRight) / 2;
  int retLeft = construct(2*node, nodeLeft, mid);
  int retRight = construct(2*node+1, mid+1, nodeRight);
  return segtree[node] = (depth[retLeft] < depth[retRight]) ? retLeft : retRight;
}

int query(int node, int nodeLeft, int nodeRight, int left, int right) {
  if (right < nodeLeft || nodeRight < left) {
    return 0;
  }

  if (left <= nodeLeft && nodeRight <= right) {
    return segtree[node];
  }

  int mid = (nodeLeft + nodeRight) / 2;
  int retLeft = query(2*node, nodeLeft, mid, left, right);
  int retRight = query(2*node+1, mid+1, nodeRight, left, right);
  return (depth[retLeft] < depth[retRight]) ? retLeft : retRight;  
}

int main() {
  scanf("%d", &N);
  memset(visited, 0, sizeof(visited));
  memset(depth, -1, sizeof(depth));
  memset(leftmost, -1, sizeof(leftmost));
  graph = vector<vector<int> >(N+1, vector<int>());
  preorder.reserve(2*N);

  for (int i=0; i<N-1; i++) {
    scanf("%d %d", &a, &b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  preorder.push_back(0);
  depth[0] = 987654321;
  dfs(1, 0);
  construct(1, 1, preorder.size()+1);

  scanf("%d", &M);
  for (int i=0; i<M; i++) {
    scanf("%d %d", &a, &b);
    int l = min(leftmost[a], leftmost[b]);
    int r = max(leftmost[a], leftmost[b]);
    printf("%d\n", query(1, 1, preorder.size()+1, l, r));
  }
}

/*
  segtree를 이용한 LCA 알고리즘
  다른 방법도 있고 그 쪽이 더 트리-스러워 보이는데 공부해볼 것
*/