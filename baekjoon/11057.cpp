// Backjoon Online Judge #11057
// (Dynamic Programming)

#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	long long **cnt = new long long *[10];
	for (int i = 0; i < 10; i++) {
		cnt[i] = new long long[N];
		cnt[i][0] = 1;
	}

	for (int i = 1; i < N; i++) {
		long long sum = 0;
		for (int j = 0; j < 10; j++) {
			cnt[j][i] = (cnt[j][i-1] + sum)%10007;
			sum += cnt[j][i-1];
		}
	}

	long long result = 0;
	for (int i = 0; i < 10; i++) {
		result += cnt[i][N-1]%10007;
	}

	cout << result%10007 << endl;
	return 0;
}

/*
k으로 끝나는 n자리 수의 개수는 0부터 k로 끝나는 n-1자리 수의 개수의 합과 같다.
이 때, 0부터 k로 끝나는 n-1자리 수의 개수를 O(k^2)으로 구하지 않고 O(k)로 구했다.
이게 러닝 타임에 큰 영향을 미치는 지는 모르겠다.
 */