#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int countRows(const vector<vector<char>>& board) {
  int cnt = 1;
  for (int i=0; i<board.size(); i++) {
    int _cnt = 1;
    for (int j=1; j<board.size(); j++) {
      if (board[i][j] == board[i][j-1]) {
        _cnt++;
      }
      else {
        cnt = max(_cnt, cnt);
        _cnt = 1;
      }
    }
    cnt = max(_cnt, cnt);
  }
  return cnt;
}

int countColumns(const vector<vector<char>>& board) {
  int cnt = 1;
  for (int j=0; j<board.size(); j++) {
    int _cnt = 1;
    for (int i=1; i<board.size(); i++) {
      if (board[i][j] == board[i-1][j]) {
        _cnt++;
      }
      else {
        cnt = max(_cnt, cnt);
        _cnt = 1;
      }
    }
    cnt = max(_cnt, cnt);
  }
  return cnt;
}

int main() {
  int N, cnt;
  vector<vector<char>> board;
  scanf("%d", &N);
  
  for (int i=0; i<N; i++) {
    board.push_back(vector<char>(N, '\n'));
    for (int j=0; j<N; j++) {
      do {
        board[i][j] = getchar();
      } while(board[i][j] == '\n');
    }
  }
  
  cnt = 1;
  
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (i != N-1) {
        swap(board[i+1][j], board[i][j]);
        cnt = max(cnt, countRows(board));
        swap(board[i+1][j], board[i][j]);
      }
      
      if (j != N-1) {
        swap(board[i][j+1], board[i][j]);
        cnt = max(cnt, countColumns(board));
        swap(board[i][j+1], board[i][j]);
      }
    }
  }
  
  printf("%d\n", cnt);
}

/* 단순한 방법으로 풀었다. 근데 시간이 12ms나 걸렸는데 0ms 답안을 확인해볼 필요가 있겠다. */