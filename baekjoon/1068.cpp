#include<cstdio>
#include<vector>
using namespace std;
int N, target, root, data[50];
vector<vector<int> > tree;
int dfs(int _root) {
  if (target == _root) {
    return 0;
  }
  if (tree[_root].size() == 0) {
    return 1;
  }
  
  int ret = 0;
  for (int i=0; i<tree[_root].size(); i++) {
    ret += dfs(tree[_root][i]);
  }
  return ret;
}
int main() {
  scanf("%d", &N);
  tree.reserve(N);
  for (int i=0; i<N; i++) {
    scanf("%d", data+i);
    tree.push_back(vector<int>());
  }
  
  scanf("%d", &target);
  
  for (int i=0; i<N; i++) {
    if (data[i] == -1) {
      root = i;
    }
    
    if (data[i] != -1 && data[i] != target && i != target) {
       tree[data[i]].push_back(i);
    }
  }
  
  printf("%d", dfs(root));
}

/*
  일단 온라인으로 전체 트리를 만들고 target을 지워주는 식으로 했더니 제대로 처리를 해주지 못하는 부분이 생겨서 그냥 입력을 다 받은 다음 target이 애초부터 존재하지 않도록 트리를 구성하여 해결하였음
*/