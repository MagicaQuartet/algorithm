#include<cstdio>
#include<vector>
#include<utility>

using namespace std;

int N;
vector<vector<int>> board;

int up(int max) {
  int _max = max;
  vector<pair<int, int>> buffer;
  
  for(int j=0; j<N; j++) {
    buffer.clear();
    for(int i=0; i<N; i++) {
      if (board[i][j] != 0) {
        if (buffer.empty() || buffer.back().second == 1 || buffer.back().first != board[i][j]) {
          buffer.push_back(make_pair(board[i][j], 0));
        }
        else {
          buffer.back().first += board[i][j];
          buffer.back().second = 1;
        }
      }
    }
    
    for (int i=0; i<N; i++) {
      if (i < buffer.size()) {
        board[i][j] = buffer[i].first;
        
        if (buffer[i].first > _max) {
          _max = buffer[i].first;
        }
      }
      else {
        board[i][j] = 0;
      }
    }
  }
  
  return _max;
}

int down(int max) {
  int _max = max;
  vector<pair<int,int>> buffer;
  
  for (int j=0; j<N; j++) {
    buffer.clear();
    for (int i=N-1; i>=0; i--) {
      if (board[i][j] != 0) {
        if (buffer.empty() || buffer.back().second == 1 || buffer.back().first != board[i][j]) {
          buffer.push_back(make_pair(board[i][j], 0));
        }
        else {
          buffer.back().first += board[i][j];
          buffer.back().second = 1;
        }
      }
    }
    
    for (int i=N-1; i>=0; i--) {
      if (N - 1 - i < buffer.size()) {
        board[i][j] = buffer[N - 1 - i].first;
        
        if (buffer[N - 1 - i].first > _max) {
          _max = buffer[N - 1 - i].first;
        }
      }
      else {
        board[i][j] = 0;
      }
    }
  }

  return _max;
}

int left(int max) {
  int _max = max;
  vector<pair<int, int>> buffer;
  for (int i=0; i<N; i++) {
    buffer.clear();
    for (int j=0; j<N; j++) {
      if (board[i][j] != 0) {
        if (buffer.empty() || buffer.back().second == 1 || buffer.back().first != board[i][j]) {
          buffer.push_back(make_pair(board[i][j], 0));
        }
        else {
          buffer.back().first += board[i][j];
          buffer.back().second = 1;
        }
      }
    }
    
    for (int j=0; j<N; j++) {
      if (j < buffer.size()) {
        board[i][j] = buffer[j].first;
        
        if (buffer[j].first > _max) {
          _max = buffer[j].first;
        }
      }
      else {
        board[i][j] = 0;
      }
    }
  }

  return _max;
}

int right(int max) {
  int _max = max;
  vector<pair<int, int>> buffer;
  for (int i=0; i<N; i++) {
    buffer.clear();
    for (int j=N-1; j>=0; j--) {
      if (board[i][j] != 0) {
        if (buffer.empty() || buffer.back().second == 1 || buffer.back().first != board[i][j]) {
          buffer.push_back(make_pair(board[i][j], 0));
        }
        else {
          buffer.back().first += board[i][j];
          buffer.back().second = 1;
        }
      }
    }
    
    for (int j=N-1; j>=0; j--) {
      if (N - 1 - j < buffer.size()) {
        board[i][j] = buffer[N - 1 - j].first;
        
        if (buffer[N - 1 - j].first > _max) {
          _max = buffer[N - 1 - j].first;
        }
      }
      else {
        board[i][j] = 0;
      }
    }
  }
 
  return _max;
}

int move(int cnt, int max) {
  if (cnt == 5) {
    return max;
  }
  
  int u, d, l, r;
  
  vector<vector<int>> _board = board;
  
  u = move(cnt+1, up(max));
  if (max < u) {
    max = u;
  }
  board = _board;
  
  d = move(cnt+1, down(max));
  if (max < d) {
    max = d;
  }
  board = _board;
  
  l = move(cnt+1, left(max));
  if (max < l) {
    max = l;
  }
  board = _board;
  
  r = move(cnt+1, right(max));
  if (max < r) {
    max = r;
  }
  board = _board;
  
  return max;
}

int main() {
  int block, max;
  scanf("%d", &N);
  
  max = 0;
  
  for (int i=0; i<N; i++) {
    board.push_back(vector<int>());
    for (int j=0; j<N; j++) {
      scanf("%d", &block);
      board[i].push_back(block);
      
      if (max < block) {
        max = block;
      }
    }
  }

  printf("%d\n", move(0, max));
}

/* 상하좌우로 조작할 때 블록이 모두 잘 움직이는지 잘 확인하도록 하자. */
/* 여기서는 조건부 스택?처럼 자료구조를 사용하여 블록이 합쳐진 결과를 구한 뒤 차례대로 다시 보드판에 넣었다. */