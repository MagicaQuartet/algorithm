// Baekjoon Online Judge #2004
// (Math, Combination)

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long long n, m, k, temp;
	long long n_two_cnt = 0, m_two_cnt = 0, k_two_cnt = 0, n_five_cnt = 0, m_five_cnt = 0, k_five_cnt = 0;
	long long two_cnt, five_cnt;
	cin >> n >> m;

	k = n - m;

	temp = 2;
	while (n >= temp) {
		n_two_cnt += n / temp;
		temp *= 2;
	}

	temp = 2;
	while (m >= temp) {
		m_two_cnt += m / temp;
		temp *= 2;
	}

	temp = 2;
	while (k >= temp) {
		k_two_cnt += k / temp;
		temp *= 2;
	}
		

	temp = 5;
	while (n >= temp) {
		n_five_cnt += n / temp;
		temp *= 5;
	}

	temp = 5;
	while (m >= temp) {
		m_five_cnt += m / temp;
		temp *= 5;
	}

	temp = 5;
	while (k >= temp) {
		k_five_cnt += k / temp;
		temp *= 5;
	}

	two_cnt = n_two_cnt - m_two_cnt - k_two_cnt;
	five_cnt = n_five_cnt - m_five_cnt - k_five_cnt;

	cout << min(two_cnt, five_cnt) << endl;
	
	return 0;
}

/*
소인수분해를 했을 때 2의 지수와 5의 지수를 비교한 뒤 작은 값을 출력한다.
항상 5의 지수가 더 적을 줄 알았는데 그렇지 않은 경우도 있는 모양이다.
 */