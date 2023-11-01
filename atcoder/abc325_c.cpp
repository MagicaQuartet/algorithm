#include<iostream>
#include<string>
using namespace std;
int H, W;
int dx[8] = {0, 1, 0, -1, 1, -1, -1, 1};
int dy[8] = {1, 0, -1, 0, -1, -1, 1, 1};
char board[1010][1010];
void dfs(int x, int y) {
  board[x][y] = '.';
  for (int i=0; i<8; i++) {
    int nx = x+dx[i];
    int ny = y+dy[i];
    if (nx < 0 || ny < 0 || nx >= H || ny >= W) {
      continue;
    }
    if (board[nx][ny] == '.') {
      continue;
    }
    dfs(nx, ny);
  }
}
int main() {
  cin >> H >> W;
  for (int i=0; i<H; i++) {
    string row;
    cin >> row;
    for (int j=0; j<W; j++) {
      board[i][j] = row[j];
    }
  }
  int ans = 0;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      if (board[i][j] == '#') {
        ans++;
        dfs(i, j);
      }
    }
  }
  cout << ans << '\n';
}
