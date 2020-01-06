#include<cstdio>
#include<vector>
using namespace std;
int main() {
  int N, M, ret;
  vector<vector<char>> board;
  scanf("%d %d", &N, &M);
  
  for (int i=0; i<N; i++) {
    board.push_back(vector<char>());
    for (int j=0; j<M; j++) {
      char c;
      do {
        c=getchar();
      } while(c == '\n');
      board[i].push_back(c);
    }
  }
  
  ret = 1;
  for (int i=0; i<N-1; i++) {
    for (int j=0; j<M-1; j++) {
      for (int k=1; i+k<N && j+k<M; k++) {
        if (board[i][j] == board[i+k][j] && board[i][j] == board[i][j+k] && board[i][j] == board[i+k][j+k] && ret < (k+1)*(k+1)) {
          ret = (k+1)*(k+1);
        }
      }
    }
  }
  
  printf("%d\n", ret);
}

/* 단순하게 풀었다. 사이즈가 1인 경우를 생각 안해서 한번 틀렸다... */