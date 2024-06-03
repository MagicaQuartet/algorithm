#include<cstdio>
using namespace std;

int N, K;
int main() {
  scanf("%d%d", &N, &K);
  int ans = 0;
  while (N*2 <= K) {
    if (K % 2) {
      K -= 1;
    }
    else {
      K >>= 1;
    }
    ans++;
  }
  printf("%d\n", ans+(K-N));
}
