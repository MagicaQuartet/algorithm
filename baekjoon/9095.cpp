// Backjoon Online Judge #9095
// (Dynamic Programming)

#include <iostream>

using namespace std;

int main() {
	int T, result;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;

		if (n == 1)
			result = 1;
		else if (n == 2)
			result = 2;
		else if (n == 3)
			result = 4;
		else {
			long long *arr = new long long[n];
			arr[0] = 1;
			arr[1] = 2;
			arr[2] = 4;

			for (int i = 3; i < n; i++)
				arr[i] = arr[i-3] + arr[i-2] + arr[i-1];

			result = arr[n-1];
		}

		cout << result << endl;
	}
	return 0;
}

/*
n은 n-3의 경우에 3을 더하고, n-2의 경우에 2를 더하고, n-1의 경우에 1을 더하여 만들 수 있다.
이외의 경우는 모두 중복되므로 고려하지 않는다.
 */