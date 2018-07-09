// Baekjoon Online Judge #1912
// (Dynamic Programming)

#include <iostream>

using namespace std;

int main() {
	int n, max, sum;

	cin >> n;

	int *input = new int[n];

	for (int i = 0; i < n ; i++) {
		int temp;
		cin >> temp;
		input[i] = temp;
	}

	sum = input[0];
	max = input[0];

	if (sum < 0)
		sum = 0;

	for (int i = 1; i < n; i++) {
		sum += input[i];

		if (max < sum)
			max = sum;

		if (sum < 0)
			sum = 0;
	}

	cout << max << endl;
	return 0;
}

/*
첫 번째 수부터 순서대로 누적합과 누적합의 최댓값을 구한다.
누적합이 음수가 되었을 때, 누적된 구간과 그 이후의 구간을 합한 값은 
항상 그 이후의 구간만을 합한 값보다 작게 되기 때문에
누적합을 초기화한다.
 */