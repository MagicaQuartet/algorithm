#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m;
int wall[51][51], room[51][51];
int idx, maxRoomSize, unifiedRoomSize, roomSize[2510];
int direction[4] = {1, 2, 4, 8};
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int dfs(int x, int y, int idx) {
  room[x][y] = idx;

  int ret = 1;
  for (int i=0; i<4; i++) {
    if (wall[x][y] & direction[i]) { 
      continue;
    }
    
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
      continue;
    }

    if (room[nx][ny] != -1) {
      continue;
    }

    ret += dfs(nx, ny, idx);
  }
  return ret;
}

int main() {
  scanf("%d %d", &m, &n);
  memset(room, -1, sizeof(room));

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      scanf("%d", &wall[i][j]);
    }
  }

  idx = 0;
  maxRoomSize = 0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (room[i][j] == -1) {
        roomSize[idx] = dfs(i, j, idx);
        maxRoomSize = max(maxRoomSize, roomSize[idx]);
        idx++;
      }
    }
  }

  unifiedRoomSize = 0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      for (int k=2; k<4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];

        if (nx >= n || ny >= m) {
          continue;
        }

        if (room[i][j] != room[nx][ny]) {
          unifiedRoomSize = max(unifiedRoomSize, roomSize[room[i][j]] + roomSize[room[nx][ny]]);
        }
      }
    }
  }

  printf("%d\n", idx);
  printf("%d\n", maxRoomSize);
  printf("%d\n", unifiedRoomSize);
}