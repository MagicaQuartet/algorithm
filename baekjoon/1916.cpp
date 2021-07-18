// Baekjoon Online Judge #1916
// (Dijkstra)

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;


struct cmp {
	bool operator()(pii lhs, pii rhs) {
		return lhs.second > rhs.second;
	}
};

int main() {
	int n, m, start, end;
	cin >> n >> m;

	int *d = new int[n];
	vector<vector<pii > > e;
	priority_queue<pii, vector<pii >, cmp> pq;

	for (int i = 0; i < n; i++) {
		d[i] = -1;
		e.push_back(vector<pii >());
	}

	for (int i = 0; i < m; i++) {
		int src, dest, value;
		cin >> src >> dest >> value;

		e[src-1].push_back(make_pair(dest-1, value));
	}

	cin >> start >> end;
	d[start-1] = 0;

	for (vector<pii >::iterator it=e[start-1].begin(); it!=e[start-1].end(); ++it) {
		int dest = (*it).first;
		int value = (*it).second;
		pq.push(make_pair(dest, value));	
	}

	while (!pq.empty()) {
		int dest = pq.top().first;
		int value = pq.top().second;
		pq.pop();

		if (d[dest] != -1 && d[dest] <= value) {
			continue;
		}
		d[dest] = value;

		int buf[1010];
		memset(buf, -1, sizeof(buf));

		for (vector<pii >::iterator it=e[dest].begin(); it!=e[dest].end(); ++it) {
			int edge_dest = (*it).first;
			int edge_value = (*it).second;

			if (buf[edge_dest] != -1 && buf[edge_dest] <= value + edge_value) {
				continue;
			}	
			buf[edge_dest] = value + edge_value;
		}

		for (int i=0; i<n; i++) {
			if (buf[i] == -1 || d[i] != -1 && d[i] <= buf[i]) {
				continue;
			}
			pq.push(make_pair(i, buf[i]));
		}
	}

	cout << d[end-1] << endl;
	return 0;
}

/*
다익스트라 알고리즘을 이용하는 간단한 유형의 문제
수정) 메모리 초과를 유발할 수 있는 데이터가 추가되어 두 노드 간에 여러 간선이 존재할 경우 가장 짧은 것만 반영하도록 하는 코드 추가
 */
