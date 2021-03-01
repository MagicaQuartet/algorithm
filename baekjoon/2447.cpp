#include<cstdio>
int N;
char stars[2200][2200];
void star(int n, int x, int y, char c) {
  if (n == 1) {
    stars[x][y] = c;
    return;
  }
  for (int i=0; i<=2; i++) {
    for (int j=0; j<=2; j++) {
      star(n/3, x+n/3*i, y+n/3*j, (i==1 && j==1) ? ' ' : c);
    }
  }
}
int main() {
  scanf("%d", &N);
  star(N, 0, 0, '*');
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      printf("%c", stars[i][j]);
    }
    printf("\n");
  }
}