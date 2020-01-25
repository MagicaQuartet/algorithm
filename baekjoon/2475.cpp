#include<cstdio>
int ans, num;
int main() {
  ans = 0;
  for (int i=0; i<5; i++) {
    scanf("%d", &num);
    ans += num*num;
  }
  printf("%d\n", ans%10);
}