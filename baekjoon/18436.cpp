#include <cstdio>
#include <utility>
using namespace std;

typedef pair<int, int> pii;

int N, M, arr[100010];
pii segtree[400010];

pii construct(int node, int nodeLeft, int nodeRight) {
  if (nodeLeft == nodeRight) {
    return segtree[node] = make_pair(!(arr[nodeLeft]%2), !!(arr[nodeLeft]%2));
  }

  int mid = (nodeLeft + nodeRight) / 2;
  pii retLeft = construct(node*2, nodeLeft, mid);
  pii retRight = construct(node*2+1, mid+1, nodeRight);
  return segtree[node] = make_pair(retLeft.first+retRight.first, retLeft.second+retRight.second);
}

pii update(int node, int nodeLeft, int nodeRight, int target, int val) {
  if (target < nodeLeft || nodeRight < target) {
    return segtree[node];
  }

  if (nodeLeft == nodeRight) {
    arr[nodeLeft] = val;
    return segtree[node] = make_pair(!(arr[nodeLeft]%2), !!(arr[nodeLeft]%2));
  }

  int mid = (nodeLeft + nodeRight) / 2;
  pii retLeft = update(node*2, nodeLeft, mid, target, val);
  pii retRight = update(node*2+1, mid+1, nodeRight, target, val);
  return segtree[node] = make_pair(retLeft.first+retRight.first, retLeft.second+retRight.second);
}

pii query(int node, int nodeLeft, int nodeRight, int left, int right) {
  if (right < nodeLeft || nodeRight < left) {
    return make_pair(0, 0);
  }

  if (left <= nodeLeft && nodeRight <= right) {
    return segtree[node];
  }

  int mid = (nodeLeft + nodeRight) / 2;
  pii retLeft = query(node*2, nodeLeft, mid, left, right);
  pii retRight = query(node*2+1, mid+1, nodeRight, left, right);
  return make_pair(retLeft.first+retRight.first, retLeft.second+retRight.second);
}

int main() {
  scanf("%d", &N);
  for (int i=1; i<=N; i++) {
    scanf("%d", arr+i);
  }
  construct(1, 1, N);
  scanf("%d", &M);
  for (int i=0; i<M; i++) {
    int mode, a, b;
    scanf("%d %d %d", &mode, &a, &b);
    if (mode == 1) {
      update(1, 1, N, a, b);
    }
    else if (mode == 2) {
      printf("%d\n", query(1, 1, N, a, b).first);
    }
    else {
      printf("%d\n", query(1, 1, N, a, b).second);
    }
  }
}
