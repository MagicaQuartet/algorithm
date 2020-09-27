#include<cstdio>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;

int N, life;
int x[100010];
int p[100010];
int segtreeX[400010], segtreeP[400010];
ll sum;

int constructX(int node, int nodeLeft, int nodeRight) {
  if (nodeLeft == nodeRight) {
    return x[nodeLeft];
  }

  int mid = (nodeLeft + nodeRight) / 2;
  int retLeft = constructX(2*node, nodeLeft, mid);
  int retRight = constructX(2*node+1, mid+1, nodeRight);
  return min(retLeft, retRight);
}

int queryX(int node, int nodeLeft, int nodeRight, int left, int right) {
  if (right < nodeLeft || nodeRight < left) {
    return 1000000000;
  }

  if (left <= nodeLeft && nodeRight <= right) {
    return segtreeX[node];
  }

  int mid = (nodeLeft + nodeRight) / 2;
  int retLeft = queryX(2*node, nodeLeft, mid, left, right);
  int retRight = queryX(2*node+1, mid+1, nodeRight, left, right);
  return min(retLeft, retRight);
}

int main() {
  scanf("%d", &N);
  sum = 0;
  life = 1;
  priority_queue<int> pq;
  
  for (int i=1; i<=N; i++) {
    scanf("%d %d", x+i, p+i);
  }

  constructX(1, 1, N);

  for (int i=1; i<=N; i++) {
    if (life < 0) {
      break;
    }

    if (sum > x[i]) {
      life--;
      
      if (i<N && sum > queryX(1, 1, N, i+1, N)) {
        if (pq.top() < p[i] || sum - pq.top() > x[i]) {
          continue;
        }
        else {
          sum -= pq.top();
          pq.pop();
        }
      }
      else {
        continue;
      }

      if (sum > x[i]) {
        life--;
        continue;
      }
    }
    sum += p[i];
    pq.push(p[i]);
  }

  printf("%s\n", life >= 0 ? "Kkeo-eok" : "Zzz");
}