#include<cstdio>
int n, port, cnt, cache[40000];
int main() {
  scanf("%d", &n);
  cnt = 0;
  for (int i=0; i<n; i++) {
    scanf("%d", &port);
    cache[i] = -1;
    for (int j=0; j<=i; j++) {
      if (cache[j] == -1 || port <= cache[j]) {
        cache[j] = port;
        if (cnt < j+1) {
          cnt = j+1;
        }
        break;
      }
    }
  }
  printf("%d\n", cnt);
}

/* 이런 유형의 문제도 LIS 문제로 바꿀 수 있구나! 신기하넹 */