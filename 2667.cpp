#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int bfs(int N, pair<int, int>& start, vector<vector<int>>& map, vector<vector<int>>& visited) {
	if (visited[start.first][start.second])
		return 0;
	else {
		int cnt = 0;
		queue<pair<int, int>> q;

		q.push(start);

		while (!q.empty()) {
			pair<int, int> point = q.front();
			q.pop();
			if (!map[point.first][point.second] || visited[point.first][point.second])
				continue;
			cnt++;
			visited[point.first][point.second] = 1;

			if (point.first > 0 && !visited[point.first-1][point.second])
				q.push(make_pair(point.first-1, point.second));
			if (point.first < N-1 && !visited[point.first+1][point.second])
				q.push(make_pair(point.first+1, point.second));
			if (point.second > 0 && !visited[point.first][point.second-1])
				q.push(make_pair(point.first, point.second-1));
			if (point.second < N-1 && !visited[point.first][point.second+1])
				q.push(make_pair(point.first, point.second+1));
		}

		return cnt;
	}
}

int main() {
	int N, cnt = 0;
	char *c;
	scanf("%d", &N);

	vector<vector<int>> map;
	vector<vector<int>> visited;
	vector<int> result;
	c = new char[N+1];

	for (int i = 0; i < N; i++) {
		map.push_back(vector<int>());
		visited.push_back(vector<int>());
		scanf("%s", c);
		for (int j = 0; j < N; j++) {
			map.back().push_back(c[j] == '0' ? 0 : 1);
			visited.back().push_back(0);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				int ret = bfs(N, make_pair(i, j), map, visited);
				if (ret > 0) {
					cnt++;
					result.push_back(ret);
				}
			}
		}
	}

	sort(result.begin(), result.end());
	printf("%d\n", cnt);
	for (vector<int>::iterator it=result.begin(); it!=result.end(); ++it)
		printf("%d\n", *it);

	return 0;
}