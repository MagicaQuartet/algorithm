// Baekjoon Online Judge #2156
// (Dynamic Programming)

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, result;
	cin >> n;

	int *wine = new int[n];

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		wine[i] = temp;
	}

	if (n == 1)
		result = wine[0];
	else if (n == 2)
		result = wine[0] + wine[1];
	else if (n == 3) {
		result = max(wine[0] + wine[1], wine[2] + max(wine[0], wine[1]));
	}
	else {
		int *sum = new int[n];
		sum[0] = wine[0];
		sum[1] = wine[0] + wine[1];
		sum[2] = max(wine[0] + wine[1], wine[2] + max(wine[0], wine[1]));
		sum[3] = wine[3] + max(sum[1], sum[0] + wine[2]);
		
		for (int i = 4; i < n; i++) {
			sum[i] = wine[i] + max(sum[i-2], max(sum[i-3] + wine[i-1], sum[i-4] + wine[i-1]));
		}

		result = max(sum[n-1], sum[n-2]);
	}

	cout << result << endl;
	return 0;
}

/*
index가 4 이상 차이나는 잔을 고르면 그 사이에 있는 잔 하나를 항상 고를 수 있다.
그러므로 잔 사이의 간격은 최대 3이면 된다. 그 외의 풀이는 계단 오르기 문제와 유사하다.
 */