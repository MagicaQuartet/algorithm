#include<cstdio>
int A, B;

int main() {
  scanf("%d %d", &A, &B);
  int ans = 0;

  while (A < B) {
    while (B%2==0) {
      if (A == B) {
        break;
      }
      ans++;
      B /= 2;
    }
    if (A == B) {
      break;
    }
    if (B%10!=1) {
      ans = -2;
      break;
    }
    ans++;
    B /= 10;
  }

  if (A != B) {
    ans = -2;
  }
  printf("%d\n", ans+1);
}
