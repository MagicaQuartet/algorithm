#include<cstdio>
int N;
int main() {
  scanf("%d", &N);
  int x = 2;
  while (N>1 && x<=N) {
    while(N%x == 0) {
      printf("%d\n", x);
      N /= x;
    }
    x++;
  }
}