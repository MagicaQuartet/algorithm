// Baekjoon Online Judge #6593
// (Dijkstra)

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main() {
	while (true) {
		int L, R, C;
		int start_x, start_y, start_z, end_x, end_y, end_z;
		cin >> L >> R >> C;

		if (L == 0)
			break;

		vector<vector<vector<char>>> building;
		vector<vector<vector<int>>> d;
		queue<pair<int, vector<int>>> q;

		for (int i = 0; i < L; i++) {
			building.push_back(vector<vector<char>>());
			d.push_back(vector<vector<int>>());

			for (int j = 0; j < R; j++) {
				string temp;

				building.back().push_back(vector<char>());
				d.back().push_back(vector<int>());

				cin >> temp;
				for (int k = 0; k < C; k++) {
					if (temp[k] == '.') {
						building.back().back().push_back('.');
						d.back().back().push_back(-1);
					}
					else if (temp[k] == '#') {
						building.back().back().push_back('#');
						d.back().back().push_back(-1);
					}
					else if (temp[k] == 'S') {
						building.back().back().push_back('.');
						d.back().back().push_back(0);
						start_x = i;
						start_y = j;
						start_z = k;
					}
					else {
						building.back().back().push_back('.');
						d.back().back().push_back(-1);
						end_x = i;
						end_y = j;
						end_z = k;	
					}
				}
			}
		}

		vector<int> pos;
		pos.push_back(start_x);
		pos.push_back(start_y);
		pos.push_back(start_z);
		q.push(make_pair(0, pos));

		while (!q.empty()) {
			pair<int, vector<int>> candidate = q.front();
			int cost = candidate.first;
			int pos_x = candidate.second[0];
			int pos_y = candidate.second[1];
			int pos_z = candidate.second[2];
			q.pop();

			if (pos_x - 1 >= 0 && building[pos_x-1][pos_y][pos_z] == '.' && (d[pos_x-1][pos_y][pos_z] == -1 || d[pos_x-1][pos_y][pos_z] > cost + 1)) {
				d[pos_x-1][pos_y][pos_z] = cost + 1;

				vector<int> _pos = vector<int>();
				_pos.push_back(pos_x-1);
				_pos.push_back(pos_y);
				_pos.push_back(pos_z);

				q.push(make_pair(cost+1, _pos));
			}
			if (pos_y - 1 >= 0 && building[pos_x][pos_y-1][pos_z] == '.' && (d[pos_x][pos_y-1][pos_z] == -1 || d[pos_x][pos_y-1][pos_z] > cost + 1)) {
				d[pos_x][pos_y-1][pos_z] = cost + 1;

				vector<int> _pos = vector<int>();
				_pos.push_back(pos_x);
				_pos.push_back(pos_y-1);
				_pos.push_back(pos_z);

				q.push(make_pair(cost+1, _pos));
			}
			if (pos_z - 1 >= 0 && building[pos_x][pos_y][pos_z-1] == '.' && (d[pos_x][pos_y][pos_z-1] == -1 || d[pos_x][pos_y][pos_z-1] > cost + 1)) {
				d[pos_x][pos_y][pos_z-1] = cost + 1;

				vector<int> _pos = vector<int>();
				_pos.push_back(pos_x);
				_pos.push_back(pos_y);
				_pos.push_back(pos_z-1);

				q.push(make_pair(cost+1, _pos));
			}
			if (pos_x + 1 < L && building[pos_x+1][pos_y][pos_z] == '.' && (d[pos_x+1][pos_y][pos_z] == -1 || d[pos_x+1][pos_y][pos_z] > cost + 1)) {
				d[pos_x+1][pos_y][pos_z] = cost + 1;

				vector<int> _pos = vector<int>();
				_pos.push_back(pos_x+1);
				_pos.push_back(pos_y);
				_pos.push_back(pos_z);

				q.push(make_pair(cost+1, _pos));
			}
			if (pos_y + 1 < R && building[pos_x][pos_y+1][pos_z] == '.' && (d[pos_x][pos_y+1][pos_z] == -1 || d[pos_x][pos_y+1][pos_z] > cost + 1)) {
				d[pos_x][pos_y+1][pos_z] = cost + 1;

				vector<int> _pos = vector<int>();
				_pos.push_back(pos_x);
				_pos.push_back(pos_y+1);
				_pos.push_back(pos_z);

				q.push(make_pair(cost+1, _pos));
			}
			if (pos_z + 1 < C && building[pos_x][pos_y][pos_z+1] == '.' && (d[pos_x][pos_y][pos_z+1] == -1 || d[pos_x][pos_y][pos_z+1] > cost + 1)) {
				d[pos_x][pos_y][pos_z+1] = cost + 1;

				vector<int> _pos = vector<int>();
				_pos.push_back(pos_x);
				_pos.push_back(pos_y);
				_pos.push_back(pos_z+1);

				q.push(make_pair(cost+1, _pos));
			}
		}

		if (d[end_x][end_y][end_z] != -1)
			cout << "Escaped in " << d[end_x][end_y][end_z] << " minute(s)." << endl;
		else
			cout << "Trapped!" << endl;
	}

	return 0;
}

/*
3차원 배열 형태이긴 한데 L, R, C의 범위가 크지 않으므로 단순히 다익스트라 알고리즘을 적용하여 충분히 풀 수 있다.
 */