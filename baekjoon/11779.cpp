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

int V, E, u, v, w, a, b;
vector<vector<pii > > graph;
int dist[1010], parent[1010];

int main() {
	scanf("%d %d", &V, &E);
	graph = vector<vector<pii > >(V+1, vector<pii >());
	for (int i=1; i<=V; i++) {
		dist[i] = INF;
    parent[i] = -1;
	}

	for (int i=0; i<E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back({v, w});
	}
  scanf("%d %d", &a, &b);

	dist[a] = 0;
	priority_queue<ppiii, vector<ppiii >, cmp> pq;
	for (pii child: graph[a]) {
		pq.push({{a, child.first}, child.second});
	}

	while (!pq.empty()) {
		int src = pq.top().first.first;
    int dst = pq.top().first.second;
		int d = pq.top().second;
		pq.pop();
		if (dist[dst] <= d) {
			continue;
		}
    parent[dst] = src;
		dist[dst] = d;
		for (pii child: graph[dst]) {
			if (dist[child.first] <= d+child.second) {
				continue;
			}

			pq.push({{dst, child.first}, d+child.second});
		}
	}

	printf("%d\n", dist[b]);
  vector<int> path;
  int node = b;
  while (b != -1) {
    path.push_back(b);
    b = parent[b];
  }
  printf("%d\n", path.size());
  for (int i=path.size()-1; i>=0; i--) {
    printf("%d ", path[i]);
  }
  printf("\n");
}