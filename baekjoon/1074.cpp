#include<cstdio>
int N, R, C;
int solve(int n, int r, int c) {
  if (n == 0) {
    return 0;
  }

  if (c >= (1<<(n-1)) && r < (1<<(n-1))) {
    return (1<<(2*n-2)) + solve(n-1, r, c-(1<<(n-1)));
  }
  else if (r >= (1<<(n-1)) && c < (1<<(n-1))) {
    return (1<<(2*n-2))*2 + solve(n-1, r-(1<<(n-1)), c);
  }
  else if (r >= (1<<(n-1)) && c >= (1<<(n-1))) {
    return (1<<(2*n-2))*3 + solve(n-1, r-(1<<(n-1)), c-(1<<(n-1)));
  }
  else {
    return solve(n-1, r, c);
  }
}
int main() {
  scanf("%d %d %d", &N, &R, &C);
  printf("%d\n", solve(N, R, C));
}
