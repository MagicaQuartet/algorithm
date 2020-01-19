#include<cstdio>
#include<cstring>
int N, num, ans, lds[1000];
int main() {
  ans = 0;
  memset(lds, 0, 4000);
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    scanf("%d", &num);
    for (int j=0; j<=i; j++) {
      if (lds[j] <= num) {
        lds[j] = num;
        if (ans < j+1) {
          ans = j+1;
        }
        break;
      }
    }
  }
  printf("%d\n", ans);
}

/* DP를 이용한 LIS / LDS 길이 구하기 잘 기억해두자 */