#include<cstdio>
#include<cstring>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#define pii pair<int, int>
using namespace std;

int N, M;
int field[55][55];
int timestamp[55][55];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pii > candidate;

int solve(const vector<int >& picked) {
  memset(timestamp, -1, sizeof(timestamp));
  queue<pair<pii, int> > q;
  
  for (auto idx: picked) {
    q.push(make_pair(candidate[idx], 0));
  }
  
  int ret = -1;
  while (!q.empty()) {
    int x = q.front().first.first;
    int y = q.front().first.second;
    int t = q.front().second;
    q.pop();

    if (timestamp[x][y] != -1 && timestamp[x][y] <= t) {
      continue;
    }

    timestamp[x][y] = t;
    ret = max(ret, t);

    for (int i=0; i<4; i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];

      if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
        continue;
      }
      
      if (field[nx][ny] == 1) {
        continue;
      }

      q.push(make_pair(make_pair(nx, ny), t+1));
    }
  }
  
  for (int i=0; i<N; i++) {
    if (ret == -1) break;

    for (int j=0; j<N; j++) {
      if (timestamp[i][j] == -1 && field[i][j] != 1) {
        ret = -1;
        break;
      }
    }
  }

  return ret;
}

int pick(vector<int >& picked, int idx) {
  if (picked.size() == M) {
    return solve(picked);
  }

  if (idx >= candidate.size()) {
    return -1;
  }

  int ret1 = pick(picked, idx+1);
  picked.push_back(idx);
  int ret2 = pick(picked, idx+1);
  picked.pop_back();
  return min(ret1, ret2) == -1 ? max(ret1, ret2) : min(ret1, ret2);
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      scanf("%d", &field[i][j]);
      if (field[i][j] == 2) {
        candidate.push_back(make_pair(i, j));
      }
    }
  }

  vector<int> picked;
  printf("%d\n", pick(picked, 0));
}