#include<cstdio>
#include<cstring>
int N, num, segtree[400010], ret[100010];

int update(int node, int nodeLeft, int nodeRight, int target, int newValue) {
  if (target < nodeLeft || nodeRight < target) {
    return segtree[node];
  }
  
  if (nodeLeft == nodeRight) {
    return segtree[node] = newValue;
  }
  
  int mid = (nodeLeft + nodeRight) / 2;
  int retLeft = update(node*2, nodeLeft, mid, target, newValue);
  int retRight = update(node*2+1, mid+1, nodeRight, target, newValue);
  return segtree[node] = retLeft + retRight;
}

int query(int node, int nodeLeft, int nodeRight, int pos) {
  if (nodeLeft == nodeRight) {
    return nodeLeft;
  }
  
  int mid = (nodeLeft + nodeRight) / 2;
  
  if (pos < segtree[node*2]) {
    return query(node*2, nodeLeft, mid, pos);
  }
  else {
    return query(node*2+1, mid+1, nodeRight, pos-segtree[node*2]);
  }
}

int main() {
  scanf("%d", &N);
  memset(segtree, 0, sizeof(segtree));
  
  for (int i=1; i<=N; i++) {
    update(1, 1, N, i, 1);
  }
  
  for (int i=1; i<=N; i++) {
    scanf("%d", &num);
    
    int q = query(1, 1, N, num);
    ret[q] = i;
    update(1, 1, N, q, 0);
  }
  
  for (int i=1; i<=N; i++) {
    printf("%d\n", ret[i]);
  }
}

/*
  처음에는 아무 생각없이 BIT를 써보려고 했다. 근데 아무리 머리를 굴려도 query 한번 돌려서 나온 위치에 이미 숫자가 배치되어 있을 경우 다시 query를 돌려야 되는데 이게 최악의 경우 O(N^2)가 될 것 같았다.
  
  'k번째 답 구하기' 유형의 문제처럼, 이 문제도 O(logN)만에 각 숫자가 들어갈 위치를 찾을 수 있어야 한다. BIT의 경우 한 숫자에 대해 탐색을 여러 번 수행해야하기 때문에 위와 같은 경우가 나올 수 있다. 그러나 전체 트리의 정보를 저장하는 segment tree를 이용하면 어떤 경우에든 한 번의 탐색으로 위치를 찾을 수 있었다.
  
  구간 합을 구하는 문제는 BIT를 이용하는 것이 더 간결하다~ 라는 말만 기억하고 풀기 시작했지만 항상 그렇게 단순히 들어맞지는 않는다는 것을 배웠다. 근데 혹시 BIT로도 빠르게 풀 수 있으려나...?
*/