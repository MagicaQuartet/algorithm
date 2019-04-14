#include<iostream>
#include<cstdlib>
#include<vector>
#include<limits>

using namespace std;

int solve(const vector<vector<int>> S, vector<int> start, vector<int> link, int cnt) {
	if (cnt > S.size()) {
		int start_sum = 0, link_sum = 0;
		
		for (int i=0; i<start.size()-1; i++) {
			for (int j=i+1; j<start.size(); j++) {
				start_sum += S[start[i]][start[j]] + S[start[j]][start[i]];
				link_sum += S[link[i]][link[j]] + S[link[j]][link[i]];
			}
		}
		
		return abs(start_sum - link_sum);
	}
	
	int ret;
	
	if (start.size() == S.size()/2) {
		link.push_back(cnt);
		ret = solve(S, start, link, cnt+1);
		link.pop_back();
	}
	else if (link.size() == S.size()/2) {
		start.push_back(cnt);
		ret = solve(S, start, link, cnt+1);
		start.pop_back();
	}
	else {
		int ret_start, ret_link;
		start.push_back(cnt);
		ret_start = solve(S, start, link, cnt+1);
		start.pop_back();
		
		link.push_back(cnt);
		ret_link = solve(S, start, link, cnt+1);
		link.pop_back();
		
		ret = ret_start < ret_link ? ret_start : ret_link;
	}
	
	return ret;
}

int main() {
	int N, temp;
	vector<vector<int>> S;
	
	cin.sync_with_stdio(false);
	cin >> N;
	
	for (int i=0; i<N; i++) {
		S.push_back(vector<int>());
		for (int j=0; j<N; j++) {
			cin >> temp;
			S[i].push_back(temp);
		}
	}
	
	cout << solve(S, vector<int>(), vector<int>(), 0) << endl;
	
	return 0;
}


/* 재귀함수를 이용하여 팀을 짜는 모든 방법에 대해 능력치를 계산한다 */