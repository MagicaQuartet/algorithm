#include<cstdio>
#include<vector>
#include<algorithm>
#define INF 9876543210
using namespace std;

int n, y, r, m, Y, X;
int segtree[200010];
vector<int> years;
vector<int> preci;

int construct(int node, int nodeLeft, int nodeRight) {
  if (nodeLeft == nodeRight) {
    return segtree[node] = preci[nodeLeft];
  }

  int mid = (nodeLeft + nodeRight) / 2;
  int retLeft = construct(2*node, nodeLeft, mid);
  int retRight = construct(2*node+1, mid+1, nodeRight);
  return segtree[node] = max(retLeft, retRight);
}

int query(int node, int nodeLeft, int nodeRight, int left, int right) {
  if (nodeRight < left || right < nodeLeft) {
    return -INF;
  }

  if (left <= nodeLeft && nodeRight <= right) {
    return segtree[node];
  }

  int mid = (nodeLeft + nodeRight) / 2;
  int retLeft = query(2*node, nodeLeft, mid, left, right);
  int retRight = query(2*node+1, mid+1, nodeRight, left, right);
  return max(retLeft, retRight);
}

int main() {
  scanf("%d", &n);
  years.reserve(n+2);
  preci.reserve(n+2);

  years.push_back(-INF);
  preci.push_back(-INF);

  for (int i=1; i<=n; i++) {
    scanf("%d %d", &y, &r);
    years.push_back(y);
    preci.push_back(r);
  }

  construct(1, 1, n);

  scanf("%d", &m);
  for (int i=0; i<m; i++) {
    scanf("%d %d", &Y, &X);

    vector<int>::iterator xlb = lower_bound(years.begin(), years.end(), X);
    vector<int>::iterator ylb = lower_bound(years.begin(), years.end(), Y);
    vector<int>::iterator yub = upper_bound(years.begin(), years.end(), Y);

    int xlbidx = xlb - years.begin();
    int ylbidx = ylb - years.begin();
    int yubidx = yub - years.begin();
    int prevMax = (yubidx <= xlbidx-1) ? query(1, 1, n, yubidx, xlbidx-1) : -INF;

    if (xlb != years.end() && ylb != years.end() && years[xlbidx] == X && years[ylbidx] == Y) {
      if (preci[xlbidx] > preci[ylbidx]) {
        printf("false\n");
      }
      else if (X-Y > 1 && preci[ylbidx] == 1) {
        printf("false\n");
      }
      else if (prevMax >= preci[xlbidx]) {
        printf("false\n");
      }
      else if (years[xlbidx] - years[ylbidx] == xlbidx - ylbidx) {
        printf("true\n");
      }
      else {
        printf("maybe\n");
      }
    }
    else {
      if (ylb == years.end()) {
        printf("maybe\n");
      }
      else if (years[ylbidx] == Y && X-Y > 1 && preci[ylbidx] == 1) {
        printf("false\n");
      }
      else if (years[ylbidx] == Y && prevMax >= preci[ylbidx]) {
        printf("false\n");
      }
      else if (xlb == years.end()) {
        printf("maybe\n");
      }
      else if (years[xlbidx] == X) {
        if (X-Y > 1 && preci[xlbidx] == 1) {
          printf("false\n");
        }
        else if (prevMax >= preci[xlbidx]) {
          printf("false\n");
        }
        else {
          printf("maybe\n");
        }
      }
      else {
        printf("maybe\n");
      }
    }
  }
}

/*
  와 이걸 맞네...
  '특정 구간의 최댓값을 세그먼트 트리로 찾는다'를 베이스로 깔고 경우의 수를 잘 나누면 된다.
*/