#include<cstdio>
#include<cstring>
#define ll long long
int N, Q, x, y, a, b, data[100010];
ll tree[400010];

ll construct(int node, int nodeLeft, int nodeRight) {
  if (nodeLeft == nodeRight) {
    tree[node] = data[nodeLeft];
    return tree[node];
  }
  
  int mid = (nodeLeft + nodeRight) / 2;
  ll retLeft = construct(node*2, nodeLeft, mid);
  ll retRight = construct(node*2+1, mid+1, nodeRight);
  tree[node] = retLeft + retRight;
  return tree[node];
}

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
  scanf("%d %d", &N, &Q);
  
  for (int i=1; i<=N; i++) {
    scanf("%d", data+i);
  }
  
  construct(1, 1, N);
  
  for (int i=0; i<Q; i++) {
    scanf("%d %d %d %d", &x, &y, &a, &b);
    
    printf("%lld\n", x < y ? query(1, 1, N, x, y) : query(1, 1, N, y, x));
    update(1, 1, N, a, b);
  }
}