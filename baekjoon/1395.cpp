#include<cstdio>
#include<cstring>
int N, M, O, S, T, segtree[400010], lazy[400010];

void update(int node, int nodeLeft, int nodeRight, int left, int right) {
  if (lazy[node] > 0) {
    segtree[node] = (nodeRight - nodeLeft + 1) - segtree[node];
    
    if (nodeLeft != nodeRight) {
      lazy[node*2] = !lazy[node*2];
      lazy[node*2+1] = !lazy[node*2+1];
    }
    
    lazy[node] = 0;
  }
  
  if (right < nodeLeft || nodeRight < left) {
    return;
  }
  
  if (left <= nodeLeft && nodeRight <= right) {
    segtree[node] = (nodeRight - nodeLeft + 1) - segtree[node];
    
    if (nodeLeft != nodeRight) {
      lazy[node*2] = !lazy[node*2];
      lazy[node*2+1] = !lazy[node*2+1];
    }
    
    return;
  }
  
  int mid = (nodeLeft + nodeRight) / 2;
  update(node*2, nodeLeft, mid, left, right);
  update(node*2+1, mid+1, nodeRight, left, right);
  
  segtree[node] = segtree[node*2] + segtree[node*2+1];
}

int query(int node, int nodeLeft, int nodeRight, int left, int right) {
  if (lazy[node] > 0) {
    segtree[node] = (nodeRight - nodeLeft + 1) - segtree[node];
    
    if (nodeLeft != nodeRight) {
      lazy[node*2] = !lazy[node*2];
      lazy[node*2+1] = !lazy[node*2+1];
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
  int retLeft = query(node*2, nodeLeft, mid, left, right);
  int retRight = query(node*2+1, mid+1, nodeRight, left, right);
  
  segtree[node] = segtree[node*2] + segtree[node*2+1];
  
  return retLeft + retRight;
}

int main() {
  scanf("%d %d", &N, &M);
  memset(segtree, 0, 4*(N+1));
  memset(lazy, 0, 4*(N+1));
  
  for (int i=0; i<M; i++) {
    scanf("%d %d %d", &O, &S, &T);
    
    if (O == 0) {
      update(1, 1, N, S, T);
    }
    else {
      printf("%d\n", query(1, 1, N, S, T));
    }    
  }
}

/*
  Segment Tree with Lazy Propagation
  
  개념적으로 이해는 되는데 구현이 너무나도 헷갈린다...
  (참고 링크: https://bowbowbow.tistory.com/4)
  
  일단 여기서는,
  update 시 필요한 구간을 찾으면 그 구간의 자식들에게는 바로 업데이트를 반영하지 않고 lazy를 통해 표시만 해놓는다.
  이후 lazy가 표시된 구간에 대한 query나 update가 진행될 경우 그 때 lazy를 반영한다. 마찬가지로 자식들이 필요하지 않은 경우에는 바로 전파하지 않고 lazy로 표시해둔다.
*/