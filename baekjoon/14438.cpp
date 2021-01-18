#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 1000000001
int N, M, arr[100010], seg[400010];
int construct(int node, int nodeLeft, int nodeRight) {
  if (nodeLeft == nodeRight) {
    return seg[node] = arr[nodeLeft];
  }
  int mid = (nodeLeft+nodeRight)/2;
  int retLeft = construct(2*node, nodeLeft, mid);
  int retRight = construct(2*node+1, mid+1, nodeRight);
  return seg[node] = min(retLeft, retRight);
}
int update(int node, int nodeLeft, int nodeRight, int target, int value) {
  if (nodeLeft == nodeRight) {
    if (nodeLeft == target) seg[node] = value;
    return seg[node];
  }
  if (target < nodeLeft || nodeRight < target) {
    return seg[node];
  }
  int mid = (nodeLeft+nodeRight)/2;
  int retLeft = update(2*node, nodeLeft, mid, target, value);
  int retRight = update(2*node+1, mid+1, nodeRight, target, value);
  return seg[node] = min(retLeft, retRight);
}
int query(int node, int nodeLeft, int nodeRight, int left, int right) {
  if (nodeRight < left || right < nodeLeft) {
    return INF;
  }
  if (left <= nodeLeft && nodeRight <= right) {
    return seg[node];
  }
  int mid = (nodeLeft+nodeRight)/2;
  int retLeft = query(2*node, nodeLeft, mid, left, right);
  int retRight = query(2*node+1, mid+1, nodeRight, left, right);
  return min(retLeft, retRight);
}
int main() {
  scanf("%d", &N);
  for (int i=1; i<=N; i++) {
    scanf("%d", arr+i);
  }
  construct(1, 1, N);
  scanf("%d", &M);
  while (M--) {
    int mode, i, j;
    scanf("%d %d %d", &mode, &i, &j);
    if (mode == 1) {
      update(1, 1, N, i, j);
    }
    else {
      printf("%d\n", query(1, 1, N, i, j));
    }
  }
}