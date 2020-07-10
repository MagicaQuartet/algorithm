#include<cstdio>

char board[5][15], c;
int idx;

int main() {
  for (int i=0; i<5; i++) {
    for (int j=0; j<15; j++) {
      board[i][j] = 0;
    }
  }
  
  for (int i=0; i<5; i++) {
    idx = 0;
    while(1) {
      c = getchar();
      if (c == '\n') {
        break;
      }
      
      board[i][idx++] = c;
    }
  }
  
  for (int j=0; j<15; j++) {
    for (int i=0; i<5; i++) {
      if (board[i][j] == 0) {
        continue;
      }
      printf("%c", board[i][j]);
    }
  }
  printf("\n");
}