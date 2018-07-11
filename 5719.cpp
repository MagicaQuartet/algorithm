// Baekjoon Online Judge #5719
// (Dijkstra)

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main() {
	while (true) {
		int N, M, start, end;
		cin >> N >> M;

		if (N == 0)
			break;

		vector<int> d;
		vector<vector<pair<int, int>>> road;
		vector<vector<int>> fastest_route;
		queue<pair<int, int>> q;

		for (int i = 0; i < N; i++) {
			d.push_back(-1);
			road.push_back(vector<pair<int, int>>());
			fastest_route.push_back(vector<int>());
		}

		cin >> start >> end;
		d[start] = 0;

		for (int i = 0; i < M; i++) {
			int src, dest, value;
			cin >> src >> dest >> value;

			road[src].push_back(make_pair(value, dest));
		}

		q.push(make_pair(0, start));

		while (!q.empty()) {
			pair<int, int> candidate = q.front();
			int cost = candidate.first;
			int pos = candidate.second;
			q.pop();

			for (vector<pair<int, int>>::iterator it=road[pos].begin(); it!=road[pos].end(); ++it) {
				pair<int, int> _candidate = *it;
				int _value = _candidate.first;
				int _pos = _candidate.second;

				if (d[_pos] == -1 || d[_pos] > cost + _value) {
					d[_pos] = cost + _value;
					fastest_route[_pos].clear();
					fastest_route[_pos].push_back(pos);

					q.push(make_pair(d[_pos], _pos));
				}
				else if (d[_pos] == cost + _value)
					fastest_route[_pos].push_back(pos);
			}
		}

		queue<int> q_fastest_route;
		q_fastest_route.push(end);
		while (!q_fastest_route.empty()) {
			int dest = q_fastest_route.front();
			q_fastest_route.pop();

			for (vector<int>::iterator it=fastest_route[dest].begin(); it!=fastest_route[dest].end(); ++it) {
				q_fastest_route.push((*it));
				for (vector<pair<int, int>>::iterator _it=road[(*it)].begin(); _it!=road[(*it)].end(); ++_it) {
					if ((*_it).second == dest) {
						road[(*it)].erase(_it);
						break;
					}
				}
			}
		}

		for (int i = 0; i < N; i++)
			d[i] = -1;

		d[start] = 0;
		q.push(make_pair(0, start));

		while (!q.empty()) {
			pair<int, int> candidate = q.front();
			int cost = candidate.first;
			int pos = candidate.second;
			q.pop();

			for (vector<pair<int, int>>::iterator it=road[pos].begin(); it!=road[pos].end(); ++it) {
				pair<int, int> _candidate = *it;
				int _value = _candidate.first;
				int _pos = _candidate.second;

				if (d[_pos] == -1 || d[_pos] > cost + _value) {
					d[_pos] = cost + _value;

					q.push(make_pair(d[_pos], _pos));
				}
			}
		}

		cout << d[end] << endl;
	}

	return 0;
}

/*
먼저 주어진 그래프로 다익스트라 알고리즘을 실행한다. 이 때, src에서 dest로 갈 때 d[dest]가 갱신이 되거나, 갱신이 되지 않더라도
d[dest]의 값과 d[src]+(src->dest)의 값이 같으면 그 간선 저장한다. 최단 경로가 여러 개 있을 수 있으므로 vector를 이용하여
갱신이 되지 않았지만 최단 경로일 때는 그 간선을 vector에 그대로 넣고, 갱신이 되었을 경우에는 그 vector를 clear한 뒤에 간선을 넣는다.

이 과정이 한 번 끝나면, 도착지점에서 출발지점까지의 최단 경로를 모두 알아낼 수 있다. 거꾸로 되짚어가며 최단 경로에 속해있는 간선을
road에서 지운다.

그런 뒤에 다시 한 번 다익스트라 알고리즘을 실행하면 '거의 최단 경로'의 길이를 알아낼 수 있다.
 */