// Baekjoon Online Judge #14954
// (Daejeon Regional)

#include <iostream>
#include <set>

using namespace std;

long long func(long long n) {
	long long sum = 0;

	while (n > 0) {
		int remainder = n % 10;
		sum += remainder*remainder;
		n /= 10;
	}

	return sum;
}

int main() {
	long long n;
	cin >> n;

	set<int> func_results;
	long long func_result = n;

	while (true) {
		if (func_result == 1) {
			cout << "HAPPY" << endl;
			break;
		}
		else if (func_results.find(func_result) != func_results.end()) {
			cout << "UNHAPPY" << endl;
			break;
		}
		else {
			func_results.insert(func_result);
			func_result = func(func_result);
		}
	}

	return 0;
}

/*
입력을 받고 그 수의 각 자리 수를 제곱하여 더한다.
결과가 1이면 HAPPY를 출력하고, 그렇지 않으면 그 결과를 set에 저장한 뒤 다시 그 결과값의 각 자리수를 제곱하여 더한다.
결과가 1이 나올 떄까지 반복하되, set에 이미 있는 수가 다시 결과로 나오면 UNHAPPY를 출력하고 끝낸다.
 */