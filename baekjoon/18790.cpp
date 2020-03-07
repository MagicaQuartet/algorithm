#include<cstdio>
#include<vector>
using namespace std;
int N;
bool solve(vector<int>& cnt, vector<int>& ans, int n, int sum, int idx) {
  if (n == N) {
    return sum == 0;
  }
  
  bool ret = false;
  
  for (int i=idx; i<N; i++) {
    if (cnt[i] > 0) {
      ans[n] = i;
      cnt[i]--;
      ret = solve(cnt, ans, n+1, (sum+i)%N, i);
      cnt[i]++;
      
      if (ret) break;
    }
  }
  
  return ret;
}
int main() {
  scanf("%d", &N);
  vector<int> cnt(N, 0);
  vector<int> ans(N, 0);
  for (int i=0; i<2*N-1; i++) {
    int num;
    scanf("%d", &num);
    cnt[num]++;
  }

  bool ret = solve(cnt, ans, 0, 0, 0);
  if (ret) {
    for (auto i : ans) {
      printf("%d ", i);
    } 
  }
  else {
    printf("-1");
  }
}