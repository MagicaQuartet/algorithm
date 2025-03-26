#include<cstdio>
#include<cstring>
#include<map>
#include<utility>
#define pii pair<int, int>
using namespace std;
int R, C, M;
int board[101][101], tmp_board[101][101];
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};
map<int, pair<pii, int>> sharks;
int main() {
  scanf("%d %d %d", &R, &C, &M);
  memset(board, 0, sizeof(board));
  for (int i=1; i<=M; i++) {
    int r, c, s, d, z;
    scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
    board[r][c] = i;
    sharks[i] = make_pair(make_pair(s, d), z);
  }
  int idx = 1;
  int ans = 0;
  while(idx <= C) {
    // 낚시
    for (int r=1; r<=R; r++) {
      if (board[r][idx]) {
        ans += sharks[board[r][idx]].second;
        sharks.erase(board[r][idx]);
        board[r][idx] = 0;
        break;
      }
    }
    // 이동
    memset(tmp_board, 0, sizeof(tmp_board));
    for (int r=1; r<=R; r++) {
      for (int c=1; c<=C; c++) {
        if (board[r][c] == 0) {
          continue;
        }
        int shark = board[r][c];
        pair<pii, int> info = sharks[shark];
        int s = info.first.first;
        int d = info.first.second;
        int z = info.second;
        int nr = r + dx[d]*s;
        int nc = c + dy[d]*s;
        // 범위를 벗어나는 경우 데응
        int _d = d;
        while (nr <= 0 || nr > R) {
          if (nr <= 0) {
            nr = 1 + (1-nr);
          }
          else {
            nr = R - (nr-R);
          }
          _d = 1+_d%2;
        }
        while (nc <= 0 || nc > C) {
          if (nc <= 0) {
            nc = 1 + (1-nc);
          }
          else {
            nc = C - (nc-C);
          }
          _d = 3+_d%2;
        }
        info.first.second = _d;
        sharks[shark] = info;
        // 이동할 자리에 이미 상어가 있다면
        if (tmp_board[nr][nc]) {
          int dup_z = sharks[tmp_board[nr][nc]].second;
          if (z > dup_z) {
            tmp_board[nr][nc] = shark;
          }
        }
        else {
          tmp_board[nr][nc] = shark;
        }
      }
    }
    for (int r=1; r<=R; r++) {
      for (int c=1; c<=C; c++) {
        board[r][c] = tmp_board[r][c];
      }
    }
    idx++;
  }
  printf("%d\n", ans);
}
