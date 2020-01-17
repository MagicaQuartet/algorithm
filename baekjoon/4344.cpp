#include<cstdio>
#include<cstring>
int C, N, num, score[1001];
double sum, cnt;
int main() {
  scanf("%d", &C);
  while(C--) {
    cnt = sum = 0;
    memset(score, 0, 4004);
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
      scanf("%d", &num);
      score[i] = num;
      sum += num;
    }
    for (int i=0; i<N; i++) {
      if (score[i] > sum/N) {
        cnt += 1;
      }
    }
    printf("%.3f%%\n", 100*cnt/N);
  }
}