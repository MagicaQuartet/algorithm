#include <cstdio>
using namespace std;
int main() {
  int N, X, num;
  scanf("%d %d", &N, &X);
  while(N--) {
    scanf("%d", &num);
    if (num < X)
      printf("%d ", num);
  }
  printf("\n");
  return 0;
}