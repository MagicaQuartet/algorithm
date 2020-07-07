#include<cstdio>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

#define pvi pair<vector<int>, int>

int N, M, H;
int map[101][101][101], dx[] = {0, 1, 0, -1, 0, 0}, dy[] = {1, 0, -1, 0, 0, 0}, dz[] = {0, 0, 0, 0, 1, -1};

int main() {
  scanf("%d %d %d", &M, &N, &H);
  
  int young = 0;
  int maxDay = 0;
  queue<pvi > q;
  
  for (int h=0; h<H; h++) {
    for (int i=0; i<N; i++) {
      for (int j=0; j<M; j++) {
        scanf("%d", &map[h][i][j]);
        
        if (map[h][i][j] == 0) {
          young++;
        }
        else if (map[h][i][j] == 1) {
          q.push(make_pair(vector<int>{h, i, j}, 0));
        }
      }
    }
  }
  
  while(!q.empty()) {
    vector<int> coord = q.front().first;
    int z = coord[0], x = coord[1], y = coord[2];
    int cnt = q.front().second;
    q.pop();
    
    maxDay = max(maxDay, cnt);
    
    for (int i=0; i<6; i++) {
      if (z+dz[i] < 0 || z+dz[i] >= H || x+dx[i] < 0 || x+dx[i] >= N || y+dy[i] < 0 || y+dy[i] >= M) {
        continue;
      }
      
      if (map[z+dz[i]][x+dx[i]][y+dy[i]] == 0) {
        young--;
        map[z+dz[i]][x+dx[i]][y+dy[i]] = 1;
        q.push(make_pair(vector<int>{z+dz[i], x+dx[i], y+dy[i]}, cnt+1));
      }
    }
  }
  
  printf("%d\n", young > 0 ? -1 : maxDay);
}

