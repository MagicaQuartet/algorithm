#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
#define INF 987654321
#define pii pair<int, int>
#define ppiii pair<pii, int>
using namespace std;

struct cmp {
	bool operator() (ppiii lhs, ppiii rhs) {
		return lhs.second > rhs.second;
	}
};

int V, E, u, v, w;
vector<vector<pii > > graph;
int dist[1010];
int visited[1010][1010];

int main() {
	scanf("%d %d", &V, &E);
	graph = vector<vector<pii > >(V+1, vector<pii >());
	for (int i=1; i<=V; i++) {
		dist[i] = INF;
    for (int j=1; j<=V; j++) {
      visited[i][j] = 0;
    }
	}

	for (int i=0; i<E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back({v, w});
    graph[v].push_back({u, w});
	}

	dist[1] = 0;
	priority_queue<ppiii, vector<ppiii >, cmp> pq;
	for (pii child: graph[1]) {
		pq.push({{1, child.first}, child.second});
	}

	while (!pq.empty()) {
		int src = pq.top().first.first;
    int dst = pq.top().first.second;
		int d = pq.top().second;
		pq.pop();
		if (dist[dst] <= d) {
			continue;
		}
    visited[src][dst] = 1;
		dist[dst] = d;
		for (pii child: graph[dst]) {
			if (dist[child.first] <= d+child.second) {
				continue;
			}

			pq.push({{dst, child.first}, d+child.second});
		}
	}
  vector<pii > ans;
  for (int i=1; i<=V; i++) {
    for (int j=1; j<=V; j++) {
      if (visited[i][j]) {
        ans.push_back({i, j});
      }
    }
  }
  printf("%d\n", ans.size());
  for (pii edge: ans) {
    printf("%d %d\n", edge.first, edge.second);
  }
}