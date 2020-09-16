#include<cstdio>
#include<cstring>
#include<utility>
#include<deque>
using namespace std;

int N, K, L;
int r, c, X;
char C;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int direction;  // ESWN 0123
int board[205][205];
int nx, ny;
int ans;

int main() {
  scanf("%d %d", &N, &K);
  memset(board, 0, sizeof(board));
  for (int i=0; i<K; i++) {
    scanf("%d %d", &r, &c);
    board[r][c] = 1;
  }

  deque<pair<int, int> > snake;
  snake.push_front(make_pair(1, 1));
  board[1][1] = -1;  
  direction = 0;
  ans = 0;

  scanf("%d", &L);
  bool done = false;
  for (int i=0; i<L; i++) {
    scanf("%d %c", &X, &C);

    if (done) {
      continue;
    }

    while (ans < X) {
      nx = snake.front().first+dx[direction];
      ny = snake.front().second+dy[direction];
      if (nx < 1 || nx > N || ny < 1 || ny > N || board[nx][ny] == -1) {
        done = true;
        break;
      }

      if (board[nx][ny] != 1) {
        board[snake.back().first][snake.back().second] = 0;
        snake.pop_back();
      }
      board[nx][ny] = -1;
      snake.push_front(make_pair(nx, ny));
      ans++;
    }

    if (C == 'L') {
      direction = (direction+4-1)%4;
    }
    else {
      direction = (direction+1)%4;
    }
  }

  if (!done) {
    nx = snake.front().first+dx[direction];
    ny = snake.front().second+dy[direction];

    while (!(nx < 1 || nx > N || ny < 1 || ny > N || board[nx][ny] == -1)) {
      if (board[nx][ny] != 1) {
        board[snake.back().first][snake.back().second] = 0;
        snake.pop_back();
      }
      board[nx][ny] = -1;
      snake.push_front(make_pair(nx, ny));
      ans++;

      nx = snake.front().first+dx[direction];
      ny = snake.front().second+dy[direction];
    }
  }

  printf("%d\n", ++ans);
}