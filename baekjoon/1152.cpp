#include<cstdio>
int cnt=0;
char c, prev;
int main() {
  prev = ' ';
  while((c=getchar())!='\n' && c!=EOF) {
    if (c == ' ' && prev != ' ') {
      cnt++;
    }
    prev = c;
  }
  if (prev != ' ') cnt++;
  printf("%d\n", cnt);
}