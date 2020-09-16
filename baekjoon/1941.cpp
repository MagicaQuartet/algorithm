#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

int classroom[5][5];
int check[5][5];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int> > trace;

void dfs(int x, int y) {
  check[x][y] = 0;

  for (int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) {
      continue;
    }

    if (!check[nx][ny]) {
      continue;
    }

    dfs(nx, ny);
  }
}

int solve(int x, int y) {
  if (trace.size() == 7) {
    memset(check, 0, sizeof(check));
    int cnt = 0;
    for (auto p: trace) {
      check[p.first][p.second] = 1;
      cnt += classroom[p.first][p.second];
    }

    if (cnt < 4) {
      return 0;
    }

    dfs(trace[0].first, trace[0].second);

    for (auto p: trace) {
      if (check[p.first][p.second] == 1) {
        return 0;
      }
    }
    return 1;
  }

  if (x == 5) {
    return 0;
  }

  int ret = 0;

  if (y < 4) {
    ret += solve(x, y+1);
    trace.push_back({x, y});
    ret += solve(x, y+1);
    trace.pop_back();
  }
  else {
    ret += solve(x+1, 0);
    trace.push_back({x, y});
    ret += solve(x+1, 0);
    trace.pop_back();
  }
  
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i=0; i<5; i++) {
    string s;
    cin >> s;

    for (int j=0; j<5; j++) {
      classroom[i][j] = (s[j] == 'S' ? 1 : 0);
    }
  }

  printf("%d\n", solve(0, 0));
}