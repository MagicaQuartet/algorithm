#include<cstdio>
int main() {
  int T;
  char c;
  scanf("%d", &T);
  for (int i=0; i<T; i++) {
    printf("String #%d\n", i+1);
    do {
      c = getchar();
    } while(c=='\n');
    while(c!='\n') {
      printf("%c", c == 'Z' ? 'A': c+1);
      c = getchar();
    }
    printf("\n\n");
  }
}