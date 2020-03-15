#include<cstdio>
#include<algorithm>

#define INF 1000000001
using namespace std;

int N, M, a, b, data[100010], rangeMin[400010];

int construct(int node, int nodeLeft, int nodeRight) {
  if (nodeLeft == nodeRight) {
    rangeMin[node] = data[nodeLeft];
    return rangeMin[node];
  }
  
  int mid = (nodeLeft + nodeRight) / 2;
  int retLeft = construct(node*2, nodeLeft, mid);
  int retRight = construct(node*2+1, mid+1, nodeRight);
  rangeMin[node] = min(retLeft, retRight);
  return rangeMin[node];
}

int query(int node, int nodeLeft, int nodeRight, int left, int right) {
  if (right < nodeLeft || nodeRight < left) {
    return INF;
  }
  
  if (left <= nodeLeft && nodeRight <= right) {
    return rangeMin[node];
  }
  
  int mid = (nodeLeft + nodeRight) / 2;
  int retLeft = query(node*2, nodeLeft, mid, left, right);
  int retRight = query(node*2+1, mid+1, nodeRight, left, right);
  return min(retLeft, retRight);
}

int main() {
  scanf("%d %d", &N, &M);
  
  for (int i=1; i<=N; i++) {
    scanf("%d", data+i);
  }
  
  construct(1, 1, N);
  
  for (int i=0; i<M; i++) {
    scanf("%d %d", &a, &b);
    printf("%d\n", query(1, 1, N, a, b));
  }
}