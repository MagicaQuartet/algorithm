// Baekjoon Online Judge #9323
// (Dijkstra)

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n, m, start, end, s, p, y;
		cin >> n >> m >> start >> end >> s >> p >> y;

		vector<double> d_true;
		vector<double> d_false;
		vector<vector<pair<pair<int, int>, int>>> road;
		for (int j = 0; j < n; j++) {
			road.push_back(vector<pair<pair<int, int>, int>>());
			d_true.push_back(-1);
			d_false.push_back(-1);
		}
		d_true[start-1] = 0.0;
		d_false[start-1] = 0.0;

		for (int j = 0; j < m; j++) {
			int city1, city2, ticketCheck, length;
			cin >> city1 >> city2 >> ticketCheck >> length;

			road[city1-1].push_back(make_pair(make_pair(length, ticketCheck), city2));
			road[city2-1].push_back(make_pair(make_pair(length, ticketCheck), city1));
		}

		queue<pair<pair<double, bool>, int>> q;
		q.push(make_pair(make_pair(0.0, false), start));

		while (!q.empty()) {
			pair<pair<double, bool>, int> candidate = q.front();
			pair<double, bool> cost = candidate.first;
			int city = candidate.second;
			q.pop();

			for (vector<pair<pair<int, int>, int>>::iterator it=road[city-1].begin(); it!=road[city-1].end(); ++it) {
				pair<pair<int, int>, int> _candidate = *it;
				pair<int, int> fare_info = _candidate.first;
				int _city = _candidate.second;
				double next_cost;
				bool next_ride;

				if (cost.second) {
					next_cost = (y+fare_info.first*p)*fare_info.second/100.0;
					next_ride = false;

					if ((d_false[_city-1] < -1+0.0001 && d_false[_city-1] > -1-0.0001) || d_false[_city-1] > cost.first + next_cost) {
						d_false[_city-1] = cost.first + next_cost;
						q.push(make_pair(make_pair(d_false[_city-1], next_ride), _city));
					}

					next_cost = fare_info.first*p;
					next_ride = true;

					if ((d_true[_city-1] < -1+0.0001 && d_true[_city-1] > -1-0.0001) || d_true[_city-1] > cost.first + next_cost) {
						d_true[_city-1] = cost.first + next_cost;
						q.push(make_pair(make_pair(d_true[_city-1], next_ride), _city));
					}
				}
				else {
					next_cost = (y+fare_info.first*p)*fare_info.second/100.0;
					next_ride = false;

					if ((d_false[_city-1] < -1+0.0001 && d_false[_city-1] > -1-0.0001) || d_false[_city-1] > cost.first + next_cost) {
						d_false[_city-1] = cost.first + next_cost;
						q.push(make_pair(make_pair(d_false[_city-1], next_ride), _city));
					}

					next_cost = s+fare_info.first*p;
					next_ride = true;

					if ((d_true[_city-1] < -1+0.0001 && d_true[_city-1] > -1-0.0001) || d_true[_city-1] > cost.first + next_cost) {
						d_true[_city-1] = cost.first + next_cost;
						q.push(make_pair(make_pair(d_true[_city-1], next_ride), _city));
					}
				}
			}
		}

		printf("%.2f\n", min(d_true[end-1], d_false[end-1]));
	}

	return 0;
}

/*
각 간선에서 무임승차를 할 지 제 값을 내고 탈지를 정할 수 있는데, 그렇게 단순한 문제가 아니다.
제 값을 내고 여러 간선을 이어서 이동한다면, 티켓 기본 요금은 1번만 내도 된다. 그러나 그 사이사이에 무임승차 구간이 끼어있다면, 다시 제값을 내고 타는 지점에서
다시 티켓 기본 요금을 내야한다. 그러므로 단순히 greedy하게 다익스트라 알고리즘을 이용하면 안된다. 안타깝게도 예시 테스트들은 그냥 greedy하게 무임승차 할지 말지를 정해도 통과를 하는데
반례가 존재한다.

그러므로, 각 지점의 d값을 이전 지점에서 무임승차를 해서 온 경우와 제값을 내고 온 경우로 나누어서 저장한다. 또한, 큐에는 이전 지점에서 무임승차를 한 것인지 아닌지에 대한 정보도 넣는다.
큐에서 어떤 값을 꺼내면, 이어진 다음 구간들에 대해 무임승차 여부에 맞게 제값을 낼 때와 무임승차를 할 때의 기댓값을 각 각 계산하여 그 값과 무임승차 여부를 큐에 넣는다.

그러면, 도착지에 무임승차를 한 채로 도착하는 경우와 제값을 내고 도착하는 경우에 대해 d값이 저장되게 된다. 이 중 작은 값을 고르면 된다.
 */