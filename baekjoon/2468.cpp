#include<cstdio>
#include<algorithm>
using namespace std;

int N, maxVal, map[101][101], visited[101][101], dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

void dfs(int x, int y, int threshold) {
  visited[x][y] = 1;
  
  for (int i=0; i<4; i++) {
    if (x+dx[i] >= 0 && x+dx[i] < N && y+dy[i] >= 0 && y+dy[i] < N && !visited[x+dx[i]][y+dy[i]] && map[x+dx[i]][y+dy[i]] >= threshold) {
      dfs(x+dx[i], y+dy[i], threshold);
    }
  }
}

int solve() {
  int ans = 0, cnt;
  
  for (int t=1; t<=maxVal; t++) {
    cnt = 0;
    
    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
        visited[i][j] = 0;
      }
    }
    
    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
        if (!visited[i][j] && map[i][j] >= t) {
          dfs(i, j, t);
          cnt++;
        }
      }
    }
    
    ans = max(ans, cnt);
  }
  
  return ans;
}

int main() {
  scanf("%d", &N);
  maxVal = 0;
  
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      scanf("%d", &map[i][j]);
      maxVal = max(maxVal, map[i][j]);
    }
  }
  
  printf("%d\n", solve());
}

/*
  DFS
*/