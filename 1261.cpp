// Baekjoon Online Judge #1261
// (Dijkstra)

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> d;
	vector<vector<int>> wall;
	queue<pair<int, pair<int, int>>> q;

	for (int i = 0; i < M; i++) {
		d.push_back(vector<int>());
		for (int j = 0; j < N; j++)
			d.back().push_back(-1);

		wall.push_back(vector<int>());
	}
	d[0][0] = 0;

	for (int i = 0; i < M; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < N; j++) {
			wall[i].push_back(temp[j] == '0' ? 0 : 1);
		}
	}

	q.push(make_pair(0, make_pair(0, 0)));

	while (!q.empty()) {
		pair<int, pair<int, int>> candidate = q.front();
		int wall_cnt = candidate.first;
		int x = candidate.second.first;
		int y = candidate.second.second;
		q.pop();

		if (x-1 >= 0) {
			if (d[x-1][y] == -1 || d[x-1][y] > wall_cnt + wall[x-1][y]) {
				d[x-1][y] = wall_cnt + wall[x-1][y];
				q.push(make_pair(d[x-1][y], make_pair(x-1, y)));
			}
		}
		if (y-1 >= 0) {
			if (d[x][y-1] == -1 || d[x][y-1] > wall_cnt + wall[x][y-1]) {
				d[x][y-1] = wall_cnt + wall[x][y-1];
				q.push(make_pair(d[x][y-1], make_pair(x, y-1)));
			}
		}
		if (x+1 < M) {
			if (d[x+1][y] == -1 || d[x+1][y] > wall_cnt + wall[x+1][y]) {
				d[x+1][y] = wall_cnt + wall[x+1][y];
				q.push(make_pair(d[x+1][y], make_pair(x+1, y)));
			}
		}
		if (y+1 < N) {
			if (d[x][y+1] == -1 || d[x][y+1] > wall_cnt + wall[x][y+1]) {
				d[x][y+1] = wall_cnt + wall[x][y+1];
				q.push(make_pair(d[x][y+1], make_pair(x, y+1)));
			}
		}
	}

	cout << d[M-1][N-1] << endl;
	return 0;
}

/*
다익스트라 알고리즘을 이용해 각 지점까지 도달하고자 할 때 통과해야 하는 벽의 최소 개수를 구한다.
 */