#include<cstdio>

int n, cnt, tmp;

int main() {
  scanf("%d", &n);
  cnt = 0;
  
  for(int i=0; i<5; i++) {
    scanf("%d", &tmp);
    if (tmp % 10 == n) {
      cnt++;
    }
  }
  
  printf("%d\n", cnt);
}