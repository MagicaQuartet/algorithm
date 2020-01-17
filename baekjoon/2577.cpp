#include<cstdio>
#include<cstring>
int A, B, C, num;
int cnt[10];
int main() {
  memset(cnt, 0, 40);
  scanf("%d %d %d", &A, &B, &C);
  num = A*B*C;
  while(num) {
    cnt[num%10]++;
    num/=10;
  }
  for (int i=0; i<10; i++) {
    printf("%d\n", cnt[i]);
  }
}