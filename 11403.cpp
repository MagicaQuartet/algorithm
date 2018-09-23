#include <cstdio>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

int dfs(int N, int start, vector<vector<int>>& map, vector<vector<int>>& path) {
	stack<pair<int, int>> stack;

	for (vector<int>::iterator it=map[start].begin(); it!=map[start].end(); ++it) {
		stack.push(make_pair(*it, 0));
	}

	while (!stack.empty()) {
		pair<int, int> elem = stack.top();
		path[start][elem.first] = 1;
		stack.pop();

		if (map[elem.first].begin() + elem.second != map[elem.first].end()) {
			stack.push(make_pair(elem.first, elem.second+1));
			if (!path[start][*(map[elem.first].begin()+elem.second)])
				stack.push(make_pair(*(map[elem.first].begin()+elem.second), 0));
		}
	}

	return 0;
}

int main() {
	int N, input;
	scanf("%d", &N);

	vector<vector<int>> map;
	vector<vector<int>> path;

	for (int i = 0; i < N; i++) {
		map.push_back(vector<int>());
		path.push_back(vector<int>());
		for (int j = 0; j < N; j++) {
			scanf("%d", &input);
			if (input) {
				map.back().push_back(j);
				path.back().push_back(1);
			}
			else
				path.back().push_back(0);
		}
	}

	for (int i = 0; i < N; i++) {
		dfs(N, i, map, path);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", path[i][j]);
		}
		printf("\n");
	}

	return 0;
}