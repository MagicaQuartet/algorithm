#include<cstdio>

#define Q 1000000007
#define ll long long
int N, M, K, a, b, c, data[1000010];
ll segtree[4000010];

ll construct(int node, int nodeLeft, int nodeRight) {
  if (nodeLeft == nodeRight) {
    segtree[node] = data[nodeLeft];
    return segtree[node];
  }
  
  int mid = (nodeLeft + nodeRight) / 2;
  ll retLeft = construct(node*2, nodeLeft, mid);
  ll retRight = construct(node*2+1, mid+1, nodeRight);
  
  segtree[node] = (retLeft*retRight) % Q;
  return segtree[node];
}

ll update(int node, int nodeLeft, int nodeRight, int target, int newValue) {
  if (target < nodeLeft || nodeRight < target) {
    return segtree[node];
  }
  
  if (nodeLeft == nodeRight) {
    segtree[node] = newValue;
    return newValue;
  }
  
  int mid = (nodeLeft + nodeRight) / 2;
  ll retLeft = update(node*2, nodeLeft, mid, target, newValue);
  ll retRight = update(node*2+1, mid+1, nodeRight, target, newValue);
  
  segtree[node] = (retLeft*retRight) % Q;
  return segtree[node];
}

ll query(int node, int nodeLeft, int nodeRight, int left, int right) {
  if (right < nodeLeft || nodeRight < left) {
    return 1;
  }
  
  if (left <= nodeLeft && nodeRight <= right) {
    return segtree[node];
  }
  
  int mid = (nodeLeft + nodeRight) / 2;
  ll retLeft = query(node*2, nodeLeft, mid, left, right);
  ll retRight = query(node*2+1, mid+1, nodeRight, left, right);
  
  return (retLeft * retRight) % Q;
}

int main() {
  scanf("%d %d %d", &N, &M, &K);
  
  for (int i=1; i<=N; i++) {
    scanf("%d", data+i);
  }
  
  construct(1, 1, N);
  
  for (int i=0; i<M+K; i++) {
    scanf("%d %d %d", &a, &b, &c);
    if (a == 1) {
      update(1, 1, N, b, c);
    }
    else {
      printf("%lld\n", query(1, 1, N, b, c));
    }
  }
}

/*
  맞왜틀 특) 자료형을 ll로 안 함
  
  계산 중간값이 ll일 땐 중간값 계산에 필요한 친구들도 그냥 ll로 해버리자.
*/