#include<cstdio>
int T, score, sum;
char c;
int main() {
  scanf("%d", &T);
  while(T--) {
    score = 0;
    sum = 0;
    while((c=getchar())=='\n') {}
    while(c!='\n' && c!=EOF) {
      if (c == 'O') {
        score++;
        sum += score;
      }
      else {
        score = 0;
      }
      c=getchar();
    }
    printf("%d\n", sum);
  }
}