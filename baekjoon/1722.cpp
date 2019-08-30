// Baekjoon Online Judge #1722
// (Math, Implementation)

#include <iostream>

using namespace std;

int main() {
	int N, mode;
	cin >> N >> mode;

	long long *factorial = new long long[N];
	factorial[0] = 1;	// NOTE: factorial[0] will be not used
	for (int i = 1; i < N; i++) {
		factorial[i] = factorial[i-1] * i;
	}

	if (mode == 1) {
		long long k;
		cin >> k;
		k -= 1;

		int *used = new int[N];		// used number from 1 to N
		int *quotient = new int[N];
		for (int i = 0; i < N; i++) {
			used[i] = 0;
			quotient[i] = 0;
		}

		for (int i = N-1; i > 0; i--) {
			quotient[i] = k / factorial[i];
			k %= factorial[i];
		}

		for (int i = N-1; i >= 0; i--) {
			int cnt = 0;
			for (int j = 0; j < N; j++) {
				if (cnt == quotient[i] && used[j] == 0) {
					cout << j+1 << " ";
					used[j] = 1;
					break;
				}

				if (used[j] == 0)
					cnt++;
			}
		}

		cout << endl;
	}
	else {
		int *inputSequence = new int[N];

		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			inputSequence[i] = temp;
		}

		for (int i = 0; i < N; i++) {
			int temp = inputSequence[i];
			for (int j = i+1; j < N; j++) {
				if (inputSequence[j] > temp)
					inputSequence[j]--;
			}
		}

		long long result = 1;

		for (int i = 0; i < N; i++) {
			result += (inputSequence[i] - 1) * factorial[N - 1 - i];
		}

		cout << result << endl;
	}

	return 0;
}

/*
일단 어느쪽이든 factorial를 쓸 것이므로 먼저 O(n)으로 1!부터 N!까지의 값을 저장한다.

각 문제에 대해 설명을 하기 전에, 임의의 수열에서 각 자리의 숫자가 늘어날 때 마다 어떤 변화가 일어나는 지 생각해보자.
뒤에서 k번째 수가 증가하면, 모든 수열을 1 2 ... N 부터 순서대로 번호를 붙였을 때, (k-1)!의 배수 만큼 번호가 증가할 것이다.
이를 이용하기 위해 미리 factorial을 계산했다. 물론 k번째 수가 l만큼 늘어난다고 (k-1)! * l이 늘어나는 것은 아니다. 단순히 얼마가
증가했는지가 중요한 것이 아니고, 그 자리에 들어갈 수 있는 몇 번째로 작은 수가 있는지가 중요한 것이기 때문이다. 예를 들어
2 1 3 4에서 2 3 1 4로 바뀌면 뒤에서 3번째 자리의 수가 2만큼 늘어났다고 생각하지 않고 1만큼 늘어났다고 간주를 해야 한다.

1번 문제에서는, k번째 수열을 만들기 위해 각 자리의 숫자가 얼마나 바뀌어야 하는지를 계산하고 quotient 배열에 저장한다.. 위에서 말했듯이, 바뀌어야 하는 정도는 단순 수치가
아니라 가능한 수 중 몇 번째로 작은 수가 오는지에 대한 것이다. 그런 뒤에, quotient 배열을 보면서 앞에서부터 어떤 숫자들이 나열되는지를 출력한다.
이 때, 사용한 숫자는 used 배열에 체크를 하여 '가능한 몇 번째로 작은 수'를 찾을 수 있게 한다.

2번 문제에서는, 각 자리의 숫자들이 그 자리에서 가능한 몇 번째 숫자인지 계산한다.
그 결과는 inputSequence 배열에 저장된다. 그런 뒤에, (inputSequence[i] - 1) * factorial[N - 1 - i]를 모두 합하면 그 수열이 몇 번 수열인지 알 수 있다.

말로 설명하기에는 조금 복잡하지만, '각 자리의 숫자가 바뀔 때 수열 번호가 얼마나 바뀌는가'가 핵심 포인트이다.
O(n^2)로 풀어서 조마조마 했는데 다행히 통과가 된다. 더 효율적인 방법이 있는지 궁금하다.
 */