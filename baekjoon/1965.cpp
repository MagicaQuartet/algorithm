#include<cstdio>
int n, b, ans, box[1000];
int main() {
  scanf("%d", &n);
  ans = 0;
  for (int i=0; i<n; i++) {
    box[i] = 987654321;
    scanf("%d", &b);
    for (int j=0; j<=i; j++) {
      if (box[j] >= b) {
        box[j] = b;
        if (ans < j+1) {
          ans = j+1;
        }
        break;
      }
    }
  }
  printf("%d\n", ans);
}

/* LIS/LDS 구하는 방법을 깜빡해서 다시 찾아봤다. 역시 간단하지만 기똥차네... */
/* 각 입력을 받을 때마다 길이가 k인 LIS/LDS의 끝자리 숫자를 가지고 이리저리 하는 알고리즘이다. */