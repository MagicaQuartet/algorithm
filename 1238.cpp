// Baekjoon Online Judge #1238
// (Dijkstra)

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main() {
	int N, M, X;
	cin >> N >> M >> X;

	int *dFromX = new int[N];
	int *dToX = new int[N];
	vector<vector<pair<int, int>>> eFromX;
	vector<vector<pair<int, int>>> eToX;
	queue<pair<int, int>> qFromX;
	queue<pair<int, int>> qToX;

	for (int i = 0; i < N; i++) {
		dFromX[i] = -1;
		dToX[i] = -1;
		eFromX.push_back(vector<pair<int, int>>());
		eToX.push_back(vector<pair<int, int>>());
	}

	for (int i = 0; i < M; i++) {
		int src, dest, value;
		cin >> src >> dest >> value;

		eToX[src-1].push_back(make_pair(dest, value));
		eFromX[dest-1].push_back(make_pair(src, value));

		if (src == X)
			qToX.push(make_pair(dest, value));
		if (dest == X)
			qFromX.push(make_pair(src, value));
	}

	dFromX[X-1] = 0;
	dToX[X-1] = 0;

	while (!qFromX.empty()) {
		pair<int, int> candidate = qFromX.front();
		int src = candidate.first;
		int value = candidate.second;
		qFromX.pop();

		if (dFromX[src-1] == -1 || dFromX[src-1] > value) {
			dFromX[src-1] = value;
			for (vector<pair<int, int>>::iterator it=eFromX[src-1].begin(); it!=eFromX[src-1].end(); ++it) {
				pair<int, int> _candidate = *it;
				qFromX.push(make_pair(_candidate.first, _candidate.second + value));
			}
		}
	}

	while (!qToX.empty()) {
		pair<int, int> candidate = qToX.front();
		int dest = candidate.first;
		int value = candidate.second;
		qToX.pop();

		if (dToX[dest-1] == -1 || dToX[dest-1] > value) {
			dToX[dest-1] = value;
			for (vector<pair<int, int>>::iterator it=eToX[dest-1].begin(); it!=eToX[dest-1].end(); ++it) {
				pair<int, int> _candidate = *it;
				qToX.push(make_pair(_candidate.first, _candidate.second + value));
			}
		}
	}

	int max = 0;
	for (int i = 0; i < N; i++) {
		if (dToX[i] != -1 && dFromX[i] != -1 && dToX[i] + dFromX[i] > max)
			max = dToX[i] + dFromX[i];
	}

	cout << max << endl;
	return 0;
}

/*
파티가 열리는 X에 대해 다른 모든 지점에서 X로 가는 거리와 X에서 다른 모든 지점으로 가는 거리를 알아야 하는 문제이다.
임의의 두 점 사이의 최단거리를 모두 구하고 그 중에서 필요한 것을 골라야 하나 생각을 했지만 아무래도 그건 너무 오래 걸릴 것 같아서
(플로이드-워셜을 써도 되는지 안되는지는 안해봐서 모른다)
사실 잘 생각해보면 완전히 모든 임의의 두 점 간의 최단거리를 구해야하는 것은 아니다. 한 쪽은 X, 다른 한 쪽은 X가 아닌 나머지로 고정되어있다.
이에 착안하여 다익스트라 알고리즘을 2번 쓰는 방법을 생각하였다.

1) X에서 다른 모든 점으로 가는 최단 거리는 X를 기준으로 하는 다익스트라 알고리즘을 그대로 이용하면 된다.

2) 다른 모든 점에서 X로 가는 각 거리는, 입력된 edge에서 시작점과 도착점을 반대로 하여 저장한 뒤 다익스트라 알고리즘을 적용하였다.
이 경우 d[i]에는 (i+1)지점에서 X로 가는 최단 거리가 저장된다.

1)과 2)의 결과물을 d1, d2라고 하면, d1[i] + d2[i] 중 가장 큰 값을 골라내면 된다.
 */