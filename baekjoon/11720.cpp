#include<cstdio>
int N, sum;
char c;
int main() {
  scanf("%d", &N);
  sum = 0;
  while((c=getchar())=='\n');
  for (int i=0; i<N; i++) {
    sum += c-48;
    c=getchar();
  }
  printf("%d\n", sum);
}