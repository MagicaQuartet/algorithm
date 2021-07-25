#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;
int N;
int board[21][21], visited[21][21];
int x, y;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

struct cmp {
  bool operator()(ppiii lhs, ppiii rhs) {
    if (lhs.second != rhs.second) {
      return lhs.second > rhs.second;
    }
    if (lhs.first.first != rhs.first.first) {
      return lhs.first.first > rhs.first.first;
    }
    return lhs.first.second > rhs.first.second;
  }
};

int main() {
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      scanf("%d", &board[i][j]);
      if (board[i][j] == 9) {
        x = i;
        y = j;
        board[i][j] = 0;
      }
    }
  }

  int ans = 0;
  int sz = 2;
  int cnt = 0;
  while (1) {
    memset(visited, 0, sizeof(visited));
    queue<ppiii > q;
    priority_queue<ppiii, vector<ppiii >, cmp> pq;

    board[x][y] = 0;
    q.push(make_pair(make_pair(x, y), ans));
    while (!q.empty()) {
      pii pos = q.front().first;
      int t = q.front().second;
      q.pop();
      if (visited[pos.first][pos.second]) {
        continue;
      }
      visited[pos.first][pos.second] = 1;
      if (board[pos.first][pos.second] != 0 && board[pos.first][pos.second] < sz) {
        pq.push(make_pair(pos, t));
      }

      for (int i=0; i<4; i++) {
        int nx = pos.first+dx[i];
        int ny = pos.second+dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
          continue;
        }
        if (visited[nx][ny]) {
          continue;
        }
        if (board[nx][ny] > sz) {
          continue;
        }
        q.push(make_pair(make_pair(nx, ny), t+1));
      }
    }

    if (pq.empty()) {
      break;
    }
    x = pq.top().first.first;
    y = pq.top().first.second;
    ans = pq.top().second;
    cnt++;
    if (sz == cnt) {
      sz++;
      cnt = 0;
    }
  }
  printf("%d\n", ans);
}
