#include<cstdio>
int N, K, X, i, j, data[100010], segtree[400010];
char cmd;

int construct(int node, int nodeLeft, int nodeRight) {
  if (nodeLeft == nodeRight) {
    return segtree[node] = data[nodeLeft];
  }
  
  int mid = (nodeLeft + nodeRight) / 2;
  int retLeft = construct(node*2, nodeLeft, mid);
  int retRight = construct(node*2+1, mid+1, nodeRight);
  return segtree[node] = retLeft * retRight;
}

int query(int node, int nodeLeft, int nodeRight, int left, int right) {
  if (right < nodeLeft || nodeRight < left) {
    return 1;
  }
  
  if (left <= nodeLeft && nodeRight <= right) {
    return segtree[node];
  }
  
  int mid = (nodeLeft + nodeRight) / 2;
  int retLeft = query(node*2, nodeLeft, mid, left, right);
  int retRight = query(node*2+1, mid+1, nodeRight, left, right);
  return retLeft * retRight;
}

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
  return segtree[node] = retLeft * retRight;
}

int main() {
  while(scanf("%d %d", &N, &K) != EOF) {
    for (int i=1; i<=N; i++) {
      scanf("%d", &X);
      data[i] = X > 0 ? 1 : (X < 0 ? -1 : 0);
    }
    
    construct(1, 1, N);

    while(K--) {
      while ((cmd=getchar()) == '\n') {}
      
      scanf("%d %d", &i, &j);
      //printf(">>> %c %d %d\n", cmd, i, j);
      
      if (cmd == 'C') {
        update(1, 1, N, i, j > 0 ? 1 : (j < 0 ? -1 : 0));
      }
      else {
        int q = query(1, 1, N, i, j);
        printf("%c", q > 0 ? '+' : (q < 0 ? '-' : '0'));
      }
    }
    printf("\n");
  }
}