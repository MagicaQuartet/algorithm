// Baekjoon Online Judge #1094

#include <cstdio>

using namespace std;

int main() {
	int X, cnt;
	scanf("%d", &X);

	cnt = 0;
	while (X > 0) {
		cnt += X % 2;
		X /= 2;
	}

	printf("%d\n", cnt);
	return 0;
}

/*
X를 이진수로 나타냈을 때 1bit가 몇 개인지 센다.
 */