#include<cstdio>
#include<cstring>
using namespace std;
int N;
int seq[10], visited[10];
void solve(int idx) {
  if (idx >= N) {
    for (int i=0; i<N; i++) {
      printf("%d ", seq[i]);
    }
    printf("\n");
    return;
  }
  for (int i=0; i<N; i++) {
    if (!visited[i]) {
      visited[i] = 1;
      seq[idx] = i+1;
      solve(idx+1);
      seq[idx] = 0;
      visited[i] = 0;
    }
  }
  return;
}
int main() {
  scanf("%d", &N);
  memset(seq, 0, sizeof(seq));
  memset(visited, 0, sizeof(visited));
  solve(0);
}
