#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#define pii pair<int, int>
#define vi vector<int>
using namespace std;

int N, M, i, j, k;
int seq[100010];
vi segtree[400010];

void construct(int node, int nodeLeft, int nodeRight) {
  if (nodeLeft == nodeRight) {
    segtree[node] = vi(1, seq[nodeLeft]);
    return;
  }

  int mid = (nodeLeft + nodeRight) / 2;
  construct(2*node, nodeLeft, mid);
  construct(2*node+1, mid+1, nodeRight);
  segtree[node] = vi(segtree[2*node].size()+segtree[2*node+1].size());
  merge(segtree[2*node].begin(), segtree[2*node].end(), segtree[2*node+1].begin(), segtree[2*node+1].end(), segtree[node].begin());
}

int query(int node, int nodeLeft, int nodeRight, int left, int right, int target) {
  if (right < nodeLeft || nodeRight < left) {
    return 0;
  }

  if (left <= nodeLeft && nodeRight <= right) {
    vector<int>::iterator ub = upper_bound(segtree[node].begin(), segtree[node].end(), target);
    return segtree[node].end() - ub;
  }

  int mid = (nodeLeft + nodeRight) / 2;
  int retLeft = query(2*node, nodeLeft, mid, left, right, target);
  int retRight = query(2*node+1, mid+1, nodeRight, left, right, target);
  return retLeft + retRight;
}

int main() {
  scanf("%d", &N);
  for (int i=1; i<=N; i++) {
    scanf("%d", seq+i);
  }
  construct(1, 1, N);

  scanf("%d", &M);
  for (int q=0; q<M; q++) {
    scanf("%d %d %d", &i, &j, &k);
    printf("%d\n", query(1, 1, N, i, j, k));
  }
}

/*
  세그트리를 변형한 머지소트 트리.
  검색하면 더 간단해보이는 구현이 있긴 한데 잘 이해가 안되고,
  기존에 사용하던 세그트리 구현법이 많이 익숙해서 유사한 형태로 구현했음.
*/