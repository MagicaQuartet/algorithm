#include<iostream>
#include<string>
using namespace std;

int N, map[101][101], visited[101][101], dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

void dfs(int x, int y, int mask) {
  visited[x][y] = 1;
  
  for (int i=0; i<4; i++) {
    if (x+dx[i] >= 0 && x+dx[i] < N && y+dy[i] >=0 && y+dy[i] < N && !visited[x+dx[i]][y+dy[i]] && map[x+dx[i]][y+dy[i]] & mask) {
      dfs(x+dx[i], y+dy[i], mask);
    }
  }
}

int solve(bool blindness) {
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      visited[i][j] = 0;
    }
  }
  
  int ret = 0;
  int mask;
  
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (!visited[i][j]) {
        mask = (map[i][j] & 0x6) && blindness ? 0x6 : map[i][j];
        dfs(i, j, mask);
        ret++;
      }
    }
  }
  
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> N;
  
  for (int i=0; i<N; i++) {
    string s;
    cin >> s;
    
    for (int j=0; j<N; j++) {
      if (s[j] == 'R') {
        map[i][j] = 0x4;
      }
      else if (s[j] == 'G') {
        map[i][j] = 0x2;
      }
      else {
        map[i][j] = 0x1;
      }
    }
  }
  
  printf("%d %d\n", solve(false), solve(true));
}

/*
  DFS
  RGB값을 비트로 저장하여 조건 분기 및 구역 구분을 편리하게 하였음
*/