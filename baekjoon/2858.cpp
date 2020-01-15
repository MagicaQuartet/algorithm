#include<cstdio>
int R, B, sum;
int main() {
  scanf("%d %d", &R, &B);
  sum = R+B;
  for (int i=3; i<=sum/3; i++) {
    if (sum%i == 0 && (i-2)*(sum/i-2) == B) {
      printf("%d %d\n", sum/i, i);
      break;
    }
  }
}