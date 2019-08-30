// Baekjoon Online Judge #11052
// (Dynamic Programming)

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	int *price = new int[n];
	int *profit = new int[n];

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		price[i] = temp;
	}

	profit[0] = price[0];

	for (int i = 1; i < n; i++) {
		int temp = price[i];
		for (int j = i-1; j >= 0; j--) {
			temp = max(temp, profit[j] + price[i-j-1]);
		}
		profit[i] = temp;
	}

	cout << profit[n-1] << endl;
	return 0;
}

/*
i개를 팔 때 얻을 수 있는 이익의 최댓값은 i-k개를 팔 때 얻을 수 있는 이익의 최댓값에 k개 세트의 값을 더한 것 중
최댓값이다.
 */