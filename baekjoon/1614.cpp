// Baekjoon Online Judge #1614
// (Math)

#include <iostream>

using namespace std;

int main() {
	int finger;
	long long cnt, num;

	cin >> finger >> cnt;

	if (finger == 1) {
		num = 8 * cnt;
	}
	else if (finger == 5) {
		num = 8 * cnt + 4;
	}
	else {
		if (cnt % 2 == 1) {
			num = 4 * cnt + (5 - finger);
		}
		else {
			num = 4 * cnt + finger - 1;
		}
	}

	cout << num << endl;
	return 0;
}

/*
엄지 / 새끼 / 그 외 손가락으로 분류해서 풀면 쉽다.
 */