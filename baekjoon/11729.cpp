#include<cstdio>
int N;
void hanoi(int n, int src, int aux, int dest) {
  if (n == 1) {
    printf("%d %d\n", src, dest);
    return;
  }
  hanoi(n-1, src, dest, aux);
  printf("%d %d\n", src, dest);
  hanoi(n-1, aux, src, dest);
}
int hanoi_cnt(int n) {
  if (n == 1) {
    return 1;
  }
  return 2*hanoi_cnt(n-1) + 1;
}
int main() {
  scanf("%d", &N);
  printf("%d\n", hanoi_cnt(N));
  hanoi(N, 1, 2, 3);
}
