#include<cstdio>
#include<algorithm>

#define INF 1000000001
using namespace std;

int N, M, a, b, data[100010], rangeMin[400100], rangeMax[400100];

int constructMin(int node, int nodeLeft, int nodeRight) {
  if (nodeLeft == nodeRight) {
    rangeMin[node] = data[nodeLeft];
    return rangeMin[node];
  }
  
  int mid = (nodeLeft + nodeRight) / 2;
  int retLeft = constructMin(node*2, nodeLeft, mid);
  int retRight = constructMin(node*2+1, mid+1, nodeRight);
  rangeMin[node] = min(retLeft, retRight);
  return rangeMin[node];
}

int constructMax(int node, int nodeLeft, int nodeRight) {
  if (nodeLeft == nodeRight) {
    rangeMax[node] = -data[nodeLeft];
    return rangeMax[node];
  }
  
  int mid = (nodeLeft + nodeRight) / 2;
  int retLeft = constructMax(node*2, nodeLeft, mid);
  int retRight = constructMax(node*2+1, mid+1, nodeRight);
  rangeMax[node] = min(retLeft, retRight);
  return rangeMax[node];
}

int query(int tree[], int node, int nodeLeft, int nodeRight, int left, int right) {
  if (right < nodeLeft || nodeRight < left) {
    return INF;
  }
  
  if (left <= nodeLeft && nodeRight <= right) {
    return tree[node];
  }
  
  int mid = (nodeLeft + nodeRight) / 2;
  int retLeft = query(tree, node*2, nodeLeft, mid, left, right);
  int retRight = query(tree, node*2+1, mid+1, nodeRight, left, right);
  return min(retLeft, retRight);
}

int main() {
  scanf("%d %d", &N, &M);
  
  for (int i=1; i<=N; i++) {
    scanf("%d", data+i);
  }
  
  constructMin(1, 1, N);
  constructMax(1, 1, N);
  
  for (int i=0; i<M; i++) {
    scanf("%d %d", &a, &b);
    printf("%d %d\n", query(rangeMin, 1, 1, N, a, b), -query(rangeMax, 1, 1, N, a, b));
  }
}