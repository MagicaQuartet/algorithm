#include<cstdio>
int x, y;
int main() {
  while (1) {
    scanf("%d %d", &x, &y);
    if (x == 0 && y == 0) break;
    printf("%s\n", (x%y==0) ? "multiple" : ((y%x==0) ? "factor" : "neither"));
  }
}