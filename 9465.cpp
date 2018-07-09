// Baekjoon Online Judge #9465
// (Dynamic Programming)

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n;
		long long result = 0;
		cin >> n;

		long long **score = new long long*[2];
		score[0] = new long long[n];
		score[1] = new long long[n];

		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			score[0][i] = temp;
		}
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			score[1][i] = temp;
		}

		if (n == 1)
			result = max(score[0][0], score[1][0]);
		else if (n == 2)
			result = max(score[0][0] + score[1][1], score[1][0] + score[0][1]);
		else {
			long long **sum = new long long *[2];
			sum[0] = new long long[n];
			sum[1] = new long long[n];

			sum[0][0] = score[0][0];
			sum[1][0] = score[1][0];
			sum[0][1] = score[1][0] + score[0][1];
			sum[1][1] = score[0][0] + score[1][1];

			for (int j = 2; j < n; j++) {
				sum[0][j] = score[0][j] + max(sum[1][j-1], sum[1][j-2]);
				sum[1][j] = score[1][j] + max(sum[0][j-1], sum[0][j-2]);
			}

			result = max(sum[0][n-1], sum[1][n-1]);
		}

		cout << result << endl;
	}

	return 0;
}

/*
0번째 행 m번째 열의 스티커를 고를 때의 최댓값은 그 스티커의 점수에
1번째 행 m-1열의 스티커를 고를 때의 최댓값과 1번째 행 m-2열의 스티커를 고를 때의 최댓값 중
더 큰 값을 더한 것이다.
 */