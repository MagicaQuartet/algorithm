#include<cstdio>
#include<vector>
using namespace std;
typedef vector<int> vi;
int N, M, T;
int parent[51];

int find(int node) {
  if (parent[node] == node) {
    return node;
  }
  return parent[node] = find(parent[node]);
}

void merge(int lhs, int rhs) {
  int lhsRoot = find(lhs);
  int rhsRoot = find(rhs);
  if (lhsRoot == rhsRoot) {
    return;
  }
  parent[rhsRoot] = lhsRoot;
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i=1; i<=N; i++) {
    parent[i] = i;
  }
  scanf("%d", &T);
  vi trueman;
  for (int i=0; i<T; i++) {
    int t;
    scanf("%d", &t);
    if (i>0) {
      merge(trueman[i-1], t);
    }
    trueman.push_back(t);
  }
  vector<vi > party;
  for (int i=0; i<M; i++) {
    int n;
    scanf("%d", &n);
    party.push_back(vi());
    for (int j=0; j<n; j++) {
      int member;
      scanf("%d", &member);
      if (j>0) {
        merge(party[i][j-1], member);
      }
      party[i].push_back(member);
    }
  }

  if (T == 0) {
    printf("%d\n", M);
    return 0;
  }

  int ans = 0;
  for (int i=0; i<M; i++) {
    int check = 1;
    for (int member: party[i]) {
      if (find(member) == find(trueman[0])) {
        check = 0;
        break;
      }
    }
    ans += check;
  }
  printf("%d\n", ans);
}
