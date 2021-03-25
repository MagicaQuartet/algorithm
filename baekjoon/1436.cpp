#include<cstdio>
int N;
int check666(int n) {
  int cnt = 0;
  while(n) {
    if (n%10==6) {
      cnt++;
    }
    else {
      cnt = 0;
    }
    if (cnt == 3) {
      return 1;
    }
    n/=10;
  }
  return 0;
}
int main() {
  scanf("%d", &N);
  for (int i=666;;i++) {
    if (check666(i)) {
      N--;
    }
    if (N == 0) {
      printf("%d\n", i);
      break;
    }
  }
}