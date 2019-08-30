// Baekjoon Online Judge #15953

#include <cstdio>

using namespace std;

int main() {
	int T, a, b, total;
	scanf("%d", &T);

	while (T--) {
		total = 0;
		scanf("%d %d", &a, &b);

		if (a != 0) {
			if (a <= 1)
				total += 5000000;
			else if (a <= 3)
				total += 3000000;
			else if (a <= 6)
				total += 2000000;
			else if (a <= 10)
				total += 500000;
			else if (a <= 15)
				total += 300000;
			else if (a <= 21)
				total += 100000;
		}

		if (b != 0) {
			if (b <= 1)
				total += 5120000;
			else if (b <= 3)
				total += 2560000;
			else if (b <= 7)
				total += 1280000;
			else if (b <= 15)
				total += 640000;
			else if (b <= 31)
				total += 320000;
		}

		printf("%d\n", total);
	}

	return 0;
}

/*
그냥 적당히 하드코딩 한다
 */