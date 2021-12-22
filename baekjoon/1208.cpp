#include<cstdio>
#include<cstring>
#define OFFSET 4000000
int N, S;
long long cnt[8000001];
int main() {
  scanf("%d %d", &N, &S);
  memset(cnt, 0, sizeof(cnt));
  for (int i=0; i<N; i++) {
    int num;
    scanf("%d", &num);
    if (num < 0) {
      for (int j=-num; j<=8000000; j++) {
        cnt[j+num] += cnt[j];
      }
    }
    else {
      for (int j=8000000-num; j>=0; j--) {
        cnt[j+num] += cnt[j];
      }
    }
    cnt[num+OFFSET]++;
  }
  printf("%lld\n", cnt[S+OFFSET]);
}
