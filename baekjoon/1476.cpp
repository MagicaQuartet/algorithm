#include<cstdio>
int e, s, m;
int main() {
  scanf("%d %d %d", &e, &s, &m);
  for (int y=0; y<285; y++) {
    int num = 28*y+(s-1);
    if (num%15!=(e-1) || num%19!=(m-1)) continue;
    printf("%d\n", num+1);
    break;
  }
}