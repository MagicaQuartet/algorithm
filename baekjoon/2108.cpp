#include<cstdio>
#include<cstring>
#define INF 4001
#define OFFSET 4000
int N;
int csort[8010];
long long sum;
int cnt, minVal, maxVal, freqVal1, freqVal2, freqCnt;
int main() {
  scanf("%d", &N);
  memset(csort, 0, sizeof(csort));
  minVal = INF+OFFSET;
  maxVal = -INF+OFFSET;
  for (int i=0; i<N; i++) {
    int num;
    scanf("%d", &num);
    num += OFFSET;
    csort[num]++;
    sum += num;
    if (minVal > num) minVal = num;
    if (maxVal < num) maxVal = num;
  }
  printf("%lld\n", (sum+N/2)/N-OFFSET);
  cnt = 0;
  freqCnt = 1;
  freqVal1 = freqVal2 = -INF;
  for (int i=8000; i>=0; i--) {
    if (cnt+csort[i] > N/2) {
      printf("%d\n", i-OFFSET);
      break;
    }
    cnt += csort[i];
  }
  for (int i=8000; i>=0; i--) {
    if (csort[i] > freqCnt) {
      freqVal2 = -INF;
      freqVal1 = i-OFFSET;
      freqCnt = csort[i];
    }
    else if (csort[i] == freqCnt) {
      freqVal2 = freqVal1;
      freqVal1 = i-OFFSET;
    }
  }
  printf("%d\n", (freqVal2==-INF)?freqVal1:freqVal2);
  printf("%d\n", maxVal-minVal);
}