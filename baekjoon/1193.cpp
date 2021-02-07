#include<cstdio>
int N;
int main() {
  scanf("%d", &N);
  for (int i=1; ; i++) {
    if (i*(i+1)/2 > N-1) {
      int offset = i*(i+1)/2 - N;
      int numerator = i%2 ? offset + 1 : i - offset;
      int denominator = i+1 - numerator;
      printf("%d/%d\n", numerator, denominator);
      break;
    }
  }
}