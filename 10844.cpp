// Baekjoon Online Judge #10844
// (Dynamic Programming)

#include <iostream>

using namespace std;

int main() {
	int n;
	long long result = 0;
	cin >> n;

	long long **arr = new long long *[10];
	arr[0] = new long long[n];
	arr[0][0] = 0;

	for (int i = 1; i < 10; i++) {
		arr[i] = new long long[n];
		arr[i][0] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) 
				arr[0][i] = arr[1][i-1];
			else if (j == 9)
				arr[9][i] = arr[8][i-1];
			else
				arr[j][i] = (arr[j-1][i-1] + arr[j+1][i-1]) % 1000000000;
		}
	}

	for (int i = 0; i < 10; i++) {
		result += arr[i][n-1];
		if (result > 1000000000)
			result %= 1000000000;
	}

	cout << result << endl;
	return 0;
}

/*
끝자리가 k(1~8)인 N자리 계단수의 수는 N-1자리 계단수 중 끝자리가 
k-1, k+1인 수의 갯수의 합과 같다. 0과 9의 경우는 각각 N-1자리 계단수 중 끝자리가 1과 8인 
수와 같다.
 */