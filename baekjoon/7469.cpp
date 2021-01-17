#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
int n, m, i, j, k;
int arr[100010];
vi seg[400010];
vi merge(vi& vLeft, vi& vRight) {
  vi ret;
  ret.reserve(vLeft.size()+vRight.size());
  int lidx, ridx;
  lidx = ridx = 0;
  while (lidx < vLeft.size() && ridx < vRight.size()) {
    if (vLeft[lidx] < vRight[ridx]) ret.push_back(vLeft[lidx++]);
    else ret.push_back(vRight[ridx++]);
  }
  while (lidx < vLeft.size()) ret.push_back(vLeft[lidx++]);
  while (ridx < vRight.size()) ret.push_back(vRight[ridx++]);
  return ret;
}
vi construct(int node, int nodeLeft, int nodeRight) {
  if (nodeLeft == nodeRight) {
    vi ret = vi(1, arr[nodeLeft]);
    return seg[node] = ret;
  }
  int mid = (nodeLeft+nodeRight)/2;
  vi retLeft = construct(2*node, nodeLeft, mid);
  vi retRight = construct(2*node+1, mid+1, nodeRight);
  return seg[node] = merge(retLeft, retRight);
}
pii query(int node, int nodeLeft, int nodeRight, int left, int right, int target) {
  if (right < nodeLeft || nodeRight < left) {
    return make_pair(0, 0);
  }
  if (left <= nodeLeft && nodeRight <= right) {
    vi::iterator ub = upper_bound(seg[node].begin(), seg[node].end(), target);
    return make_pair((*ub==target?1:0), ub-seg[node].begin());
  }
  int mid = (nodeLeft+nodeRight)/2;
  pii retLeft = query(2*node, nodeLeft, mid, left, right, target);
  pii retRight = query(2*node+1, mid+1, nodeRight, left, right, target);
  return make_pair(max(retLeft.first, retRight.first), retLeft.second+retRight.second);
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i=1; i<=n; i++) {
    scanf("%d", arr+i);
  }
  construct(1, 1, n);
  for (int q=1; q<=m; q++) {
    scanf("%d %d %d", &i, &j, &k);
    int head = -1000000000;
    int tail = 1000000000;
    while (head <= tail) {
      int mid = (head+tail)/2;
      pii ret = query(1, 1, n, i, j, mid);

      if (ret.second <= k-1) {
        head = mid+1;
      }
      else {
        tail = mid-1;
      }
    }
    printf("%d\n", head);
  }
}