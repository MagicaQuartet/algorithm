#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
void pick(vector<int>& arr, int idx, vector<int>& used) {
  if (used.size() >= M) {
    for (int num: used) {
      printf("%d ", num);
    }
    printf("\n");
    return;
  }
  if (idx >= N) {
    return;
  }

  used.push_back(arr[idx]);
  pick(arr, idx+1, used);
  used.pop_back();
  pick(arr, idx+1, used);
}
int main() {
  scanf("%d%d", &N, &M);
  vector<int> arr;
  vector<int> used;
  for (int i=0; i<N; i++) {
    int num;
    scanf("%d", &num);
    arr.push_back(num);
  }
  sort(arr.begin(), arr.end());
  pick(arr, 0, used);
}