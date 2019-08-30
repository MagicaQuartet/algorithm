// Baekjoon Online Judge #4388

#include <cstdio>

using namespace std;

int main() {
	long long lhs, rhs;
	while (true) {
		scanf("%lld %lld", &lhs, &rhs);

		if (lhs == 0 && rhs == 0)
			break;

		int carry = 0;
		int carry_cnt = 0;

		while (lhs > 0 || rhs > 0) {
			int l, r;
			l = lhs%10;
			r = rhs%10;

			if (l+r+carry >= 10) {
				carry = 1;
				carry_cnt++;
			}

			lhs /= 10;
			rhs /= 10;
		}

		printf("%d\n", carry_cnt);
	}

	return 0;
}

/*
1의 자리 수부터 시작해서, 두 숫자의 각 자리 수와 carry(0으로 시작)을 합한 결과가 10 이상인지 확인한다.
10 이상이라면, 다음 자리 수의 덧셈에서 carry = 1로 한다.

***10 미만일 때 carry를 다시 0으로 해주어야 하는 것으로 보이나 그렇게 구현하지 않아도 통과를 한다. 예를 들어, 405 505는 2로 출력이 된다.***
 */