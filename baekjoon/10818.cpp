#include <cstdio>
using namespace std;
int main() {
  int N, num;
  int max = -1000000, min = 1000000;
  scanf("%d", &N);
  while(N--) {
    scanf("%d", &num);
    if (max < num)
      max = num;
    if (min > num)
      min = num;
  }
  printf("%d %d\n", min, max);
  return 0;
}