#include<stdio.h>
int x, L, P;
int main() {
  scanf("%d %d", &L, &P);
  for (int i=0; i<5; i++) {
    scanf("%d", &x);
    printf("%d ", x-L*P);
  }
}