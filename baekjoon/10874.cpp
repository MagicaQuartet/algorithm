#include<cstdio>
int N;
int main() {
  scanf("%d", &N);
  for (int i=1; i<=N; i++) {
    int wa = false;
    for (int j=0; j<10; j++) {
      int num;
      scanf("%d", &num);
      if (wa) continue;
      if (j%5+1 != num) wa = true;
    }
    if (!wa) printf("%d\n", i);
  }
}