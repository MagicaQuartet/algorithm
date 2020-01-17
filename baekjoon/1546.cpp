#include<cstdio>
#include<cstring>
int score[1001], N, num, max=0;
double sum=0;
int main() {
  memset(score, -1, 4004);
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    scanf("%d", &num);
    if (max < num) max = num;
    score[i] = num;
    sum += num;
  }
  printf("%f\n", sum/max*100/N);
}