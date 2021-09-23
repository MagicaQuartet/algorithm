#include<cstdio>
#include<vector>
using namespace std;
typedef vector<int> vi;


int R, C, T;
int r1 = -1, r2 = -1;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void initBuf(vector<vi >& board) {
  for (int i=0; i<R; i++) {
    board.push_back(vi());
    for (int j=0; j<C; j++) {
      board[i].push_back(0);
    }
  }
}

int main() {
  scanf("%d %d %d", &R, &C, &T);
  vector<vi > board;
  for (int i=0; i<R; i++) {
    board.push_back(vi());
    for (int j=0; j<C; j++) {
      int num;
      scanf("%d", &num);
      if (num == -1 && r1 == -1) {
        r1 = i;
        r2 = i+1;
      }
      board[i].push_back(num);
    }
  }

  for (int t=0; t<T; t++) {
    vector<vi > buf;
    initBuf(buf);
    // 확산
    for (int i=0; i<R; i++) {
      for (int j=0; j<C; j++) {
        if (board[i][j] < 5) {
          continue;
        }

        int diffuse = board[i][j] / 5;
        for (int k=0; k<4; k++) {
          int nx = i+dx[k];
          int ny = j+dy[k];
          if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
            continue;
          }
          if (board[nx][ny] == -1) {
            continue;
          }
          buf[i][j] -= diffuse;
          buf[nx][ny] += diffuse;
        }
      }
    }
    for (int i=0; i<R; i++) {
      for (int j=0; j<C; j++) {
        board[i][j] += buf[i][j];
        buf[i][j] = 0;
      }
    }
    // 공기청정기
    for (int i=1; i<C-1; i++) {
      buf[r1][i] -= board[r1][i];
      buf[r1][i+1] += board[r1][i];
    }
    for (int i=r1; i>0; i--) {
      buf[i][C-1] -= board[i][C-1];
      buf[i-1][C-1] += board[i][C-1];
    }
    for (int i=C-1; i>0; i--) {
      buf[0][i] -= board[0][i];
      buf[0][i-1] += board[0][i];
    }
    for (int i=0; i<r1-1; i++) {
      buf[i][0] -= board[i][0];
      buf[i+1][0] += board[i][0];
    }
    buf[r1-1][0] -= board[r1-1][0];

    for (int i=1; i<C-1; i++) {
      buf[r2][i] -= board[r2][i];
      buf[r2][i+1] += board[r2][i];
    }
    for (int i=r2; i<R-1; i++) {
      buf[i][C-1] -= board[i][C-1];
      buf[i+1][C-1] += board[i][C-1];
    }
    for (int i=C-1; i>0; i--) {
      buf[R-1][i] -= board[R-1][i];
      buf[R-1][i-1] += board[R-1][i];
    }
    for (int i=R-1; i>r2+1; i--) {
      buf[i][0] -= board[i][0];
      buf[i-1][0] += board[i][0];
    }
    buf[r2+1][0] -= board[r2+1][0];

    for (int i=0; i<R; i++) {
      for (int j=0; j<C; j++) {
        board[i][j] += buf[i][j];
        buf[i][j] = 0;
      }
    }
  }

  int sum = 0;
  for (int i=0; i<R; i++) {
    for (int j=0; j<C; j++) {
      if (board[i][j] < 0) {
        continue;
      }
      sum += board[i][j];
    }
  }
  printf("%d\n", sum);
}
