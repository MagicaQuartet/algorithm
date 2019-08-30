// Baekjoon Online Judge #11501
// (Daejeon Regional)

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T, N;
	cin >> T;

	for (int test = 0; test < T; test++) {
		cin >> N;

		vector<int> price;
		vector<int> max_peak;
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			price.push_back(temp);
			max_peak.push_back(0);
		}

		int max_price = 0;
		for (int i = N-1; i >= 0; i--) {
			if (price[i] > max_price)
				max_price = price[i];
			max_peak[i] = max_price;
		}

		long long sum = 0;
		for (int i = 0; i < N; i++)
			sum += max_peak[i]-price[i];

		cout << sum << endl;
	}
}

/*
주가를 순서대로 저장한다.
저장한 주가를 뒤에서 앞으로 탐색하는 방식으로 i일 및 그 이후에 등장하는 가장 높은 주가를 i일에 대한 정보로 저장한다.
즉, 2 7 6이 주어졌을 때 그 정보는 7 7 6이 된다. 또한, 10 7 6일 경우 그대로 10 7 6이 된다.

그런 뒤, 모든 날에 대해 당일 또는 그 이후로 등장하는 가장 높은 주가에 당일의 주가를 뺀다. 그리고 그 값을 모두 더한다.
 */