// Baekjoon Online Judge #2193
// (Dynamic Programming)

#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	long long *zero = new long long[n];
	long long *one = new long long[n];

	zero[0] = 0;
	one[0] = 1;

	for (int i = 1; i < n; i++) {
		zero[i] = zero[i-1] > 0 ? zero[i-1] + one[i-1] : one[i-1];
		one[i] = zero[i-1] > 0 ? zero[i-1] : 0;
	}

	cout << zero[n-1] + one[n-1] << endl;
	return 0;
}

/*
n자리 이친수 중에서 0으로 끝나는 수와 1로 끝나는 수의 개수를 따로 저장한다.
n자리 이친수는 n-1자리 이친수 중 0으로 끝나는 수 끝에 0 또는 1을 붙이거나
1로 끝나는 수 끝에 0을 붙여서 만들 수 있다.
이 때, n-1자리 이친수 중 0으로 끝나는 수의 개수가 0인 경우를 고려해야 한다.
 */