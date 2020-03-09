#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N, ans;
int dfs(const vector<vector<int> >& tree, int k) {
  int ret = 0;
  
  vector<int> cnt(tree[k].size(), 0);
  for (int i=0; i<tree[k].size(); i++) {
    cnt[i] = dfs(tree, tree[k][i]);
  }
  
  if (cnt.size()) {
    sort(cnt.begin(), cnt.end());
    reverse(cnt.begin(), cnt.end());
    for (int i=0; i<cnt.size(); i++) {
      ret = max(ret, cnt[i]+1+i);
    }
  }
  
  return ret;
}
int main() {
  scanf("%d", &N);
  vector<vector<int> > tree(N, vector<int>());
  for (int i=0; i<N; i++) {
    int parent;
    scanf("%d", &parent);
    if (parent > -1) {
      tree[parent].push_back(i);
    }
  }
  
  printf("%d\n", dfs(tree, 0));
}

/*
  처음에는 0번부터 시작해서 직접적인 부하가 가장 많은 부하를 선택하도록 하였다. 그러나 이는 최적해가 아니다.
  다음에는 직접적인 부하 각각을 root로 하는 subtree를 이루는 요소의 수가 큰 쪽부터 선택하도록 하였다. 그런데 이것도 최적해가 아니다.
  
  메시지를 전하는 데에 걸리는 시간은 전달할 사람 수 뿐만 아니라 해당 트리의 구조에도 영향을 받는다. 예를 들어, 사람 수가 적은데 linear하게 생긴 트리에서는 사람 수가 더 많지만 균형잡힌 트리에서보다 시간이 더 걸릴 수 있다.
  
  그래서 최적해를 찾기 위해서는, 직접적인 부하 각각을 root로 하는 subtree 내에서 메시지를 모두 전달하는데에 걸린 시간을 체크하고 걸리는 시간이 가장 큰 쪽부터 선택해야한다.
*/