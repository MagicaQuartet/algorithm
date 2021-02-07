#include<cstdio>
#include<vector>
using namespace std;
int N, M;
void pick(int idx, vector<int>& used) {
  if (used.size() >= M) {
    for (int num: used) {
      printf("%d ", num);
    }
    printf("\n");
    return;
  }
  if (idx > N) {
    return;
  }

  for (int i=idx; i<=N; i++) {
    used.push_back(i);
    pick(i, used);
    used.pop_back();
  }
}
int main() {
  scanf("%d%d", &N, &M);
  vector<int> used;
  pick(1, used);
}