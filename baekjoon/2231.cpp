#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int>& digits, int cnt, int N) {
	if (cnt == 0) {
		int result_n = 0;
		int result_digit = 0;
		for (vector<int>::iterator it=digits.begin(); it!=digits.end(); ++it) {
			result_n = result_n*10 + *it;
			result_digit += *it;
		}
		
		if (result_n + result_digit == N) {
			cout << result_n << endl;
			return true;
		}
		
		return false;
	}
	
	int ret;
	
	for (int i=0; i<10; i++) {
		digits.push_back(i);
		ret = solve(digits, cnt-1, N);
		digits.pop_back();
		if (ret)
			return true;
	}
	return false;
}

int countDigit(int n) {
	int cnt = 0;
	
	while (n > 0) {
		cnt += 1;
		n /= 10;
	}
	return cnt;
}

int main() {
	int N, ret, cnt, div;
	vector<int> container;
	
	cin.sync_with_stdio(false);
	cin >> N;
	
	ret = 0;
	cnt = countDigit(N);
	div = 1;
	for (int i=0; i<cnt-1; i++) {
		div *= 10;
	}
	
	ret = false;
	container.push_back((N/div)-1);
	
	if (cnt > 1 && ((N - cnt*9)/div != N/div)) {
		ret = solve(container, cnt-1, N);
	}
	
	if (!ret) {
		container.pop_back();
		container.push_back(N/div);
		ret = solve(container, cnt-1, N);
	}
	
	if (!ret)
		cout << 0 << endl;
	
	return 0;
}

/* 가장 큰 자리의 수가 달라지는 경우만 잘 고려해서 각 자리 수에 가능한 모든 수를 넣어보고 가능한 경우 중 가장 작은 것을 찾는다 */