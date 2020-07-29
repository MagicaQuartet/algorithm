#include<cstdio>

int idx = 0;
char str[5] = "UCPC";

int main() {
  char c;

  while ((c=getchar()) != '\n') {
    if (idx > 3) {
      continue;
    }

    if (c == str[idx]) {
      idx++;
    }
  }

  printf("%s\n", idx > 3 ? "I love UCPC" : "I hate UCPC");
}