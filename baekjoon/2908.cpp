#include<cstdio>
int A, B;
int main() {
  scanf("%d %d", &A, &B);
  A = 100*(A%10) + 10*(A%100/10) + A/100;
  B = 100*(B%10) + 10*(B%100/10) + B/100;
  printf("%d\n", A>B?A:B);
}