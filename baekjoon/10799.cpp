#include<cstdio>

char c;
int cnt, sum;
bool afterLazer;

int main() {
  cnt = sum = 0;
  afterLazer = false;
  
  while ((c=getchar())!='\n') {
    if (c == '(') {
      cnt++;
      afterLazer = false;
    }
    else {
      if (afterLazer) {
        cnt--;
        sum++;
      }
      else {
        cnt--;
        sum += cnt;
        afterLazer = true;
      }
    }
  }
  
  printf("%d\n", sum);
}