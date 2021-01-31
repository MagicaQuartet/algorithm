#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
#define INF 987654321
#define pii pair<int, int>
#define vpii vector<pii >
int TC, N, M, W, S, E, T;
int dist[510], originalDist[510];
int main() {
  scanf("%d", &TC);
  while(TC--) {
    scanf("%d %d %d", &N, &M, &W);
    vector<vpii > graph(N+1, vpii());
    for (int i=0; i<M; i++) {
      scanf("%d %d %d", &S, &E, &T);
      graph[S].push_back({E, T});
      graph[E].push_back({S, T});
    }
    for (int i=0; i<W; i++) {
      scanf("%d %d %d", &S, &E, &T);
      graph[S].push_back({E, -T});
    }
    for (int i=1; i<=N; i++) {
      originalDist[i] = dist[i] = INF;
    }
    dist[1] = 0;
    for (int i=1; i<N; i++) {
      for (int src=1; src<=N; src++) {
        for (pii p: graph[src]) {
          int dst = p.first;
          int cost = p.second;
          dist[dst] = min(dist[dst], dist[src]+cost);
        }
      }
    }
    copy(dist+1, dist+N+1, originalDist+1);
    for (int src=1; src<=N; src++) {
      for (pii p: graph[src]) {
        int dst = p.first;
        int cost = p.second;
        dist[dst] = min(dist[dst], dist[src]+cost);
      }
    }
    int possible = false;
    for (int i=1; i<=N; i++) {
      if (dist[i] != originalDist[i]) {
        possible = true;
        break;
      }
    }
    printf("%s\n", possible ? "YES": "NO");
  }
}