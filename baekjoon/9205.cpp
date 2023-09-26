#include<cstdio>
#include<cstring>
#include<vector>
#include<utility>
using namespace std;
#define pii pair<int, int>
int t, n, x, y;
vector<pii> points;
int graph[110][110];
int visited[110];
int dist(pii src, pii dst) {
  int distx = src.first-dst.first;
  if (distx < 0) {
    distx = -distx;
  }
  int disty = src.second-dst.second;
  if (disty < 0) {
    disty = -disty;
  }
  return distx+disty;
}
bool dfs(int idx) {
  if (idx == points.size()-1) {
    return true;
  }
  visited[idx] = 1;
  for (int i=0; i<n+2; i++) {
    if (graph[idx][i] == 0) {
      continue;
    }
    if (visited[i] == 1) {
      continue;
    }
    if (dfs(i)) {
      return true;
    }
  }
  return false;
}
int main() {
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    points.clear();
    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));
    for (int i=0; i<n+2; i++) {
      scanf("%d%d", &x, &y);
      points.push_back(make_pair(x, y));
    }
    for (int i=0; i < points.size()-1; i++) {
      for (int j=i+1; j < points.size(); j++) {
        if (dist(points[i], points[j]) <= 1000) {
          graph[i][j] = 1;
          graph[j][i] = 1;
        }
      }
    }
    if (dfs(0)) {
      printf("happy\n");
    } else {
      printf("sad\n");
    }
  }
}
