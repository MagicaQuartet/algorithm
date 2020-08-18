#include<cstdio>
#include<queue>
#include<utility>
#define ppi pair<pair<int, int>, int>
using namespace std;

int N, M;
int uf[100010];

struct cmp {
  bool operator() (ppi lhs, ppi rhs) {
    return lhs.second > rhs.second;
  }
};

int find(int node) {
  if (node == uf[node]) {
    return node;
  }
  
  return uf[node] = find(uf[node]);
}

void merge(int lhs, int rhs) {
  int lr = find(lhs);
  int rr = find(rhs);
  
  if (lr < rr) {
    uf[rr] = lr;
  }
  else {
    uf[lr] = rr;
  }
}

int main() {
  scanf("%d %d", &N, &M);
  priority_queue<ppi, vector<ppi >, cmp> pq;

  for (int i=1; i<=N; i++) {
    uf[i] = i;
  }

  for (int i=0; i<M; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    pq.push({{a, b}, c});
  }

  int ans = 0;
  while (!pq.empty()) {
    int a = pq.top().first.first;
    int b = pq.top().first.second;
    int c = pq.top().second;
    pq.pop();
    
    int lr = find(a);
    int rr = find(b);
    if (lr == rr) {
      continue;
    }
    
    merge(lr, rr);
    ans += c;
  }
  printf("%d\n", ans);
}