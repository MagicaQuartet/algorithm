// Baekjoon Online Judge #2579
// (Dynamic Programming)

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, result;
	cin >> n;

	int *stairs = new int[n];

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		stairs[i] = temp;
	}

	if (n == 1) {
		result = stairs[0];
	}
	else if (n == 2) {
		result = stairs[0] + stairs[1];
	}
	else if (n == 3) {
		result = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);
	}
	else {
		int *score = new int[n];
		score[0] = stairs[0];
		score[1] = stairs[0] + stairs[1];
		score[2] = stairs[2] + max(score[0], stairs[1]);

		for (int i = 3; i < n; i++) {
			score[i] = stairs[i] + max(score[i-2], score[i-3] + stairs[i-1]);
		}

		result = score[n-1];
	}

	cout << result << endl;
	return 0;
}

/*
n번째 계단까지 얻을 수 있는 점수의 최댓값은 n-2번째 계단까지 얻을 수 있는 점수의 최댓값과
n-1번째 계단의 점수 + n-3번째 계단까지 얻을 수 있는 점수의 최댓값 중 더 큰 값이다.
 */