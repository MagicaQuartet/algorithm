#include<iostream>

using namespace std;

int main() {
	long N, num, temp, ret;
	int cnt;
	
	cin.sync_with_stdio(false);
	cin >> N;
	
	num = N;
	temp = 1;
	cnt = 0;
	
	while (num > 0) {
		cnt++;
		temp *= 10;
		num /= 10;
	}
	
	temp = 1;
	ret = 0;
	for (int i=1; i<cnt; i++) {
		ret += i*9*temp;
		temp *= 10;
	}
	
	ret += cnt*(N-temp+1);
	
	cout << ret << endl;
	return 0;
}

/* 입력의 크기만 잘 고려하면 별거 아니다 */