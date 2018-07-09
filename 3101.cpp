// Baekjoon Online Judge #3101
// (Implementation)

#include <iostream>

using namespace std;

int main() {
	int N, K;
	int _x = 0, _y = 0;
	long long sum = 1;
	cin >> N >> K;

	long long *cnt = new long long[N];
	cnt[0] = 1;
	for (int i = 1; i < N; i++) {
		cnt[i] = cnt[i-1] + i+1;
	}

	char *jump = new char[K];
	cin >> jump;

	for (int i = 0; i < K; i++) {
		char direction = jump[i];
		int coordinate_sum;

		if (direction == 'U')
			_x--;
		else if (direction == 'D')
			_x++;
		else if (direction == 'L')
			_y--;
		else
			_y++;

		coordinate_sum = _x + _y;

		if (coordinate_sum <= N) {
			if (coordinate_sum % 2 == 0) {
				if (coordinate_sum != N)
					sum += coordinate_sum == 0 ? 1 : cnt[coordinate_sum-1] + (_y + 1);
				else
					sum += cnt[coordinate_sum-1] + (N - 1 - _x + 1);
			}
			else {
				if (coordinate_sum != N)
					sum += cnt[coordinate_sum-1] + (_x + 1);
				else
					sum += cnt[coordinate_sum-1] + (N - 1 - _y + 1);
			}
		}
		else {
			if (coordinate_sum % 2 == 0) {
				sum += cnt[N-1] + (cnt[N-2] - cnt[N-2-(coordinate_sum - N)]) + (N - 1 - _x + 1);
			}
			else {
				sum += cnt[N-1] + (cnt[N-2] - cnt[N-2-(coordinate_sum - N)]) + (N - 1 - _y + 1);
			}
		}
	}

	cout << sum << endl;
	return 0;
}

/*
행을 x좌표, 열을 y좌표, 왼쪽 위를 (0, 0)으로 봤을 때 (p, q) 자리에 어떤 수가 오는 지 계산할 수 있게 하였다.
대각선, 즉 p+q가 같은 부분들을 따라 숫자가 배치되는 것에 착안하였다.

이 때, 좌표의 합이 k일 때 좌표의 합이 k-1이하인 영역의 합을 구하는 과정이 필요한데 이를 매 점프마다 일일이 계산하려면
타임 리밋이 우려되어 N을 입력받을 때 O(N)으로 배열에 미리 저장하도록 하였다. 이 배열에는 좌표의 합이 N-1이하인 부분의 수만
저장되는데, N이상인 부분도 이 배열을 통해 숫자의 수를 구할 수 있으므로 문제 없다.
 */