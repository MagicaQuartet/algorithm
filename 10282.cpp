// Baekjoon Online Judge #10282
// (Dijkstra)

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int test = 0; test < T; test++) {
		int n, d, c;
		cin >> n >> d >> c;

		vector<int> D;
		vector<vector<pair<int, int>>> dependency;
		queue<pair<int, int>> q;

		for (int i = 0; i < n; i++) {
			D.push_back(-1);
			dependency.push_back(vector<pair<int, int>>());
		}

		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;

			dependency[b-1].push_back(make_pair(s, a));
		}

		D[c-1] = 0;
		q.push(make_pair(0, c));

		while (!q.empty()) {
			pair<int, int> candidate = q.front();
			int cost = candidate.first;
			int pos = candidate.second;
			q.pop();

			for (vector<pair<int, int>>::iterator it=dependency[pos-1].begin(); it!=dependency[pos-1].end(); ++it) {
				pair<int, int> _candidate = *it;
				int _cost = _candidate.first;
				int _pos = _candidate.second;

				if (D[_pos-1] == -1 || D[_pos-1] > cost + _cost) {
					D[_pos-1] = cost + _cost;
					q.push(make_pair(D[_pos-1], _pos));
				}
			}
		}

		int infested_cnt = 0;
		int max_cost = 0;
		for (int i = 0; i < n; i++) {
			if (D[i] > -1) {
				infested_cnt++;
				if (max_cost < D[i])
					max_cost = D[i];
			}
		}

		cout << infested_cnt << " " << max_cost << endl;
	}

	return 0;
}

/*
단순 다익스트라 문제. 다익스트라 알고리즘을 실행한 뒤 D의 값이 -1이 아닌 것의 수와 D의 값의 최댓값을 찾으면 된다.
 */