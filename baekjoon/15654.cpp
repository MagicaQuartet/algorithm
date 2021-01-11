#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, arr[10], visited[10];
void solve(vector<int>& ans) {
  if (ans.size()==M) {
    for (auto num: ans) {
      printf("%d ", num);
    }
    printf("\n");
    return;
  } 
  for (int i=0; i<N; i++) {
    if (visited[i] == 1) continue;
    visited[i] = 1;
    ans.push_back(arr[i]);
    solve(ans);
    visited[i] = 0;
    ans.pop_back();
  }
}
int main() {
  scanf("%d %d", &N, &M);
  for (int i=0; i<N; i++) {
    scanf("%d", arr+i);
    visited[i] = 0;
  }
  sort(arr, arr+N);
  vector<int> ans;
  ans.reserve(M);
  solve(ans);
}