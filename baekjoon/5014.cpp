#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
#define pii pair<int, int>
int visited[1000010];
int F, S, G, U, D;
queue<pii > ats;
int bfs() {
  ats.push(make_pair(S, 0));
  while (!ats.empty()) {
    pii at = ats.front();
    ats.pop();
    if (visited[at.first] == 1) {
      continue;
    }
    visited[at.first] = 1;
    if (at.first == G) {
      return at.second;
    }
    if (at.first+U <= F && visited[at.first+U] == 0) {
      ats.push(make_pair(at.first+U, at.second+1));
    }
    if (at.first-D >= 1 && visited[at.first-D] == 0) {
      ats.push(make_pair(at.first-D, at.second+1));
    }
  }
  return -1;
}
int main() {
  scanf("%d%d%d%d%d", &F, &S, &G, &U, &D);
  memset(visited, 0, sizeof(visited));
  int ret = bfs();
  if (ret == -1) {
    printf("use the stairs\n");
  }
  else {
    printf("%d\n", ret);
  }
}
