#include<cstdio>
int M, N, sum, minVal;
int main() {
  scanf("%d %d", &M, &N);
  sum = 0;
  minVal = 10001;
  for (int i=1; i<=100; i++) {
    if (i*i > N) break;
    if (i*i < M) continue;
    if (sum == 0) minVal = i*i;
    sum += i*i;
  }
  if (sum == 0) {
    printf("-1\n");
  }
  else {
    printf("%d\n%d\n", sum, minVal);
  }
}