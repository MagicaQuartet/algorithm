// Backjoon Online Judge #2294
// (Dynamic Programming)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int *coin_arr = new int[n];
	int *cnt = new int[k+1];

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		coin_arr[i] = temp;
	}

	vector<int> coin(coin_arr, coin_arr + n);
	sort(coin.begin(), coin.end());

	cnt[0] = 0;
	for (int i = 1; i < k+1; i++) {
		int temp = -1;
		for (vector<int>::reverse_iterator rit = coin.rbegin(); rit!=coin.rend(); ++rit) {
			if (i - *rit >= 0 && cnt[i - *rit] != -1) {
				if (temp == -1 || temp > cnt[i - *rit] + 1)
					temp = cnt[i - *rit] + 1;
			}
			cnt[i] = temp;
		}
	}

	cout << cnt[k] << endl;
	return 0;
}