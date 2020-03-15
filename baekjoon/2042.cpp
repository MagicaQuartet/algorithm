#include<cstdio>
#include<vector>
using namespace std;
#define ll long long

int N, M, K, a, b;
ll data[1000010], segtree[4000010], c;

ll construct(int node, int nodeLeft, int nodeRight) {
  if (nodeLeft == nodeRight) {
    segtree[node] = data[nodeLeft];
    return segtree[node];
  }

  int mid = (nodeLeft + nodeRight) / 2;
  ll retLeft = construct(node*2, nodeLeft, mid);
  ll retRight = construct(node*2+1, mid+1, nodeRight);
  segtree[node] = retLeft + retRight;

  return segtree[node];
}

void update(int node, int nodeLeft, int nodeRight, int target, ll diff) {
  if (target < nodeLeft || target > nodeRight) {
    return;
  }
  
  if (nodeLeft == nodeRight) {
    segtree[node] += diff;
    return;
  }
  
  int mid = (nodeLeft + nodeRight) / 2;
  update(node*2, nodeLeft, mid, target, diff);
  update(node*2+1, mid+1, nodeRight, target, diff);
  segtree[node] += diff;
  
  return;
}

ll query(int node, int nodeLeft, int nodeRight, int left, int right) {
  if (right < nodeLeft || left > nodeRight) {
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
  for (int i=1; i<=N; i++) {
    scanf("%lld", &data[i]);
  }
  
  construct(1, 1, N);
  
  for (int i=0; i<M+K; i++) {
    scanf("%d %d %lld", &a, &b, &c);
    
    if (a == 1) {
      update(1, 1, N, b, c-data[b]);
      data[b] = c;
    }
    else {
      printf("%lld\n", query(1, 1, N, b, c));
    }
  }
}

/*
  맞왜틀 특) 자료형을 ll로 안함
  
  펜윅 트리는 나중에 따로 공부해보고 시도해보자
*/