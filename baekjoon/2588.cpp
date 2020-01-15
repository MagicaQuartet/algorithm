#include<cstdio>
int A, B, C, D, E;
int main() {
  scanf("%d %d", &A, &B);
  C = A*(B%10);
  B/=10;
  D = A*(B%10);
  B/=10;
  E = A*(B%10);
  printf("%d\n%d\n%d\n%d\n", C, D, E, 100*E+10*D+C);
}