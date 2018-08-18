// Backjoon Online Judge #2293
// (Dynamic Programming)

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, k, temp, result;
	scanf("%d %d", &n, &k);

	vector<int> coin;
	vector<vector<int>> dp;

	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		coin.push_back(temp);
	}

	sort(coin.begin(), coin.end());

	for (int i = 0; i < k; i++) {
		dp.push_back(vector<int>());
		for (int j = 0; j < n; j++) {
			if (i == coin[j]-1)
				dp.back().push_back(1);
			else
				dp.back().push_back(0);
		}
	}

	for (int i = coin[0]-1; i < k; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] != 0) {
				for (int l = j; l < n; l++)	{
					if (i + coin[l] < k) {
						dp[i + coin[l]][l] += dp[i][j];
					}
				}
			}
		}
	}

	result = 0;
	for (int i = 0; i < n; i++) {
		result += dp[k-1][i];
	}
	printf("%d\n", result);
	return 0;
}