#include<iostream>
#include<vector>
#include<limits>

using namespace std;

int solve(const vector<vector<char>>& map, int rx, int ry, int bx, int by, int cnt) {
	if (cnt > 9)
		return -1;
	
	int ret	= numeric_limits<int>::max();
	int _ret;
	
	_ret = -1;
	for (int i=rx-1; i>=0; i--) {
		if (map[i][ry] == '#') {
			for (int j=bx-1; j>=0; j--) {
				if (map[j][by] == '#') {
					if (ry != by) {
						_ret = solve(map, i+1, ry, j+1, by, cnt+1);
					}
					else if (i != j) {
						_ret = solve(map, i+1, ry, j+1, by, cnt+1);
					}
					else {
						if (rx < bx) {
							_ret = solve(map, i+1, ry, i+2, by, cnt+1);
						}
						else {
							_ret = solve(map, i+2, ry, i+1, by, cnt+1);
						}
					}
					
					break;
				}
				else if (map[j][by] == 'O') {
					break;
				}
			}
			
			break;
		}
		else if (map[i][ry] == 'O') {
			for (int j=bx-1; j>=0; j--) {
				if (map[j][by] == '#') {
					_ret = cnt+1;
					break;
				}
				else if (map[j][by] == 'O') {
					break;
				}
			}
			
			break;
		}
	}
	
	if (_ret != -1 && _ret < ret) {
		ret = _ret;
	}
	
	_ret = -1;
	for (int i=ry+1; i<map[0].size(); i++) {
		if (map[rx][i] == '#') {
			for (int j=by+1; j<map[0].size(); j++) {
				if (map[bx][j] == '#') {
					if (rx != bx) {
						_ret = solve(map, rx, i-1, bx, j-1, cnt+1);
					}
					else if (i != j) {
						_ret = solve(map, rx, i-1, bx, j-1, cnt+1);
					}
					else {
						if (ry < by) {
							_ret = solve(map, rx, i-2, bx, i-1, cnt+1);
						}
						else {
							_ret = solve(map, rx, i-1, bx, i-2, cnt+1);
						}
					}
					
					break;
				}
				else if (map[bx][j] == 'O') {
					break;
				}
			}
			
			break;
		}
		else if (map[rx][i] == 'O') {
			for (int j=by+1; j<map[0].size(); j++) {
				if (map[bx][j] == '#') {
					_ret = cnt+1;
					break;
				}
				else if (map[bx][j] == 'O') {
					break;
				}
			}
			
			break;
		}
	}
	
	if (_ret != -1 && _ret < ret) {
		ret = _ret;
	}
	
	_ret = -1;
	for (int i=rx+1; i<map.size(); i++) {
		if (map[i][ry] == '#') {
			for (int j=bx+1; j<map.size(); j++) {
				if (map[j][by] == '#') {
					if (ry != by) {
						_ret = solve(map, i-1, ry, j-1, by, cnt+1);
					}
					else if (i != j) {
						_ret = solve(map, i-1, ry, j-1, by, cnt+1);
					}
					else {
						if (rx < bx) {
							_ret = solve(map, i-2, ry, i-1, by, cnt+1);
						}
						else {
							_ret = solve(map, i-1, ry, i-2, by, cnt+1);
						}
					}
					
					break;
				}
				else if (map[j][by] == 'O') {
					break;
				}
			}
			
			break;
		}
		else if (map[i][ry] == 'O') {
			for (int j=bx+1; j<map.size(); j++) {
				if (map[j][by] == '#') {
					_ret = cnt+1;
					break;
				}
				else if (map[j][by] == 'O') {
					break;
				}
			}
			
			break;
		}
	}
	
	if (_ret != -1 && _ret < ret) {
		ret = _ret;
	}
	
	_ret = -1;
	for (int i=ry-1; i>=0; i--) {
		if (map[rx][i] == '#') {
			for (int j=by-1; j>=0; j--) {
				if (map[bx][j] == '#') {
					if (rx != bx) {
						_ret = solve(map, rx, i+1, bx, j+1, cnt+1);
					}
					else if (i != j) {
						_ret = solve(map, rx, i+1, bx, j+1, cnt+1);
					}
					else {
						if (ry < by) {
							_ret = solve(map, rx, i+1, bx, i+2, cnt+1);
						}
						else {
							_ret = solve(map, rx, i+2, bx, i+1, cnt+1);
						}
					}
					
					break;
				}
				else if (map[bx][j] == 'O') {
					break;
				}
			}
			
			break;
		}
		else if (map[rx][i] == 'O') {
			for (int j=by-1; j>=0; j--) {
				if (map[bx][j] == '#') {
					_ret = cnt+1;
					break;
				}
				else if (map[bx][j] == 'O') {
					break;
				}
			}
			
			break;
		}
	}
	
	if (_ret != -1 && _ret < ret) {
		ret = _ret;
	}
	
	
	if (ret == numeric_limits<int>::max())
		ret = -1;
	return ret;
}

int main() {
	int N, M, rx, ry, bx, by;
	char cell;
	vector<vector<char>> map;
	
	cin.sync_with_stdio(false);
	cin >> N >> M;
	
	for (int i=0; i<N; i++) {
		map.push_back(vector<char>());
		for (int j=0; j<M; j++) {
			cin >> cell;
			
			if (cell == 'R') {
				rx = i;
				ry = j;
				cell = '.';
			}
			else if (cell == 'B') {
				bx = i;
				by = j;
				cell = '.';
			}
			
			map[i].push_back(cell);
		}
	}
	
	cout << solve(map, rx, ry, bx, by, 0) << endl;
	return 0;
}

/* 보드를 네 방향으로 기울일 때 일어날 수 있는 모든 경우를 ***침착히*** 잘 고려해서 답을 구한다.
   그리고 cnt 인자가 10이라는 것은 이미 보드를 10번 움직였고 그 상태에서 아직 R이 O에 들어가지 않았으면 무효가 되므로
   8번째 라인에서 조건문의 조건은 cnt > 10이 아닌 cnt > 9가 되어야 한다. */