#include<cstdio>
int H, M;
int main() {
  scanf("%d %d", &H, &M);
  if (M >= 45) {
    M -= 45;
  }
  else {
    M = M + 15;
    if (H == 0) {
      H = 23;
    }
    else {
      H--;
    }
  }
  printf("%d %d\n", H, M);
}