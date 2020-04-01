#include<cstdio>
#include<cstring>
#define ll long long
int N, M, K, a, b, c;
ll d, data[1000010], segtree[4000010], lazy[4000010];

ll construct(int node, int nodeLeft, int nodeRight) {
  if (nodeLeft == nodeRight) {
    return segtree[node] = data[nodeLeft];
  }
  
  int mid = (nodeLeft + nodeRight) / 2;
  ll retLeft = construct(node*2, nodeLeft, mid);
  ll retRight = construct(node*2+1, mid+1, nodeRight);
  return segtree[node] = retLeft + retRight;
}

void update(int node, int nodeLeft, int nodeRight, int left, int right, ll diff) {
  if (lazy[node] != 0) {
    segtree[node] += (nodeRight - nodeLeft + 1) * lazy[node];
    
    if (nodeLeft != nodeRight) {
      lazy[node*2] += lazy[node];
      lazy[node*2+1] += lazy[node];
    }
    
    lazy[node] = 0;
  }
  
  if (right < nodeLeft || nodeRight < left) {
    return;
  }
  
  if (left <= nodeLeft && nodeRight <= right) {
    segtree[node] += (nodeRight - nodeLeft + 1) * diff;
    
    if (nodeLeft != nodeRight) {
      lazy[node*2] += diff;
      lazy[node*2+1] += diff;
    }
    
    return;
  }
  
  int mid = (nodeLeft + nodeRight) / 2;
  update(node*2, nodeLeft, mid, left, right, diff);
  update(node*2+1, mid+1, nodeRight, left, right, diff);
  
  segtree[node] = segtree[node*2] + segtree[node*2+1];
}

ll query(int node, int nodeLeft, int nodeRight, int left, int right) {
  if (lazy[node] != 0) {
    segtree[node] += (nodeRight - nodeLeft + 1) * lazy[node];
    
    if (nodeLeft != nodeRight) {
      lazy[node*2] += lazy[node];
      lazy[node*2+1] += lazy[node];
    }
    
    lazy[node] = 0;
  }
  
  if (right < nodeLeft || nodeRight < left) {
    return 0;
  }
  
  if (left <= nodeLeft && nodeRight <= right) {
    return segtree[node];
  }
  
  int mid = (nodeLeft + nodeRight) / 2;
  ll retLeft = query(node*2, nodeLeft, mid, left, right);
  ll retRight = query(node*2+1, mid+1, nodeRight, left, right);
  
  return retLeft + retRight;
}

int main() {
  scanf("%d %d %d", &N, &M, &K);
  memset(segtree, 0, 4*(N+1));
  memset(lazy, 0, 4*(N+1));
  
  for (int i=1; i<=N; i++) {
    scanf("%lld", data+i);
  }
  
  construct(1, 1, N);
  
  for (int i=0; i<M+K; i++) {
    scanf("%d %d %d", &a, &b, &c);
    
    if (a == 1) {
      scanf("%lld", &d);
      update(1, 1, N, b, c, d);
    }
    else {
      printf("%lld\n", query(1, 1, N, b, c));
    }
  }
}

/*
  Segment Tree with Lazy Propagation
  
  update와 query일 때 모두 lazy가 존재할 수 있다.
  그러니 두 경우 모두 lazy가 있는지 체크하고, 있으면 segtree의 노드에 lazy를 반영한 다음 자식 노드로 lazy를 전파한다.
  
  그리고 update일 때는 탐색한 노드에 대해서는 제대로 된 값이 들어가야 하므로 segtree에서 해당 노드의 값을 업데이트하는 코드를 추가한다.
  
  요약하면 대략 다음과 같을 것이다.
  1. lazy 체크
  2-1. 영역을 벗어나거나 영역에 포함되어 바로 반환하는 경우. update 함수에서는 해당 노드의 값은 바로 수정하지만 자식 노드의 업데이트는 당장 하지 않을 것이므로 자식 노드의 lazy에 diff를 더함.
  2-2. 반으로 쪼개고 재귀 호출. 자식 노드에서도 update 함수가 호출되었으므로 segtree에서 해당 노드들의 값에는 모든 lazy가 반영되어 있다. 그러므로 부모 노드의 값을 자식 노드들의 값의 합으로 업데이트.
*/