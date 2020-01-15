#include<cstdio>
int year;
int main() {
  scanf("%d", &year);
  printf("%d\n", (year%4 == 0 && year%100 != 0) || year%400 == 0 ? 1 : 0);
}