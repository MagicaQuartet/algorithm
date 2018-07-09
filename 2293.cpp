// Backjoon Online Judge #2293
// (Dynamic Programming)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int *coin_arr = new int[n];
	long long *cnt = new long long[k+1];
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		coin_arr[i] = temp;
	}

	cnt[0] = 0;

	vector<int> coin(coin_arr, coin_arr + n);
	sort(coin.begin(), coin.end());

	for (int i = 1; i < k+1; i++) {
		cnt[i] = 0;
		for (vector<int>::iterator it=coin.begin(); it!=coin.end(); ++it) {
			if (*it <= i) {
				if (cnt[i-*it] == 0)
					cnt[i] = 1;
				else
					cnt[i] += cnt[i-*it];
			}
			else
				break;
		}
	}

	cout << cnt[k] << endl;
	return 0;
}