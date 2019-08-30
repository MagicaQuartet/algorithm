// Baekjoon Online Judge #11502
// (Daejeon Regional)

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T, K;

	vector<int> prime;
	prime.push_back(2);
	prime.push_back(3);
	prime.push_back(5);
	prime.push_back(7);
	prime.push_back(11);
	prime.push_back(13);
	prime.push_back(17);
	prime.push_back(19);

	for (int i = 20; i < 1000; i++) {
		bool isPrime = true;
		for (vector<int>::iterator it=prime.begin(); it!=prime.end(); ++it) {
			if ((*it)*(*it) > i)
				break;

			if (i % (*it) == 0) {
				isPrime = false;
				break;
			}
		}

		if (isPrime)
			prime.push_back(i);
	}

	cin >> T;
	for (int test = 0; test < T; test++) {
		bool isThreePrime = false;
		cin >> K;

		for (int i = 0; i < prime.size(); i++) {
			if (isThreePrime || prime[i] > K / 3)
				break;

			for (int j = i; j < prime.size(); j++) {
				if (isThreePrime || prime[i] + 2*prime[j] > K)
					break;

				for (int k = j; j < prime.size(); k++) {
					if (prime[i] + prime[j] + prime[k] > K)
						break;

					if (prime[i] + prime[j] + prime[k] == K) {
						isThreePrime = true;
						cout << prime[i] << " " << prime[j] << " " << prime[k] << endl;
						break;
					}
				}
			}
		}

		if (!isThreePrime)
			cout << -1 << endl;
	}

	return 0;
}

/*
먼저 1000 미만의 소수를 모두 구한 뒤, 입력 받은 수를 세 소수로 나타낼 수 있는지 확인한다.
일일히 모든 조합을 확인하되, 아예 불가능한 조합은 건너뛰고 오름차순인 조합만 확인하는 등
최적화를 해주면 시간 문제없이 된다.
 */