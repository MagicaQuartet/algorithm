#include<cstdio>
using namespace std;
int N, K;
int main() {
  scanf("%d%d", &N, &K);
  int ans = 0;
  for (int i=1; i<=N; i++) {
    int num = i;
    for (int Q=2; Q<=K && num>=Q; Q++) {
      while (num%Q == 0) {
        num /= Q;
      }
    }
    if (num == 1) {
      ans++;
    }
  }
  printf("%d\n", ans);
}
