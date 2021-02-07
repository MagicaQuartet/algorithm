#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
void pick(vector<int>& arr, vector<int>& used) {
  if (used.size() >= M) {
    for (int num: used) {
      printf("%d ", num);
    }
    printf("\n");
    return;
  }

  for (int num: arr) {
    used.push_back(num);
    pick(arr, used);
    used.pop_back();
  }
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
  pick(arr, used);
}