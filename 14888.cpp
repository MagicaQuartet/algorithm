#include<iostream>
#include<vector>
#include<limits>

using namespace std;

int solve(const vector<int>& num, const int N, vector<int>& op, int sum, int idx, int mode) {
	if (idx == N)
		return sum;
	
	int ret = (mode == 0) ? numeric_limits<int>::max() : numeric_limits<int>::min();
	
	for (int i=0; i<4; i++) {
		if (op[i] == 0)
			continue;
		
		int temp;
		
		op[i]--;
		if (i==0) {
			temp = solve(num, N, op, sum+num[idx], idx+1, mode);
		}
		else if (i==1) {
			temp = solve(num, N, op, sum-num[idx], idx+1, mode);
		}
		else if (i==2) {
			temp = solve(num, N, op, sum*num[idx], idx+1, mode);
		}
		else {
			temp = solve(num, N, op, sum/num[idx], idx+1, mode);
		}
		
		if (mode == 0) {
			if (ret > temp)
				ret = temp;
		}
		else {
			if (ret < temp)
				ret = temp;
		}
		op[i]++;
	}
	
	return ret;
}

int main() {
	int N, minret, maxret;
	
	vector<int> num;
	vector<int> op;
	
	cin.sync_with_stdio(false);
	cin >> N;
	
	for (int i=0; i<N; i++) {
		int temp;
		cin >> temp;
		num.push_back(temp);
	}
	
	for (int i=0; i<4; i++) {
		int temp;
		cin >> temp;
		op.push_back(temp);
	}
	
	minret = solve(num, N, op, num[0], 1, 0);
	maxret = solve(num, N, op, num[0], 1, 1);
	
	cout << maxret << endl << minret << endl;
	return 0;
}

/* 재귀함수를 이용한 brute force */