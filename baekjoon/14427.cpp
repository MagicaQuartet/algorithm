#include <cstdio>
#include <utility>
#define INF 987654321
using namespace std;

typedef pair<int, int> pii;

int N, M, arr[100010];
pii segtree[400010];

pii construct(int node, int nodeLeft, int nodeRight) {
  if (nodeLeft == nodeRight) {
    return segtree[node] = make_pair(arr[nodeLeft], nodeLeft);
  }

  int mid = (nodeLeft + nodeRight) / 2;
  pii retLeft = construct(node*2, nodeLeft, mid);
  pii retRight = construct(node*2+1, mid+1, nodeRight);
  if (retLeft.first < retRight.first || (retLeft.first == retRight.first && retLeft.second < retRight.second)) {
    segtree[node] = make_pair(retLeft.first, retLeft.second);
  }
  else {
    segtree[node] = make_pair(retRight.first, retRight.second);
  }
  return segtree[node];
}

pii update(int node, int nodeLeft, int nodeRight, int target, int val) {
  if (target < nodeLeft || nodeRight < target) {
    return segtree[node];
  }

  if (nodeLeft == nodeRight) {
    arr[nodeLeft] = val;
    return segtree[node] = make_pair(arr[nodeLeft], nodeLeft);
  }

  int mid = (nodeLeft + nodeRight) / 2;
  pii retLeft = update(node*2, nodeLeft, mid, target, val);
  pii retRight = update(node*2+1, mid+1, nodeRight, target, val);
  if (retLeft.first < retRight.first || (retLeft.first == retRight.first && retLeft.second < retRight.second)) {
    segtree[node] = make_pair(retLeft.first, retLeft.second);
  }
  else {
    segtree[node] = make_pair(retRight.first, retRight.second);
  }
  return segtree[node];
}

int main() {
  scanf("%d", &N);
  for (int i=1; i<=N; i++) {
    scanf("%d", arr+i);
  }
  construct(1, 1, N);
  scanf("%d", &M);
  for (int i=0; i<M; i++) {
    int mode, idx, val;
    scanf("%d", &mode);
    if (mode == 1) {
      scanf("%d %d", &idx, &val);
      update(1, 1, N, idx, val);
    }
    else {
      printf("%d\n", segtree[1].second);
    }
  }
}
