#include<cstdio>
int cnt5, N;
int main() {
  scanf("%d", &N);
  cnt5 = 0;
  for (int i=5; i<=N; i+=5) {
    int num = i;
    while (num%5 == 0) {
      cnt5++;
      num /= 5;
    }
  }
  printf("%d\n", cnt5);
}