#include<cstdio>
#include<cstring>
int N, num, max, cache[200];
int main() {
  scanf("%d", &N);
  max = 0;
  for (int i=0; i<N; i++) {
    scanf("%d", &num);
    cache[i] = 987654321;
    for (int j=0; j<=i; j++) {
      if (cache[j] >= num) {
        cache[j] = num;
        if (max < j+1) {
          max = j+1;
        }
        break;
      }
    }
  }
  printf("%d\n", N-max);
}

/* 잘 생각해보면 전체 수열의 길이와 LIS의 길이의 차를 구하면 되는 문제이다. */