#include<cstdio>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

#define INF 987654321
#define pii pair<int, int>

int N, M;
int map[1001][1001], days[1001][1001], dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int main() {
  int young = 0;
  int maxDay = 0;
  queue<pair<pii, int>> q;
  scanf("%d %d", &M, &N);
  
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      scanf("%d", &map[i][j]);
      days[i][j] = INF;
      
      if (map[i][j] == 1) {
        q.push(make_pair(make_pair(i, j), 0));
      }
      else if (map[i][j] == 0) {
        young++;
      }
    }
  }
  
  while (!q.empty()) {
    pii coord = q.front().first;
    int cnt = q.front().second;
    q.pop();
    
    maxDay = max(maxDay, cnt);
    
    for (int i=0; i<4; i++) {
      if (coord.first+dx[i] < 0 || coord.first+dx[i] >= N || coord.second+dy[i] < 0 || coord.second+dy[i] >= M) {
        continue;
      }
      
      if (map[coord.first+dx[i]][coord.second+dy[i]] == 0) {
        young--;
        map[coord.first+dx[i]][coord.second+dy[i]] = 1;
        q.push(make_pair(make_pair(coord.first+dx[i], coord.second+dy[i]), cnt+1));
      }
    }
  }
  
  printf("%d\n", young > 0 ? -1 : maxDay);
}

/*
  BFS는 level 0인 지점을 여려 곳에 두고 시작할 수 있다!
*/