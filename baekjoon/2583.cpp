#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int M, N, K, map[101][101], dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int dfs(int x, int y) {
  int ret = 1;
  map[x][y] = 0;
  
  for (int i=0; i<4; i++) {
    if (x+dx[i] >= 0 && x+dx[i] < M && y+dy[i] >= 0 && y+dy[i] < N && map[x+dx[i]][y+dy[i]]) {
      ret += dfs(x+dx[i], y+dy[i]);
    }
  }
  
  return ret;
}

vector<int> solve() {
  vector<int> ret;
  
  for (int i=0; i<M; i++) {
    for (int j=0; j<N; j++) {
      if (map[i][j]) {
        ret.push_back(dfs(i, j));
      }
    }
  }
  
  sort(ret.begin(), ret.end());
  return ret;
}

int main() {
  scanf("%d %d %d", &M, &N, &K);
  
  for (int i=0; i<M; i++) {
    for (int j=0; j<N; j++) {
      map[i][j] = 1;
    }
  }
  
  for (int k=0; k<K; k++) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
    
    for (int x=x1; x<x2; x++) {
      for (int y=y1; y<y2; y++) {
        map[x][y] = 0;
      }
    }
  }
  
  vector<int> ans = solve();
  printf("%d\n", ans.size());
  for (auto i : ans) {
    printf("%d ", i);
  }
}