#include<cstdio>
#include<set>
using namespace std;

int n, k;
int cards[11];
int visited[11];
set<int> result;

void solve(int left, int sum) {
  if (!left) {
    result.insert(sum);
    return;
  }

  for (int i=0; i<n; i++) {
    if (visited[i]) {
      continue;
    }
    visited[i] = 1;
    solve(left-1, sum*(cards[i] < 10 ? 10 : 100) + cards[i]);
    visited[i] = 0;
  }
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i=0; i<n; i++) {
    scanf("%d", cards+i);
    visited[i] = 0;
  }
  solve(k, 0);
  printf("%d\n", result.size());
}