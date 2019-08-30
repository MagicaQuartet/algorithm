// Baekjoon Online Judge #14496

#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

int main() {
	int a, b, N, M, from, to;
	scanf("%d %d %d %d", &a, &b, &N, &M);

	vector<int> d;
	vector<vector<int>> change;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < N; i++) {
		d.push_back(-1);
		change.push_back(vector<int>());
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &from, &to);
		change[from-1].push_back(to-1);
		change[to-1].push_back(from-1);

		if (from == a)
			pq.push(make_pair(1, to-1));
		else if (to == a)
			pq.push(make_pair(1, from-1));
	}

	d[a-1] = 0;

	while (!pq.empty()) {
		pair<int, int> next = pq.top();
		pq.pop();

		if (d[next.second] != -1)
			continue;

		d[next.second] = next.first;

		for (vector<int>::iterator it=change[next.second].begin(); it!=change[next.second].end(); ++it) {
			if (d[*it] == -1)
				pq.push(make_pair(next.first+1, *it));
		}
	}

	printf("%d\n", d[b-1]);
	return 0;
}

/*
다익스트라로 해결 가능한 문제이다.
 */