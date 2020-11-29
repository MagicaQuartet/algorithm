#include<cstdio>

char key;
char c;
int cnt;

int main() {
  key = 0;
  key = getchar();
  while (key != '#') {
    c = 0;
    cnt = 0;
    while (c != '\n') {
      c = getchar();
      if (key-'a' == c-'a' || key-'a' == c-'A') {
        cnt++;
      }
    }
    printf("%c %d\n", key, cnt);
    key = getchar();
  }
}