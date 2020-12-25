#include<cstdio>
#include<algorithm>
using namespace std;
int T, A, B;

int main() {
  scanf("%d", &T);
  while(T--) {
    scanf("%d %d", &A, &B);

    int a = max(A, B);
    int b = min(A, B);
    int r = a % b;
    while (r) {
      a = b;
      b = r;
      r = a%b;
    }

    printf("%d\n", A*B/b);
  }
}