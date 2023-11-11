#include<cstdio>
using namespace std;
int N;
int main() {
  scanf("%d", &N);
  int ans = 0;
  for (int i=1; i<=N; i++)  {
    if (i == 100) {
      continue;
    }
    int D;
    scanf("%d", &D);
    if (i >= 10 && (i/10 != i%10)) {
      continue;
    }
    int temp = i;
    if (i >= 10) {
      temp = i%10;
    }
    while (temp <= D) {
      ans++;
      temp = temp * 10 + (i%10);
    }
  }
  printf("%d\n", ans);
}
