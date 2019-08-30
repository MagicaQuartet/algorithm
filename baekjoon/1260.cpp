#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

void bfs(vector<vector<int>> &map, int N, int start){
	vector<int> visited;
	vector<int> next;
	queue<int> queue;

	for (int i = 0; i < N; i++){
		if (start == i)
			visited.push_back(1);
		else
			visited.push_back(0);
	}

	queue.push(start);

	while (!queue.empty()) {
		int cur = queue.front();
		printf("%d ", cur+1);
		queue.pop();

		for (vector<int>::iterator it=map[cur].begin(); it!=map[cur].end(); ++it) {
			if (visited[*it] == 0) {
				visited[*it] = 1;
				next.push_back(*it);
			}
		}

		if (queue.empty()) {
			for (vector<int>::iterator it=next.begin(); it!=next.end(); ++it)
				queue.push(*it);
			next.clear();
		}
	}

	printf("\n");
}

void dfs(vector<vector<int>> &map, int N, int start) {
	vector<int> visited;
	stack<pair<int, int>> stack;

	for (int i = 0; i < N; i++){
		visited.push_back(0);
	}

	stack.push(make_pair(start, 0));

	while (!stack.empty()) {
		pair<int, int> cur = stack.top();
		if (visited[cur.first] == 0) {
			printf("%d ", cur.first+1);
			visited[cur.first] = 1;
		}
		
		stack.pop();

		if (cur.second < map[cur.first].size()) {
			while (cur.second < map[cur.first].size() && visited[*(map[cur.first].begin() + cur.second)] == 1) {
				cur.second++;
			}

			if (cur.second >= map[cur.first].size())
				continue;

			stack.push(cur);
			stack.push(make_pair(*(map[cur.first].begin() + cur.second), 0));
		}
	}

	printf("\n");
}

int main() {
	int N, M, V, src, dst;

	scanf("%d %d %d", &N, &M, &V);

	vector<vector<int>> map;
	vector<vector<int>> connected;
	queue<int> q;

	for(int i = 0; i < N; i++) {
		map.push_back(vector<int>());
		connected.push_back(vector<int>());
		for (int j = 0; j < N; j++)
			connected.back().push_back(0);
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &src, &dst);

		if (connected[src-1][dst-1] == 0) {
			connected[src-1][dst-1] = 1;
			connected[dst-1][src-1] = 1;
			map[src-1].push_back(dst-1);
			map[dst-1].push_back(src-1);
		}
	}

	for (int i = 0; i < N; i++) {
		sort(map[i].begin(), map[i].end());
	}

	dfs(map, N, V-1);
	bfs(map, N, V-1);

	return 0;
}