#include <cstdio>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int bfs(int M, int N, pair<int, int> start, vector<vector<int>>& map) {
	if (map[start.first][start.second]) {
		queue<pair<int, int>> q;
		q.push(start);

		while(!q.empty()) {
			pair<int, int> point = q.front();
			q.pop();
			if (!map[point.first][point.second])
				continue;

			map[point.first][point.second] = 0;

			if (point.first > 0 && map[point.first-1][point.second])
				q.push(make_pair(point.first-1, point.second));
			if (point.first < M-1 && map[point.first+1][point.second])
				q.push(make_pair(point.first+1, point.second));
			if (point.second > 0 && map[point.first][point.second-1])
				q.push(make_pair(point.first, point.second-1));
			if (point.second < N-1 && map[point.first][point.second+1])
				q.push(make_pair(point.first, point.second+1));
		}
		return 1;
	}
	else
		return 0;
}

int main() {
	int T, M, N, K, x, y, cnt;
	scanf("%d", &T);

	while (T--) {
		cnt = 0;
		vector<vector<int>> map;
		scanf("%d%d%d", &M, &N, &K);

		for(int i = 0; i < M; i++) {
			map.push_back(vector<int>());
			for (int j = 0; j < N; j++) {
				map.back().push_back(0);
			}
		}

		for (int i = 0; i < K; i++) {
			scanf("%d%d", &x, &y);
			map[x][y] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (bfs(M, N, make_pair(i, j), map))
					cnt++;
			}
		}

		printf("%d\n", cnt);
	}
}