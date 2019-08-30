// Baekjoon Online Judge #1197
// (MST, Primm)

#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

int main() {
	int V, E;
	scanf("%d %d", &V, &E);

	vector<vector<pair<int, int>>> graph;
	vector<int> visited;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < V; i++) {
		graph.push_back(vector<pair<int, int>>());
		visited.push_back(0);
	}

	for (int i = 0; i < E; i++) {
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);

		graph[A-1].push_back(make_pair(C, B-1));
		graph[B-1].push_back(make_pair(C, A-1));
	}

	visited[0] = 1;
	for (vector<pair<int, int>>::iterator it=graph[0].begin(); it!=graph[0].end(); ++it)
		pq.push(make_pair(it->first, it->second));

	int sum = 0;

	while (!pq.empty()) {
		pair<int, int> edge = pq.top();
		int value = edge.first;
		int dest = edge.second;
		pq.pop();
		if (visited[dest] == 1)
			continue;

		visited[dest] = 1;
		sum += value;

		for (vector<pair<int, int>>::iterator it=graph[dest].begin(); it!=graph[dest].end(); ++it)
			pq.push(make_pair(it->first, it->second));
	}

	printf("%d\n", sum);
	return 0;
}

/*
MST를 찾는 알고리즘의 구현을 묻는 기본적인 문제이다. 프림 알고리즘으로 구현하였다.
 */