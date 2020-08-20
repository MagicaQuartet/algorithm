#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
#define INF 987654321
#define pii pair<int, int>
using namespace std;

struct cmp {
	bool operator() (pii lhs, pii rhs) {
		return lhs.second > rhs.second;
	}
};

int V, E, K, u, v, w;
vector<vector<pii > > graph;
int dist[20010];

int main() {
	scanf("%d %d %d", &V, &E, &K);
	graph = vector<vector<pii > >(V+1, vector<pii >());
	for (int i=1; i<=V; i++) {
		dist[i] = INF;
	}

	for (int i=0; i<E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back({v, w});
	}

	dist[K] = 0;
	priority_queue<pii, vector<pii >, cmp> pq;
	for (auto child: graph[K]) {
		pq.push(child);
	}

	while (!pq.empty()) {
		int node = pq.top().first;
		int d = pq.top().second;
		pq.pop();
		if (dist[node] <= d) {
			continue;
		}

		dist[node] = d;
		for (auto child: graph[node]) {
			if (dist[child.first] <= d+child.second) {
				continue;
			}

			pq.push({child.first, d+child.second});
		}
	}

	for (int i=1; i<=V; i++) {
		if (dist[i] != INF) {
			printf("%d\n", dist[i]);
		}
		else {
			printf("INF\n");
		}
	}
}