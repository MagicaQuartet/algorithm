#include<cstdio>
#include<cstring>
#include<utility>
using namespace std;

int n, A, B, C;
int segtree[4000010];

pair<int, int> pick(int node, int nodeLeft, int nodeRight, int k) {
  if (nodeLeft == nodeRight) {
    return {node, nodeLeft};
  }

  int mid = (nodeLeft + nodeRight) / 2;
  if (segtree[2*node] >= k) {
    return pick(2*node, nodeLeft, mid, k);
  }
  else {
    return pick(2*node+1, mid+1, nodeRight, k-segtree[2*node]);
  }
}

int diff(int node, int nodeLeft, int nodeRight, int target, int delta) {
  if (target < nodeLeft || nodeRight < target) {
    return segtree[node];
  }

  if (nodeLeft == target && nodeRight == target) {
    return segtree[node] += delta;
  }

  int mid = (nodeLeft + nodeRight) / 2;
  int retLeft = diff(2*node, nodeLeft, mid, target, delta);
  int retRight = diff(2*node+1, mid+1, nodeRight, target, delta);
  return segtree[node] = retLeft + retRight;
}

int main() {
  scanf("%d", &n);
  memset(segtree, 0, sizeof(segtree));

  while(n--) {
    scanf("%d %d", &A, &B);
    if (A == 2) {
      scanf("%d", &C);
      diff(1, 1, 1000000, B, C);
    }
    else {
      pair<int, int> ret = pick(1, 1, 1000000, B);
      int node = ret.first;
      int taste = ret.second;
      printf("%d\n", taste);
      while (node > 0) {
        segtree[node]--;
        node /= 2;
      }
    }
  }
}

/*
  베이스 베열을 A[i]: 맛이 i인 사탕의 개수로 가정하고 segtree를 구성한다.
  k번째 사탕 탐색 시 해당 사탕이 현재 노드의 왼쪽에 있는지 오른쪽에 있는지 판단한 후 재귀호출한다.
*/