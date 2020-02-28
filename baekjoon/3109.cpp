#include<iostream>
#include<string>
#include<stack>
#include<utility>
using namespace std;
int R, C, cnt;
char data[10000][500], visited[10000][500];
stack<pair<int, int> > log;
int solve(int r, int c) {
  if (c == C) {
    while(!log.empty()) {
      log.pop();
    }
    return 1;
  }
  
  int ret = 0;
  if (r > 0 && data[r-1][c] == '.' && visited[r-1][c] == 0) {
    data[r-1][c] = 'x';
    visited[r-1][c] = 1;
    log.push(make_pair(r-1, c));
    ret = solve(r-1, c+1);
  }
  if (ret == 0 && data[r][c] == '.' && visited[r][c] == 0) {
    data[r][c] = 'x';
    visited[r][c] = 1;
    log.push(make_pair(r, c));
    ret = solve(r, c+1);
  }
  if (ret == 0 && r < R-1 && data[r+1][c] == '.' && visited[r+1][c] == 0) {
    data[r+1][c] = 'x';
    visited[r+1][c] = 1;
    log.push(make_pair(r+1, c));
    ret = solve(r+1, c+1);
  }
  
  if (ret == 0 && !log.empty()) {
    data[log.top().first][log.top().second] = '.';
    log.pop();
  }
  
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> R >> C;
  for (int i=0; i<R; i++) {
    string s;
    cin >> s;
    
    for (int j=0; j<C; j++) {
      data[i][j] = s[j];
      visited[i][j] = 0;
    }
  }
  
  cnt = 0;
  for (int i=0; i<R; i++) {
    cnt += solve(i, 1);
  }
  cout << cnt;
}

/*
  가장 위 지점에서부터 시작해서 C-1 열까지 도달할 수 있는지 확인한다.
  
  이 때 다음 열로 진행하는 경우의 수가 여러 개 있을 때는 가장 위쪽으로 향하는 경로를 택한다.
  아래쪽으로 향하는 해가 최적해일 경우 그보다 위쪽으로 향하는 경로를 택했을 때도 항상 최적해가 되기 때문.
  
  그리고 각 지점에서 가능한 경로가 있든 없든, 한번 체크한 지점은 어떤 경우에도 다시 체크할 필요가 없다.
  가능한 경로가 있었으면 이미 파이프가 놓인 지점일 것이고, 없었으면 어디서 출발했든 그곳을 지나면 안되기 때문에다.
  이를 이용하면 중복을 제거하여 O(RC)에 해결 가능하다.
*/