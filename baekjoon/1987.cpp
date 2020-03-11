#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int R, C, visited[26], dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
char data[20][20];
int solve(int x, int y) {
  visited[data[x][y]-'A'] = 1;
  
  int ret = 1;
  for (int i=0; i<4; i++) {
    if (x+dx[i] < R && x+dx[i] >= 0 && y+dy[i] < C && y+dy[i] >= 0 && visited[data[x+dx[i]][y+dy[i]]-'A'] == 0) {
      ret = max(ret, solve(x+dx[i], y+dy[i])+1);
    }
  }
  
  visited[data[x][y]-'A'] = 0;
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> R >> C;
  for (int i=0; i<R; i++) {
    string s;
    cin >> s;
    for (int j=0; j<C; j++) {
      data[i][j] = s[j];
    }
  }
  
  memset(visited, 0, sizeof(visited));
  
  printf("%d\n", solve(0, 0));
}