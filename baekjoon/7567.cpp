#include<cstdio>

int sum;
char cur, pre;

int main() {
  pre = 0;
  sum = 0;
  
  while ((cur=getchar()) != '\n') {
    sum += (cur == pre) ? 5 : 10;
    pre = cur;
  }
  
  printf("%d\n", sum);
}