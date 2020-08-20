#include<cstdio>
#include<vector>
#include<utility>
#define pii pair<int, int>
using namespace std;

int N, Q, a, x, b, c;
int parents[200010];
int uf[200010];
vector<pair<int, pii > > offline;
vector<int> ans;

int find(int node) {
  if (node == 1) {
    return 1;
  }

  if (node == uf[node]) {
    return node;
  }

  return uf[node] = find(uf[node]);
}

void merge(int lhs, int rhs) {
  int lhsRoot = find(lhs);
  int rhsRoot = find(rhs);

  if (lhsRoot == 1) {
    swap(lhsRoot, rhsRoot);
  }

  uf[lhsRoot] = rhsRoot;
}

int main() {
  scanf("%d %d", &N, &Q);
  offline.reserve(N-1+Q);
  ans.reserve(Q);

  parents[1] = uf[1] = 1;
  for (int i=2; i<=N; i++) {
    scanf("%d", parents+i);
    uf[i] = parents[i];
  }

  for (int i=0; i<N-1+Q; i++) {
    scanf("%d %d", &x, &b);
    if (x == 0) {
      offline.push_back({x, {b, b}});
      uf[b] = b;
    }
    else {
      scanf("%d", &c);
      offline.push_back({x, {b, c}});
    }
  }

  
  
  for (int i=offline.size()-1; i>=0; i--) {
    int mode = offline[i].first;
    pii args = offline[i].second;
    if (mode == 0) {
      merge(args.first, parents[args.first]);
    }
    else {
      int lhsRoot = find(args.first);
      int rhsRoot = find(args.second);
      ans.push_back((lhsRoot == rhsRoot) ? 1 : 0);
    }
  }

  for (int i=ans.size()-1; i>=0; i--) {
    printf("%s\n", ans[i] ? "YES" : "NO");
  }
}

/*
  첫 오프라인 쿼리 풀이
  역방향 구현이 생각나는데 순방항 구현 방법을 모르겠을 때 활용하면 좋을 듯
*/