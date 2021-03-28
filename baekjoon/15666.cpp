#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
void solve(const vector<int>& arr, vector<int>& result, int idx, int prevNum, int passed) {
  if (result.size() == M) {
    for (auto num: result) {
      printf("%d ", num);
    }
    printf("\n");
    return;
  }

  if (idx == N) {
    return;
  }

  if (prevNum == arr[idx] && passed) {
    return solve(arr, result, idx+1, prevNum, passed);
  }

  result.push_back(arr[idx]);
  solve(arr, result, idx, arr[idx], 0);
  result.pop_back();
  solve(arr, result, idx+1, arr[idx], 1);
}
int main() {
  scanf("%d %d", &N, &M);
  vector<int> arr;
  vector<int> result;
  arr.reserve(N);
  for (int i=0; i<N; i++) {
    int num;
    scanf("%d", &num);
    arr.push_back(num);
  }
  sort(arr.begin(), arr.end());
  solve(arr, result, 0, -1, 0);
}
