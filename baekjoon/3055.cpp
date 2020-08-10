#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<utility>
#define INF 987654321
#define pii pair<int, int>
using namespace std;

int R, C;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> R >> C;
  vector<vector<int> > forest(R, vector<int>(C, 0));
  queue<pii > water;
  queue<pair<pii, int> > hedge;

  for (int i=0; i<R; i++) {
    string row;
    cin >> row;

    for (int j=0; j<C; j++) {
      if (row[j] == 'D') {
        forest[i][j] = INF;
      }
      else if (row[j] == 'S') {
        forest[i][j] = -INF;
        hedge.push({{i, j}, 0});
      }
      else if (row[j] == '*') {
        forest[i][j] = 0;
        water.push({i, j});
      }
      else if (row[j] == 'X') {
        forest[i][j] = -INF;
      }
      else {
        forest[i][j] = -1;
      }
    }
  }

  while (!water.empty()) {
    int x = water.front().first;
    int y = water.front().second;
    water.pop();

    for (int i=0; i<4; i++) {
      if (x+dx[i] < 0 || x+dx[i] >= R || y+dy[i] < 0 || y+dy[i] >= C) {
        continue;
      }

      if (forest[x+dx[i]][y+dy[i]] == -1) {
        forest[x+dx[i]][y+dy[i]] = forest[x][y] + 1;
        water.push({x+dx[i], y+dy[i]});
      }
    }
  }

  while (!hedge.empty()) {
    int x = hedge.front().first.first;
    int y = hedge.front().first.second;
    int timestamp = hedge.front().second;
    hedge.pop();

    for (int i=0; i<4; i++) {
      if (x+dx[i] < 0 || x+dx[i] >= R || y+dy[i] < 0 || y+dy[i] >= C) {
        continue;
      }

      if (forest[x+dx[i]][y+dy[i]] == INF) {
        cout << timestamp+1 << endl;
        return 0;
      }

      if (forest[x+dx[i]][y+dy[i]] == -1 || forest[x+dx[i]][y+dy[i]] > timestamp+1) {
        forest[x+dx[i]][y+dy[i]] = -INF;
        hedge.push({{x+dx[i], y+dy[i]}, timestamp+1});
      }
    }
  }

  cout << "KAKTUS" << endl;
}

/*
  visited 처리를 안해주면 데이터셋이 작아도 참사가 일어날 수 있음
*/