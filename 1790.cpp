// Baekjoon Online Judge #1790
// (Implementation)

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K, cnt = 1;
	long long temp = 10;
	long long length = 0;
	vector<long long> sublength;

	cin >> N >> K;

	while (N >= temp) {
		length += cnt == 1 ? 9 : (9 * temp / 10) * cnt;
		sublength.push_back(length);
		cnt++;
		temp *= 10;
	}

	if (sublength.empty())
		sublength.push_back(N);

	length += temp == 10 ? N : (N - temp / 10 + 1) * cnt;

	if (length < K) {
		cout << -1 << endl;
	}
	else {
		int k_cnt = 1;
		long long k_sublength = 0, k_distance;

		for (vector<long long>::iterator it=sublength.begin(); it!=sublength.end(); ++it) {
			if (K > *it) {
				k_sublength = *it;
				k_cnt++;
			}
			else
				break;
		}

		k_distance = K - k_sublength;
		if (k_cnt == 1) {
			cout << K << endl;
		}
		else {
			long long k_num_idx = (k_distance - 1) / k_cnt;
			int k_digit_idx = (k_distance - 1) % k_cnt;

			int k_temp = 1;
			for (int i = 2; i <= k_cnt; i++) {
				k_temp *= 10;
			}

			k_temp += k_num_idx;
			for (int i = 0; i < k_cnt - k_digit_idx - 1; i++) {
				k_temp /= 10;
			}
			
			cout << k_temp % 10 << endl;
		}
	}

	return 0;
}

/*
특별한 방법은 없고...

1. N까지의 수 중 자리 수가 얼마얼마인 수가 얼마나 있는지를 고려하여 전체 수열 길이를 구한다.
2. K가 그 길이보다 같거나 작으면, K가 몇 자리 수의 몇 번째 수가 커버하고 있는지 구한다.
3. K가 그 숫자의 몇 번째 자리 수인지 구한다.
4. K가 가리키는 숫자를 구한다.

조금 복잡하게 풀었지만 이 복잡한 과정을 깔끔하게 할 수 있을지는 몰라도 효율적인 알고리즘이 있는지는 잘 모르겠다..
 */