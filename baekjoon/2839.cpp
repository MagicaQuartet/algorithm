#include<cstdio>
int N;
int main() {
  scanf("%d", &N);
  for (int i=N/5; i>=0; i--) {
    if ((N-i*5)%3==0) {
      printf("%d\n", i+(N-i*5)/3);
      return 0;
    }
  }
  printf("-1\n");
}