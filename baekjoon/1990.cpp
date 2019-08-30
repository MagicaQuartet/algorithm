// Baekjoon Online Judge #1990
// (Math)

#include <iostream>
#include <cmath>

using namespace std;

bool check_first_digit(int n) {
	if (n == 5)
		return true;
	else 
		return n % 10 == 1 || n % 10 == 3 || n % 10 == 7 || n % 10 == 9 ? true : false;
}

bool is_prime(int n) {
	bool isPrime = true;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			isPrime = false;
			break;
		}
	}

	return isPrime;
}

bool is_palindrome(int n) {
	bool isPalindrome = true;
	int digit_cnt = 1;
	int temp = 10;
	int *digits;

	while (n >= temp) {
		digit_cnt++;
		temp *= 10;
	}

	digits = new int[digit_cnt];

	for (int i = 0; i < digit_cnt; i++) {
		digits[i] = n % 10;
		n /= 10;
	}

	for (int i = 0; i < digit_cnt / 2; i++) {
		if (digits[i] != digits[digit_cnt - i - 1]) {
			isPalindrome = false;
			break;
		}
	}

	delete digits;

	return isPalindrome;
}

int main() {
	int a, b;
	cin >> a >> b;

	for (int i = a; i <= b; i++) {
		if (check_first_digit(i) && is_palindrome(i) && is_prime(i))
			cout << i << endl;
	}

	cout << - 1 << endl;
	return 0;
}

/*
그냥 모든 수를 다 돌면서 팰린드롬이면서 소수인 수를 찾으려니까 시간 초과가 된다.
10 이상의 소수는 1의 자리 수가 모두 1, 3, 7, 9 중 하나라고 생각하여 이 조건도 걸어주었더니
통과가 되었다. 시간 복잡도는 똑같을텐데..
 */