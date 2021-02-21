#include<cstdio>
int A, B, C;
int main() {
  scanf("%d %d %d", &A, &B, &C);
  int hour = C / 60;
  int minute = C % 60;
  if (B+minute >= 60) hour++;
  printf("%d %d\n", (A+hour)%24, (B+minute)%60);
}