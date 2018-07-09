// Baekjoon Online Judge #2167
// (Dynamic Programming)

#include <iostream>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	int **arr = new int *[N];
	int **sum = new int *[N+1];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[M];
		sum[i] = new int[M+1];
	}
	sum[N] = new int[M+1];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			arr[i][j] = temp;
		}
	}

	for (int i = 0; i < N+1; i++) {
		for (int j = 0; j < M+1; j++) {
			if (i == 0 || j == 0)
				sum[i][j] = 0;
			else if (i == 1)
				sum[i][j] = arr[i-1][j-1] + sum[i][j-1];
			else if (j == 1)
				sum[i][j] = arr[i-1][j-1] + sum[i-1][j];
			else
				sum[i][j] = arr[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}

	int K;
	cin >> K;

	for (int k = 0; k < K; k++) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;

		cout << sum[x][y] - sum[i-1][y] - sum[x][j-1] + sum[i-1][j-1] << endl;
	}

	return 0;
}

/*
배열을 받은 뒤에 (i, j)에 input 배열의 (0, 0) ~ (i, j) 영역의 합을 저장하는 새로운 이차원 배열 sum을 만든다.
여기서는 편의를 위해 i == 0 || j == 0인 곳은 0으로 채웠다.
sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]임을 간단히 사각형을 그려 확인할 수 있다.
배열 sum을 모두 채운 뒤, 구하고자 하는 영역의 합 역시 위와 비슷한 방식으로 구한다.
 */