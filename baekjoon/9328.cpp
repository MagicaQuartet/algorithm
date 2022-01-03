#include<cstdio>
#include<cstring>
int T, h, w, visited[101][101], key[26], ans;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char map[101][101], k[27];
enum Status{NONE, RESET};
Status dfs(int x, int y) {
  if (map[x][y] == '*' || visited[x][y]) {
    return NONE;
  }
  if (map[x][y] >= 'A' && map[x][y] <= 'Z' && !key[map[x][y]-'A']) {
    return NONE;
  }
  if (map[x][y] >= 'a' && map[x][y] <= 'z' && !key[map[x][y]-'a']) {
    key[map[x][y]-'a'] = 1;
    return RESET;
  }

  visited[x][y] = 1;
  if (map[x][y] == '$') {
    ans++;
  }
  for (int i=0; i<4; i++) {
    int nx = x+dx[i];
    int ny = y+dy[i];
    if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
      continue;
    }
    Status ret = dfs(nx, ny);
    if (ret != NONE) {
      return ret;
    }
  }
  return NONE;
}
Status solve() {
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if (i != 0 && i != h-1 && j != 0 && j != w-1) {
        continue;
      }
      Status ret = dfs(i, j);
      if (ret != NONE) {
        return ret;
      }
    }
  }
  return NONE;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &h, &w);
    for (int i=0; i<h; i++) {
      scanf("%s", map[i]);
    }
    memset(key, 0, sizeof(key));
    scanf("%s", k);
    for (int i=0; k[i] != '\0' && k[i] != '0'; i++) {
      key[k[i]-'a'] = 1;
    }
    while(1) {
      memset(visited, 0, sizeof(visited));
      ans = 0;
      if (solve() == NONE) {
        break;
      }
    }
    printf("%d\n", ans);
  }
}
