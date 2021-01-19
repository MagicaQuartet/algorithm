#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
#define INF 987654321
#define pii pair<int, int>
#define pipii pair<int, pii >
int n, board[51][51], dist[51][51];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
struct cmp {
  bool operator() (pipii lhs, pipii rhs) {
    return lhs.first > rhs.first;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i=0; i<n; i++) {
    string row;
    cin >> row;
    for (int j=0; j<n; j++) {
      board[i][j] = '1'-row[j];
    }
  }
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      dist[i][j] = INF;
    }
  }
  dist[0][0] = 0;
  priority_queue<pipii, vector<pipii >, cmp> pq;
  pq.push(make_pair(board[0][1], make_pair(0, 1)));
  pq.push(make_pair(board[1][0], make_pair(1, 0)));
  while(!pq.empty()) {
    int d = pq.top().first;
    pii dst = pq.top().second;
    pq.pop();
    if (dist[dst.first][dst.second]<=d) continue;
    dist[dst.first][dst.second] = d;
    for (int i=0; i<4; i++) {
      int nx = dst.first+dx[i];
      int ny = dst.second+dy[i];
      if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
      pq.push(make_pair(d+board[nx][ny], make_pair(nx, ny)));
    }
  }
  cout << dist[n-1][n-1] << "\n";
}