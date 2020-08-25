#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> tree[200010];
int dp[200010][2];
int skill[200010];

// mode... 0: node 제외, 1: node 포함
int solve(int node, int mode) {
  if (dp[node][mode] != -1) {
    return dp[node][mode];
  }

  int ret = 0;

  if (mode) {
    int notSelectedSum = 0;
    vector<int> selected(tree[node].size(), 0);
    vector<int> notSelected(tree[node].size(), 0);
    for (auto child: tree[node]) {
      selected.push_back(solve(child, 0) + skill[node]*skill[child]);
      notSelected.push_back(max(solve(child, 1), solve(child, 0)));
      notSelectedSum += notSelected.back();
    }

    for (int i=0; i<selected.size(); i++) {
      ret = max(ret, selected[i]+notSelectedSum-notSelected[i]);
    }
  }
  else {
    for(auto child: tree[node]) {
      ret += max(solve(child, 1), solve(child, 0));
    }
  }

  return dp[node][mode] = ret;
}

int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d", &N);

  for (int i=2; i<=N; i++) {
    int parent;
    scanf("%d", &parent);
    tree[parent].push_back(i);
  }

  for (int i=1; i<=N; i++) {
    scanf("%d", skill+i);
  }

  printf("%d\n", max(solve(1, 0), solve(1, 1)));
}