// Baekjoon Online Judge #1149
// (Dynamic Programming)

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	int *red = new int[n];
	int *green = new int[n];
	int *blue = new int[n];
	int *sum_red = new int[n];
	int *sum_green = new int[n];
	int *sum_blue = new int[n];

	for (int i = 0; i < n; i++) {
		int temp_r, temp_g, temp_b;
		cin >> temp_r >> temp_g >> temp_b;
		red[i] = temp_r;
		green[i] = temp_g;
		blue[i] = temp_b;
	}

	sum_red[0] = red[0];
	sum_green[0] = green[0];
	sum_blue[0] = blue[0];

	if (n > 0) {
		for (int i = 1; i < n; i++) {
			sum_red[i] = red[i] + min(sum_green[i-1], sum_blue[i-1]);
			sum_green[i] = green[i] + min(sum_red[i-1], sum_blue[i-1]);
			sum_blue[i] = blue[i] + min(sum_green[i-1], sum_red[i-1]);
		}
	}

	cout << min(sum_red[n-1], min(sum_green[n-1], sum_blue[n-1])) << endl;
	return 0;


/*
sum_[color] 배열의 i-th 요소는 i번째 집이 [color]를 선택할 때 가능한 최소 비용이다.
i번째 집이 red를 선택하면, i-1번째 집이 blue와 green을 선택했을 때 들어가는 비용 중 더 작은 값을
i번째 집에 red를 칠할 때 드는 비용에 더하면 된다.
 */