#include<cstdio>
#include<vector>
using namespace std;
int N, M;
void solve(int i, vector<int>& arr) {
  if (arr.size()==M) {
    for (auto num: arr) {
      printf("%d ", num);
    }
    printf("\n");
    return;
  } 
  if (i>N) {
    return;
  }
  arr.push_back(i);
  solve(i+1, arr);
  arr.pop_back();
  solve(i+1, arr);
}
int main() {
  scanf("%d %d", &N, &M);
  vector<int> arr;
  arr.reserve(M);
  solve(1, arr);
}