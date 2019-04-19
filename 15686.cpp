#include<iostream>
#include<vector>
#include<utility>
#include<limits>
#include<cstdlib>

using namespace std;

int solve(const vector<pair<int, int>>& house, const vector<pair<int, int>> chicken, vector<int> pick, int idx, int M) {
	int ret;
	
	if (M == 0 || idx == chicken.size()) {
		ret = 0;
		for (int i=0; i<house.size(); i++) {
			int min_dist = numeric_limits<int>::max();
			for (int j=0; j<pick.size(); j++) {
				int dist = abs(house[i].first - chicken[pick[j]].first) + abs(house[i].second - chicken[pick[j]].second);
				
				if (dist < min_dist)
					min_dist = dist;
			}
			
			if (min_dist == numeric_limits<int>::max())
				continue;
			ret += min_dist;
		}
		
		if (ret == 0)
			return numeric_limits<int>::max();
		return ret;
	}
	
	int _ret1, _ret2;
	
	_ret1 = solve(house, chicken, pick, idx+1, M);
	
	pick.push_back(idx);
	_ret2 = solve(house, chicken, pick, idx+1, M-1);
	pick.pop_back();
	
	ret = _ret1 < _ret2 ? _ret1 : _ret2;
	
	return ret;
}

int main() {
	int N, M, num;
	vector<pair<int, int>> house;
	vector<pair<int, int>> chicken;
	
	cin.sync_with_stdio(false);
	cin >> N >> M;
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> num;
			
			if (num == 1) {
				house.push_back(make_pair(i, j));
			}
			else if (num == 2) {
				chicken.push_back(make_pair(i, j));
				
			}
		}
	}
	
	cout << solve(house, chicken, vector<int>(), 0, M) << endl;
}

/* 치킨집을 고르는 모든 경우의 수에 대해 가장 짧은 치킨 거리를 구한다 */