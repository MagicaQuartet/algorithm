#include <cstdio>
#include <cstring>

typedef long long ll;

int N, Q;
ll segtree[4000010];

ll update(int node, int nodeLeft, int nodeRight, int target, ll val) {
  if (target < nodeLeft || nodeRight < target) {
    return segtree[node];
  }

  if (nodeLeft == nodeRight) {
    segtree[node] += val;
    return segtree[node];
  }

  int mid = (nodeLeft + nodeRight) / 2;
  ll retLeft = update(2*node, nodeLeft, mid, target, val);
  ll retRight = update(2*node+1, mid+1, nodeRight, target, val);
  return segtree[node] = retLeft + retRight;
}

ll query(int node, int nodeLeft, int nodeRight, int left, int right) {
  if (right < nodeLeft || nodeRight < left) {
    return 0;
  }

  if (left <= nodeLeft && nodeRight <= right) {
    return segtree[node];
  }

  int mid = (nodeLeft + nodeRight) / 2;
  ll retLeft = query(2*node, nodeLeft, mid, left, right);
  ll retRight = query(2*node+1, mid+1, nodeRight, left, right);
  return retLeft + retRight;
}

int main() {
  scanf("%d %d", &N, &Q);
  memset(segtree, 0, sizeof(segtree));
  for (int i=0; i<Q; i++) {
    int mode, a, b;
    scanf("%d %d %d", &mode, &a, &b);
    if (mode == 1) {
      update(1, 1, N, a, b);
    }
    else {
      printf("%lld\n", query(1, 1, N, a, b));
    }
  }
}
