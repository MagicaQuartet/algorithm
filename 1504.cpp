// Baekjoon Online Judge #1504
// (Dijkstra)

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	int N, E, V1, V2;
	cin >> N >> E;

	long long *d_1 = new long long[N];
	long long *d_V1 = new long long[N];
	long long *d_V2 = new long long[N];
	vector<vector<pair<int, long long>>> e;

	for (int i = 0; i < N; i++) {
		d_1[i] = -1;
		e.push_back(vector<pair<int, long long>>());
	}
	d_1[0] = 0;

	for (int i = 0; i < E; i++) {
		int src, dest;
		long long value;
		cin >> src >> dest >> value;

		e[src-1].push_back(make_pair(dest, value));
		e[dest-1].push_back(make_pair(src, value));
	}

	cin >> V1 >> V2;

	for (int i = 0; i < N; i++) {
		d_V1[i] = -1;
		d_V2[i] = -1;
	}
	d_V1[V1-1] = 0;
	d_V2[V2-1] = 0;

	queue<pair<int, long long>> q_1;
	queue<pair<int, long long>> q_V1;
	queue<pair<int, long long>> q_V2;
	for (vector<pair<int, long long>>::iterator it=e[0].begin(); it!=e[0].end(); ++it)
		q_1.push(make_pair((*it).first, (*it).second));
	for (vector<pair<int, long long>>::iterator it=e[V1-1].begin(); it!=e[V1-1].end(); ++it)
		q_V1.push(make_pair((*it).first, (*it).second));
	for (vector<pair<int, long long>>::iterator it=e[V2-1].begin(); it!=e[V2-1].end(); ++it)
		q_V2.push(make_pair((*it).first, (*it).second));

	while (!q_1.empty()) {
		pair<int, long long> candidate = q_1.front();
		int dest = candidate.first;
		long long value = candidate.second;
		q_1.pop();

		if (d_1[dest-1] == -1 || d_1[dest-1] > value) {
			d_1[dest-1] = value;
			for (vector<pair<int, long long>>::iterator it=e[dest-1].begin(); it!=e[dest-1].end(); ++it)
				q_1.push(make_pair((*it).first, (*it).second + value));			
		}
	}

	while (!q_V1.empty()) {
		pair<int, long long> candidate = q_V1.front();
		int dest = candidate.first;
		long long value = candidate.second;
		q_V1.pop();

		if (d_V1[dest-1] == -1 || d_V1[dest-1] > value) {
			d_V1[dest-1] = value;
			for (vector<pair<int, long long>>::iterator it=e[dest-1].begin(); it!=e[dest-1].end(); ++it)
				q_V1.push(make_pair((*it).first, (*it).second + value));			
		}
	}

	while (!q_V2.empty()) {
		pair<int, long long> candidate = q_V2.front();
		int dest = candidate.first;
		long long value = candidate.second;
		q_V2.pop();

		if (d_V2[dest-1] == -1 || d_V2[dest-1] > value) {
			d_V2[dest-1] = value;
			for (vector<pair<int, long long>>::iterator it=e[dest-1].begin(); it!=e[dest-1].end(); ++it)
				q_V2.push(make_pair((*it).first, (*it).second + value));			
		}
	}

	long long path1V1, path1V2, pathV1V2, pathV2V1, pathV1N, pathV2N;
	bool V1V2, V2V1;
	path1V1 = d_1[V1-1];
	path1V2 = d_1[V2-1];
	pathV1V2 = d_V1[V2-1];
	pathV2V1 = d_V2[V1-1];
	pathV1N = d_V1[N-1];
	pathV2N = d_V2[N-1];

	V1V2 = path1V1 != -1 && pathV1V2 != -1 && pathV2N != -1;
	V2V1 = path1V2 != -1 && pathV2V1 != -1 && pathV1N != -1;

	if (!V1V2 && !V2V1)
		cout << -1 << endl;
	else if (!V1V2)
		cout << path1V2 + pathV2V1 + pathV1N << endl;
	else if (!V2V1)
		cout << path1V1 + pathV1V2 + pathV2N << endl;
	else
		cout << min(path1V2 + pathV2V1 + pathV1N, path1V1 + pathV1V2 + pathV2N) << endl;

	return 0;
}

/* 
(edge가 양방향으로 주어진다는 것을 거의 다 구현하고 나서야 깨달아서 불필요한 부분이 있는 코드이다.)

1에서 N으로 가되 V1과 V2을 지나야 하는 경로는 (1->V1 or V2) | (V1 or V2 -> V2 or V1) | (V1 or V2 -> N) 으로 이루어져있다.
이 때, edge가 양방향으로 주어지기 때문에 가운데 부분은 두 경우 모두 최단 거리가 같다.
1, V1, V2를 기준으로 하여 다익스트라 알고리즘을 적용한 뒤, 1->V1->V2->N과 1->V2->V1->N중 작은 값을 고르면 된다.
*/