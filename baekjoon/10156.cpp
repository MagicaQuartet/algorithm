#include<cstdio>

int K, N, M;

int main() {
  scanf("%d %d %d", &K, &N, &M);
  printf("%d\n", K*N < M ? 0 : K*N - M);
}