#include<cstdio>
#include<vector>
using namespace std;
int N, M;
void pick(vector<int>& used, vector<int>& visited) {
  if (used.size() >= M) {
    for (int num: used) {
      printf("%d ", num);
    }
    printf("\n");
    return;
  }

  for (int i=1; i<=N; i++) {
    if (visited[i]) continue;
    visited[i] = 1;
    used.push_back(i);
    pick(used, visited);
    visited[i] = 0;
    used.pop_back();
  }
}
int main() {
  scanf("%d%d", &N, &M);
  vector<int> used;
  vector<int> visited(N+1, 0);
  pick(used, visited);
}