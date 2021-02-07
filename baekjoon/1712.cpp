#include<cstdio>
int A, B, C;
int main() {
  scanf("%d%d%d", &A, &B, &C);
  printf("%d\n", B>=C ? -1 : A/(C-B)+1);
}