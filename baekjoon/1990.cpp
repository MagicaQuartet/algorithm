// Baekjoon Online Judge #1990
// (Math)

#include <cstdio>
#include <cmath>

using namespace std;

bool check_first_digit(int n) {
	if (n == 5)
		return true;
	else 
		return (n % 10) % 2 == 1;
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
	scanf("%d %d", &a, &b);

	for (int i = a; i <= b && i < 10000000; i++) {
		if (check_first_digit(i) && is_palindrome(i) && is_prime(i))
			printf("%d\n", i);
	}

	printf("-1\n");
	return 0;
}

/* 8자리 이상의 소수 중에는 팰린드롬이 없다는 조건을 걸어주니 통과하기는 했다... */
/* 팰린드롬 찾는 방법을 더 개선시킬 수 있을 것 같다. */