// Baekjoon Online Judge #1010
// (Dynamic Programming)

#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N, M;
		cin >> N >> M;

		long long **bridge = new long long *[M];
		for (int j = 0; j < M; j++) {
			bridge[j] = new long long[N];
			bridge[j][0] = j+1;

			for (int k = 1; k < N; k++) {
				bridge[j][k] = 0;
			}
		}

		for (int j = 1; j < M ; j++) {
			for (int k = 1; k <= j && k < N; k++) {
				bridge[j][k] = bridge[j-1][k-1] + bridge[j-1][k];
			}
		}

		cout << bridge[M-1][N-1] << endl;

		for (int j = 0; j < M; j++) {
			delete bridge[j];
		}
		delete bridge;
	}

	return 0;
}

/*
mCn을 계산하면 구할 수 있다. 일일이 팩토리얼 및 나눗셈 계산을 하지 않고
DP로 바닥부터 구해간다.
 */