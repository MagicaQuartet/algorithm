#include<cstdio>
using namespace std;
int A, B, N;
int main() {
  scanf("%d%d%d", &A, &B, &N);
  int P = A - B*(A/B);
  int ans = 0;
  while (N-- && P > 0) {
    ans = P*10/B;
    P = P*10 - B*ans;
  }
  printf("%d\n", ans);
}
