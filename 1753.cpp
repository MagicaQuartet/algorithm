// Baekjoon Online Judge #1753
// (Dijkstra)

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;
/*
struct cmp {
	bool operator() (pair<int, int> t, pair<int, int> u) {
		return t.second < u.second;
	}
};
*/

int main() {
	int V, E, start;
	cin >> V >> E >> start;

	int *d = new int[V];
	vector<vector<pair<int, int>>> e;

	for (int i = 0; i < V; i++) {
		d[i] = -1;
		e.push_back(vector<pair<int, int>>());
	}
	d[start - 1] = 0;

	//priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	queue<pair<int, int>> q;

	for (int i = 0; i < E; i++) {
		int src, dest, value;
		cin >> src >> dest >> value;

		e[src-1].push_back(make_pair(dest, value));
	}

	for (vector<pair<int, int>>::iterator it=e[start-1].begin(); it!=e[start-1].end(); ++it) {
		pair<int, int> adj_data = *it;
		pair<int, int> candidate (adj_data);
		
		q.push(candidate);
	}

	while (!q.empty()) {
		pair<int, int> candidate = q.front();
		q.pop();

		int end = candidate.first;
		int dist = candidate.second;

		if (d[end-1] == -1 || d[end-1] > dist) {
			d[end-1] = dist;
			for (vector<pair<int, int>>::iterator it=e[end-1].begin(); it!=e[end-1].end(); ++it) {
				pair<int, int> adj_data = *it;
				pair<int, int> _candidate (adj_data);

				_candidate.second += dist;
				q.push(_candidate);
			}
		}
	}

	for (int i = 0; i < V; i++) {
		if (d[i] == -1)
			cout << "INF" << endl;
		else
			cout << d[i] << endl;
	}

	return 0;
}

/*
다익스트라 알고리즘을 이용하는 간단한 유형의 문제이다.
그런데 일반적으로 다익스트라 알고리즘에서 heap (C++에서는 priority queue로 해결)을 이용하라고 하는데,
이 코드에서는 오히려 queue를 썼을 때 보다 더 오래 걸린다. 내가 잘못 짰나?
 */