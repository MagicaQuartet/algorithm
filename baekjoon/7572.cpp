#include<cstdio>

int N, diff;

int main() {
  scanf("%d", &N);
  diff = N-2013+2040;
  
  printf("%c%d\n", 'A'+(diff+5)%12, (diff+9)%10);
}