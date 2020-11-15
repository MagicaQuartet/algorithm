#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#define pii pair<int, int>
using namespace std;

int n, a, b, w;
int ans;

int solve(const vector<vector<pii > >& tree, int node) {
  int ret = 0;
  vector<int> childWeight;

  for (pii child: tree[node]) {
    childWeight.push_back(solve(tree, child.first)+child.second);
  }

  sort(childWeight.begin(), childWeight.end());

  for (int weight: childWeight) {
    ret = max(ret, weight);
  }

  if (childWeight.size() > 1) {
    ans = max(ans, childWeight[childWeight.size()-1]+childWeight[childWeight.size()-2]);
  }

  return ret;
}

int main() {
  scanf("%d", &n);
  vector<vector<pii > > tree(n, vector<pii >());

  for (int i=0; i<n-1; i++) {
    scanf("%d %d %d", &a, &b, &w);
    tree[a-1].push_back(make_pair(b-1, w));
  }

  ans = 0;
  int ret = solve(tree, 0);
  printf("%d\n", max(ret, ans));
}