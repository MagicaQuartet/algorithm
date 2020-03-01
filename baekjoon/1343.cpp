#include<cstdio>
int main() {
  char c, str[501];
  int cnt = 0, idx = 0;
  while((c=getchar()) != EOF && c != '\n') {
    if (c == 'X') {
      cnt++;
      if (cnt == 4) {
        for (int i=0; i<4; i++) {
          str[idx++] = 'A';
        }
        cnt = 0;
      }
    }
    else {
      if (cnt == 2) {
        for (int i=0; i<2; i++) {
          str[idx++] = 'B';
        }
        cnt = 0;
      }
      else if (cnt > 0) {
        printf("-1\n");
        return 0;
      }
      
      str[idx++] = '.';
    }
  }
  if (cnt == 2) {
    for (int i=0; i<2; i++) {
      str[idx++] = 'B';
    }
    cnt = 0;
  }
  else if (cnt > 0){
    printf("-1\n");
    return 0;
  }
  str[idx] = 0;
  printf("%s\n", str);
}