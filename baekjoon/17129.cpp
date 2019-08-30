#include<cstdio>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

int solve(vector<vector<char>>&map, queue<pair<pair<int, int>, int>> q) {
	while (!q.empty()) {
		pair<int, int> point = q.front().first;
		int depth = q.front().second;
		q.pop();
		
		if (map[point.first][point.second] >= '3') {
			return depth;
		}
		else if (map[point.first][point.second] == '1') {
			continue;
		}
		
		map[point.first][point.second] = '1';
		if (point.first+1 < map.size() && map[point.first+1][point.second] != '1') {
			q.push(make_pair(make_pair(point.first+1, point.second), depth+1));
		}
		if (point.first-1 >= 0 && map[point.first-1][point.second] != '1') {
			q.push(make_pair(make_pair(point.first-1, point.second), depth+1));
		}
		if (point.second+1 < map[0].size() && map[point.first][point.second+1] != '1') {
			q.push(make_pair(make_pair(point.first, point.second+1), depth+1));
		}
		if (point.second-1 >= 0 && map[point.first][point.second-1] != '1') {
			q.push(make_pair(make_pair(point.first, point.second-1), depth+1));
		}
	}
	
	return -1;
}

int main() {
	int n, m, x, y, ret;
	char cell;
	vector<vector<char>> map;
	queue<pair<pair<int, int>, int>> q;
	
	scanf("%d %d", &n, &m);
	
	for (int i=0; i<n; i++) {
		map.push_back(vector<char>());		
		for (int j=0; j<m; j++) {
			cell = getchar();
			while (cell=='\n')
				cell = getchar();
			
			map[i].push_back(cell);
			
			if (cell=='2') {
				x=i;
				y=j;
			}
		}
	}
	
	q.push(make_pair(make_pair(x, y), 0));
	ret = solve(map, q);
	if (ret==-1) {
		printf("NIE\n");
	}
	else {
		printf("TAK\n%d\n", ret);
	}
	
	return 0;
}