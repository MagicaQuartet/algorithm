#include<iostream>
#include<string>
#include<queue>
#include<utility>
using namespace std;

#define pii pair<int, int>

int N, M, ans, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
char map[102][102];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> N >> M;
  
  for (int i=1; i<=N; i++) {
    string s;
    cin >> s;
    
    for (int j=1; j<=M; j++) {
      map[i][j] = s[j-1];
    }
  }
  
  queue<pair<pii, int> > q;
  q.push(make_pair(make_pair(1, 1), 1));
  
  while (!q.empty()) {
    pii coord = q.front().first;
    int cnt = q.front().second;
    q.pop();
    
    if (coord.first == N && coord.second == M) {
      ans = cnt;
      break;
    }
    
    if (map[coord.first][coord.second] == '0') {
      continue;
    }
    
    map[coord.first][coord.second] = '0';
    for (int i=0; i<4; i++) {
      if (coord.first+dx[i] <= 0 || coord.first+dx[i] > N || coord.second+dy[i] <= 0 || coord.second+dy[i] > M) {
        continue;
      }
      
      if (map[coord.first+dx[i]][coord.second+dy[i]] == '1') {
        q.push(make_pair(make_pair(coord.first+dx[i], coord.second+dy[i]), cnt+1));
      }
    }
  }
  
  cout << ans << '\n';
}