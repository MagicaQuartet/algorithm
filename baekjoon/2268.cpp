#include<cstdio>
#include<cstring>
#define ll long long
int N, M, cmd, a, b;
ll tree[4000010];

ll update(int node, int nodeLeft, int nodeRight, int target, int newValue) {
  if (target < nodeLeft || nodeRight < target) {
    return tree[node];
  }
  
  if (nodeLeft == nodeRight) {
    tree[node] = newValue;
    return newValue;
  }
  
  int mid = (nodeLeft + nodeRight) / 2;
  ll retLeft = update(node*2, nodeLeft, mid, target, newValue);
  ll retRight = update(node*2+1, mid+1, nodeRight, target, newValue);
  tree[node] = retLeft + retRight;
  return tree[node];
}

ll query(int node, int nodeLeft, int nodeRight, int left, int right) {
  if (right < nodeLeft || nodeRight < left) {
    return 0;
  }
  
  if (left <= nodeLeft && nodeRight <= right) {
    return tree[node];
  }
  
  int mid = (nodeLeft + nodeRight) / 2;
  ll retLeft = query(node*2, nodeLeft, mid, left, right);
  ll retRight = query(node*2+1, mid+1, nodeRight, left, right);
  return retLeft + retRight;
}

int main() {
  scanf("%d %d", &N, &M);
  memset(tree, 0, sizeof(tree));
  
  for (int i=0; i<M; i++) {
    scanf("%d %d %d", &cmd, &a, &b);
    
    if (cmd == 0) {
      printf("%lld\n", a < b ? query(1, 1, N, a, b) : query(1, 1, N, b, a));
    }
    else {
      update(1, 1, N, a, b);
    }
  }
}