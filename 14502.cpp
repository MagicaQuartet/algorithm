#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int dfs(vector<vector<int>>& map, int x, int y) {
	int cnt = 0;
	if (map[x][y] == 3)
		cnt += 1;
	
	if (x-1 >= 0 && map[x-1][y] == 0) {
		map[x-1][y] = 3;
		cnt += dfs(map, x-1, y);
	}
	if (x+1 < map.size() && map[x+1][y] == 0) {
		map[x+1][y] = 3;
		cnt += dfs(map, x+1, y);
	}
	if (y-1 >= 0 && map[x][y-1] == 0) {
		map[x][y-1] = 3;
		cnt += dfs(map, x, y-1);
	}
	if (y+1 < map[0].size() && map[x][y+1] == 0) {
		map[x][y+1] = 3;
		cnt += dfs(map, x, y+1);
	}
	
	return cnt;
}

int solve(const vector<vector<int>>& map) {
	int cnt = 0;
	vector<vector<int>> _map (map);
	
	for (int i=0; i<map.size(); i++) {
		for (int j=0; j<map[0].size(); j++) {
			if (_map[i][j] == 2) {
				cnt += dfs(_map, i, j);
			}
		}
	}
	
	return cnt;
}

int main() {
	int N, M, temp, blank, ret;
	pair<int, int> wall1, wall2, wall3;
	vector<vector<int>> map;
	vector<pair<int, int>> point;
	
	cin.sync_with_stdio(false);
	cin >> N >> M;
	
	blank = 0;
	for (int i=0; i<N; i++) {
		map.push_back(vector<int>());
		for (int j=0; j<M; j++) {
			cin >> temp;
			map[i].push_back(temp);
			
			if (temp == 0) {
				point.push_back(make_pair(i, j));
				blank += 1;
			}
		}
	}
	
	ret = 0;
	
	for (int i=0; i<point.size()-2; i++) {
		wall1 = point[i];
		for (int j=i+1; j<point.size()-1; j++) {
			wall2 = point[j];
			for (int k=j+1; k<point.size(); k++) {
				wall3 = point[k];
				map[wall1.first][wall1.second] = 1;
				map[wall2.first][wall2.second] = 1;
				map[wall3.first][wall3.second] = 1;
				
				temp = blank - solve(map) - 3;
				if (ret < temp)
					ret = temp;
				
				map[wall1.first][wall1.second] = 0;
				map[wall2.first][wall2.second] = 0;
				map[wall3.first][wall3.second] = 0;
			}
		}
	}
	
	cout << ret << endl;
	return 0;
}

/* map의 크기가 작고 wall의 수도 3으로 고정되어있어 wall을 배치하는 가능한 모든 경우의 수에 대해 DFS/BFS를 하면 구할 수 있다. */