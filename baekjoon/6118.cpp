// Baekjoon Online Judge #6118
// (Dijkstra)

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<long long> d;
	vector<vector<int>> road;
	queue<pair<long long, int>> q;

	for (int i = 0; i < N; i++) {
		d.push_back(-1);
		road.push_back(vector<int>());
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		road[a-1].push_back(b);
		road[b-1].push_back(a);
	}

	d[0] = 0;
	q.push(make_pair(0, 1));

	while (!q.empty()) {
		pair<long long, int> candidate = q.front();
		long long cost = candidate.first;
		int pos = candidate.second;
		q.pop();

		for (vector<int>::iterator it=road[pos-1].begin(); it!=road[pos-1].end(); ++it) {
			int dest = *it;
			if (d[dest-1] == -1 || d[dest-1] > cost+1) {
				d[dest-1] = cost+1;
				q.push(make_pair(d[dest-1], dest));
			}
		}
	}

	int min_pos = 0;
	long long max_cost = 0;
	int cnt = 0;
	for (int i = 1; i < N; i++) {
		if (d[i] > max_cost) {
			max_cost = d[i];
			min_pos = i;
			cnt = 1;
		}
		else if (d[i] == max_cost)
			cnt++;
	}

	cout << min_pos+1 << " " << max_cost << " " << cnt << endl;
}

/*
단순 다익스트라 문제. 다익스트라 알고리즘을 실행한 뒤 각 헛간의 최단 거리 중 최댓값, 그 값을 가지는 헛간의 수와 그 중 번호가 제일 작은 헛간을 찾는다.
 */