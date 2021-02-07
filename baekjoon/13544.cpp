#include<cstdio>
#include<vector>
using namespace std;
#define vi vector<int>
int N, M, a, b, c, ans;
int arr[100010];
vi segtree[400010];

vi merge(vi& lhs, vi& rhs) {
  vi ret;
  ret.reserve(lhs.size() + rhs.size());
  int lidx = 0;
  int ridx = 0;
  while (lidx < lhs.size() && ridx < rhs.size()) {
    if (lhs[lidx] < rhs[ridx]) ret.push_back(lhs[lidx++]);
    else ret.push_back(rhs[ridx++]);
  }
  while (lidx < lhs.size()) {
    ret.push_back(lhs[lidx++]);
  }
  while (ridx < rhs.size()) {
    ret.push_back(rhs[ridx++]);
  }
  return ret;
}

int count(vi& arr, int target) {
  int head = 0;
  int tail = arr.size()-1;
  while (head <= tail) {
    int mid = (head+tail)/2;
    if (arr[mid] <= target) {
      head = mid + 1;
    }
    else {
      tail = mid - 1;
    }
  }
  return arr.size() - head;
}

vi construct(int node, int nodeLeft, int nodeRight) {
  if (nodeLeft == nodeRight) {
    return segtree[node] = vi(1, arr[nodeLeft]);
  }
  int mid = (nodeLeft+nodeRight)/2;
  vi retLeft = construct(2*node, nodeLeft, mid);
  vi retRight = construct(2*node+1, mid+1, nodeRight);
  return segtree[node] = merge(retLeft, retRight);
}

int query(int node, int nodeLeft, int nodeRight, int left, int right, int target) {
  if (right < nodeLeft || nodeRight < left) {
    return 0;
  }
  if (left <= nodeLeft && nodeRight <= right) {
    int ret = count(segtree[node], target);
    return ret;
  }
  int mid = (nodeLeft+nodeRight)/2;
  int retLeft = query(2*node, nodeLeft, mid, left, right, target);
  int retRight = query(2*node+1, mid+1, nodeRight, left, right, target);
  return retLeft+retRight;
}

int main() {
  scanf("%d", &N);
  for (int i=1; i<=N; i++) {
    scanf("%d", arr+i);
  }
  construct(1, 1, N);
  scanf("%d", &M);
  ans = 0;
  for (int i=0; i<M; i++) {
    scanf("%d%d%d", &a, &b, &c);
    ans = query(1, 1, N, a^ans, b^ans, c^ans);
    printf("%d\n", ans);
  }
}