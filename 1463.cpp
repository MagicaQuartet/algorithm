// Baekjoon Online Judge #1463
// (Dynamic Programming)

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, result;
	cin >> n;

	if (n == 1)
		result = 0;
	else if (n == 2)
		result = 1;
	else if (n == 3)
		result = 1;
	else {
		int *cnt = new int[n];
		cnt[0] = 0;
		cnt[1] = 1;
		cnt[2] = 1;

		for (int i = 3; i < n; i++) {
			cnt[i] = cnt[i-1] + 1;
			if ((i+1) % 3 == 0)
				cnt[i] = min(cnt[(i+1)/3 - 1] + 1, cnt[i]);
			if ((i+1) % 2 == 0)
				cnt[i] = min(cnt[(i+1)/2 - 1] + 1, cnt[i]);
		}

		result = cnt[n-1];
	}

	cout << result << endl;
	return 0;
}

/*
기본적으로, n을 1로 만드는 데에 필요한 연산의 수는 n-1의 경우에 1을 더한 것이다.
그러나, n이 3으로 나누어진다면 n/3의 경우에 1을 더한 것이 더 작다.
n이 3의 배수는 아니지만 2의 배수일 때는 n/2의 경우에 1을 더한 것이 더 작다.
 */