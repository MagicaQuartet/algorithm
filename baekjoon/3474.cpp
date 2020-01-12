#include<cstdio>
#include<cmath>
int main() {
  int T, num, cnt, _num;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &num);
    cnt = 0;
    while (num > 0) {
      cnt += num/5;
      num/=5;
    }    
    printf("%d\n", cnt);
  }
}