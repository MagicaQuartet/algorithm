#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;
#define pii pair<int, int>
int glacier[310][310];
int visited[310][310];
int N, M, ans;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool bfs() {
  memset(visited, 0, sizeof(visited));
  queue<pii> q;
  bool found = false;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      if (glacier[i][j] <= 0) {
        visited[i][j] = 1;
      }
      
      if (visited[i][j] == 1) {
        continue;
      }
      if (found) {
        return true;
      }
      found = true;
      q.push(make_pair(i, j));
      while (!q.empty()) {
        pii at = q.front();
        q.pop();
        if (visited[at.first][at.second] == 1) {
          continue;
        }
        visited[at.first][at.second] = 1;
        for (int di=0; di<4; di++) {
          if (at.first+dx[di] < 0 || at.first+dx[di] >= N || at.second+dy[di] < 0 || at.second+dy[di] >= M) {
            continue;
          }
          if (glacier[at.first+dx[di]][at.second+dy[di]] <= 0) {
            continue;
          }
          if (visited[at.first+dx[di]][at.second+dy[di]] == 1) {
            continue;
          }
          q.push(make_pair(at.first+dx[di], at.second+dy[di]));
        }
      }
    }
  }
  return false;
}
bool melt() {
  queue<pii> q;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      if (glacier[i][j] > 0) {
        continue;
      }
      for (int di=0; di<4; di++) {
        if (i+dx[di] < 0 || i+dx[di] >= N || j+dy[di] < 0 || j+dy[di] >= M) {
          continue;
        }
        if (glacier[i+dx[di]][j+dy[di]] > 0) {
          q.push(make_pair(i+dx[di], j+dy[di]));
        }
      }
    }
  }
  if (q.empty()) {
    return false;
  }
  while(!q.empty()) {
    pii at = q.front();
    q.pop();
    glacier[at.first][at.second] -= 1;
  }
  return true;
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      scanf("%d", &glacier[i][j]);
    }
  }
  ans = 0;
  while (1) {
    bool split = bfs();
    if (split) {
      printf("%d\n", ans);
      break;
    }
    bool melted = melt();
    if (!melted) {
      printf("0\n");
      break;
    }
    ans++;
  }
}
