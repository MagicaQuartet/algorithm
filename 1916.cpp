// Baekjoon Online Judge #1916
// (Dijkstra)

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int main() {
	int n, m, start, end;
	cin >> n >> m;

	int *d = new int[n];
	vector<vector<pair<int, int>>> e;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		d[i] = -1;
		e.push_back(vector<pair<int, int>>());
	}

	for (int i = 0; i < m; i++) {
		int src, dest, value;
		cin >> src >> dest >> value;

		e[src-1].push_back(make_pair(dest, value));
	}

	cin >> start >> end;
	d[start-1] = 0;

	for (vector<pair<int, int>>::iterator it=e[start-1].begin(); it!=e[start-1].end(); ++it) {
		int dest = (*it).first;
		int value = (*it).second;

		q.push(make_pair(dest, value));	
	}

	while (!q.empty()) {
		int dest = q.front().first;
		int value = q.front().second;
		q.pop();

		if (d[dest-1] == -1 || d[dest-1] > value) {
			d[dest-1] = value;
			for (vector<pair<int, int>>::iterator it=e[dest-1].begin(); it!=e[dest-1].end(); ++it) {
				int edge_dest = (*it).first;
				int edge_value = (*it).second;

				q.push(make_pair(edge_dest, value + edge_value));	
			}
		}
	}

	cout << d[end-1] << endl;
	return 0;
}

/*
다익스트라 알고리즘을 이용하는 간단한 유형의 문제
 */