// Baekjoon Online Judge #1003
// (Dynamic Programming)

#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int num;
		cin >> num;

		if (num == 0) {
			cout << 1 << " " << 0 << endl;
			continue;
		}
		else if (num == 1) {
			cout << 0 << " " << 1 << endl;
			continue;
		}
		else {
			int *zeros = new int[num+1];
			int *ones = new int[num+1];

			zeros[0] = 1;
			zeros[1] = 0;
			ones[0] = 0;
			ones[1] = 1;

			for (int i = 2; i < num+1; i++) {
				zeros[i] = zeros[i-1] + zeros[i-2];
				ones[i] = ones[i-1] + ones[i-2];
			}

			cout << zeros[num] << " " << ones[num] << endl;
		}
	}

	return 0;
}

/*
인자에 따라 0과 1이 출력되는 횟수를 각각 저장한다.
0과 1이 인자로 주어졌을 때의 각 횟수를 먼저 저장한 뒤,
이를 이용해 오름차순으로 배열을 채우며 n이 주어졌을 때
0과 1이 출력되는 횟수를 구한다.
 */