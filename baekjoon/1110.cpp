#include<cstdio>
int N, num, cnt=0;
int main() {
  scanf("%d", &N);
  num = N;
  while(cnt == 0 || N!=num) {
    num = (num%10)*10 + (num/10+num%10)%10;
    cnt++;
  }
  printf("%d\n", cnt);
}