#include<cstdio>
#include<cstring>
int N;
char stars[3072][6144];
int dx[8] = {0, 1, 1, 2, 2, 2, 2, 2};
int dy[8] = {2, 1, 3, 0, 1, 2, 3, 4};

void draw(int h, int x, int y) {
  if (h == 3) {
    for (int i=0; i<8; i++) {
      stars[x+dx[i]][y+dy[i]] = '*';
    }
    return;
  }

  draw(h/2, x, y+h/2);
  draw(h/2, x+h/2, y);
  draw(h/2, x+h/2, y+h);
}

int main() {
  scanf("%d", &N);
  memset(stars, 0, sizeof(stars));
  draw(N, 0, 0);
  for (int i=0; i<N; i++) {
    for (int j=0; j<2*N-1; j++) {
      printf("%c", stars[i][j] == '*' ? '*' : ' ');
    }
    printf("\n");
  }
}
