#include<cstdio>
int N, sum, cnt;
int main() {
  scanf("%d", &N);
  sum = 1;
  cnt = 1;
  while (1) {
    if (N <= sum) {
      printf("%d\n", cnt);
      break;
    }
    sum += 6*cnt;
    cnt++;
  }
}