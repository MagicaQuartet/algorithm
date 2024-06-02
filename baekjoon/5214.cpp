#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;

int N, K, M;
char graph[1010][100010]; // tube -> station
char visited_station[100010];
char visited_tube[1010];

int main() {
  scanf("%d%d%d", &N, &K, &M);
  memset(graph, 0, sizeof(graph));
  memset(visited_station, 0, sizeof(visited_station));
  memset(visited_tube, 0, sizeof(visited_tube));
  for (int i=1; i<=M; i++) {
    for (int j=0; j<K; j++) {
      int num;
      scanf("%d", &num);
      graph[i][num] = 1;
    }
  }

  int ans = -1;
  queue<pair<int, int> > q;
  q.push({1, 1});
  while (!q.empty()) {
    int pos = q.front().first;
    int cnt = q.front().second;
    q.pop();
    if (pos == N) {
      ans = cnt;
      break;
    }

    if (pos > 0) {
      if (visited_station[pos] == 1) {
        continue;
      }
      visited_station[pos] = 1;
      for (int i=1; i<=M; i++) {
        if (graph[i][pos] == 0) {
          continue;
        }
        if (visited_tube[i] == 1) {
          continue;
        }
        q.push({-i, cnt});
      }
    }
    else {
      if (visited_tube[-pos] == 1) {
        continue;
      }
      visited_tube[-pos] = 1;
      for (int i=1; i<=N; i++) {
        if (graph[-pos][i] == 0) {
          continue;
        }
        if (i == N) {
          printf("%d\n", cnt+1);
          return 0;
        }
        if (visited_station[i] == 1) {
          continue;
        }
        q.push({i, cnt+1});
      }
    }
  }
  printf("%d\n", ans);
}
