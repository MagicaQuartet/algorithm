#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
int nums[9];
int visited[9];
int firstIdx[10010];

void solve(vector<int>& seq, int left) {
  if (left == 0) {
    for(auto i: seq) {
      printf("%d ", i);
    }
    printf("\n");
    return;
  }

  for (int i=0; i<N; i++) {
    if (visited[i] || (i>0 && nums[i-1] == nums[i] && !visited[i-1])) {
      continue;
    }
    visited[i] = 1;
    seq.push_back(nums[i]);
    solve(seq, left-1);
    visited[i] = 0;
    seq.pop_back();
  }
}

int main() {
  scanf("%d %d", &N, &M);
  memset(firstIdx, 0, sizeof(firstIdx));
  for (int i=0; i<N; i++) {
    scanf("%d", nums+i);
    visited[i] = 0;
  }
  sort(nums, nums+N);
  for (int i=0; i<N; i++) {
    if (firstIdx[nums[i]] == 0) {
      firstIdx[nums[i]] = i;
    }
  }
  vector<int> seq = vector<int>();
  solve(seq, M);
}