#include<cstdio>
#include<vector>
using namespace std;
int N, M;
void pick(vector<int>& used) {
  if (used.size() >= M) {
    for (int num: used) {
      printf("%d ", num);
    }
    printf("\n");
    return;
  }

  for (int i=1; i<=N; i++) {
    used.push_back(i);
    pick(used);
    used.pop_back();
  }
}
int main() {
  scanf("%d%d", &N, &M);
  vector<int> used;
  pick(used);
}