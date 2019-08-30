// Baekjoon Online Judge #1647

#include <cstdio>
#include <vector>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {
	int N, M, A, B, C, sum, max_edge;
	scanf("%d %d", &N, &M);

	vector<int> visited;
	vector<vector<pair<int, int>>> town;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < N; i++) {
		visited.push_back(0);
		town.push_back(vector<pair<int, int>>());
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &A, &B, &C);
		town[A-1].push_back(make_pair(C, B-1));
		town[B-1].push_back(make_pair(C, A-1));

		if (A == 1)
			pq.push(make_pair(C, B-1));
		else if (B == 1)
			pq.push(make_pair(C, A-1));
	}

	visited[0] = 1;
	sum = 0;
	max_edge = 0;

	while (!pq.empty()) {
		pair<int, int> edge = pq.top();
		pq.pop();

		if (visited[edge.second] == 1)
			continue;

		visited[edge.second] = 1;
		sum += edge.first;
		if (max_edge < edge.first)
			max_edge = edge.first;

		for (vector<pair<int, int>>::iterator it=town[edge.second].begin(); it!=town[edge.second].end(); ++it) {
			if (visited[it->second] == 1)
				continue;

			pq.push(*it);
		}
	}

	printf("%d\n", sum-max_edge);
	return 0;
}

/*
주어진 그래프의 MST를 찾은 다음, 그 중에서 가중치가 가장 큰 edge를 제외하면 된다.
 */