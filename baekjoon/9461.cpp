// Backjoon Online Judge #9461
// (Dynamic Programming)

#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		long long result;
		cin >> N;

		if (N <= 3)
			result = 1;
		else {
			long long *arr = new long long[N];

			arr[0] = 1;
			arr[1] = 1;
			arr[2] = 1;

			for (int j = 3; j < N; j++)
				arr[j] = arr[j-3] + arr[j-2];

			result = arr[N-1];
		}

		cout << result << endl;
	}

	return 0;	
}

/*
왜 그렇게 되는지는 모르겠는데 암튼 규칙성이 있음..
 */