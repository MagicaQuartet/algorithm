#include <cstdio>
using namespace std;
int main() {
  int A, B;
  while (true) {
    scanf("%d %d", &A, &B);
    if (A == 0) break;
    printf("%d\n", A+B);
  }
  return 0;
}