#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define pipii pair<int, pii >
#define INF 987654321
int N, M, S, D, G[501][501], dist[501], parent[501][501];
struct cmp {
	bool operator() (pipii lhs, pipii rhs) {
		return lhs.first > rhs.first;
	}
};
void removeShortestPath(int v) {
	for (int i=0; i<N; i++) {
		if (parent[v][i]) {
			G[i][v] = INF;
			parent[v][i] = 0;
			removeShortestPath(i);
		}
	}
}
int main() {
	while(1) {
		scanf("%d %d", &N, &M);
		if (N==0) break;
		scanf("%d %d", &S, &D);
		for (int i=0; i<N; i++) {
			dist[i] = INF;
			memset(parent[i], 0, sizeof(parent[i]));
			for (int j=0; j<N; j++) {
				G[i][j] = i==j ? 0 : INF;
			}
		}
		dist[S] = 0;
		while(M--) {
			int u, v, p;
			scanf("%d %d %d", &u, &v, &p);
			G[u][v] = p;
		}

		priority_queue<pipii, vector<pipii >, cmp> pq;
		for (int i=0; i<N; i++) {
			if (i != S && G[S][i] != INF) {
				pq.push({G[S][i], {S, i}});
			}
		}
		while(!pq.empty()) {
			int d = pq.top().first;
			int src = pq.top().second.first;
			int dst = pq.top().second.second;
			pq.pop();
			if (dist[dst]<=d) {
				if (dist[dst] == d) {
					parent[dst][src] = 1;
				}
				continue;
			}

			dist[dst] = d;
			memset(parent[dst], 0, sizeof(parent[dst]));
			parent[dst][src] = 1;

			for (int i=0; i<N; i++) {
				if (G[dst][i] != INF) {
					if (dist[i] < d+G[dst][i]) continue;
					if (dist[i] == d+G[dst][i]) {
						parent[i][dst] = 1;
						continue;
					}
					pq.push({d+G[dst][i], {dst, i}});
				}
			}
		}
		removeShortestPath(D);

		for (int i=0; i<N; i++) {
			dist[i] = INF;
		}
		dist[S] = 0;
		for (int i=0; i<N; i++) {
			if (i != S && G[S][i] != INF) {
				pq.push({G[S][i], {S, i}});
			}
		}
		while(!pq.empty()) {
			int d = pq.top().first;
			int src = pq.top().second.first;
			int dst = pq.top().second.second;
			pq.pop();
			if (dist[dst]<=d) continue;
			dist[dst] = d;

			for (int i=0; i<N; i++) {
				if (G[dst][i] != INF && dist[i] > d+G[dst][i]) {
					pq.push({d+G[dst][i], {dst, i}});
				}
			}
		}
		printf("%d\n", dist[D] == INF ? -1 : dist[D]);
	}
}
