#include<iostream>
#include<string>
#include<algorithm>
#define INF 987654321
using namespace std;

int N, M;
char board[55][55];
int dp[55][55];
int dx[4] = {-1, 0, 1, 0};
int dy[4] {0, 1, 0, -1};

int dfs(int x, int y) {
  if (board[x][y] == 'H') {
    return 0;
  }
  if (dp[x][y] != -INF) {
    return dp[x][y];
  }

  int ret = 1;
  int step = board[x][y] - '0';
  dp[x][y] = -1;

  for (int i=0; i<4; i++) {
    int nx = x+dx[i]*step;
    int ny = y+dy[i]*step;
    int nret;

    if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
      continue;
    }

    nret = dfs(nx, ny);
    if (nret == -1) {
      return -1;
    }

    ret = max(ret, nret+1);
  }

  dp[x][y] = ret;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;

  for (int i=0; i<N; i++) {
    string row;
    cin >> row;

    for (int j=0; j<M; j++) {
      board[i][j] = row[j];
      dp[i][j] = -INF;
    }
  }

  cout << dfs(0, 0) << endl;
}

/*
  DFS를 재귀호출한 지점이 그 재귀호출 도중 다시 나오면 동전을 무한으로 움직일 수 있다.
  그런 경우를 별도로 체크하는 방법이 필요하다.
*/