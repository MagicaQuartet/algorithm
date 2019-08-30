#include<cstdio>

using namespace std;

int checkBase(int N) {
	while (N > 0) {
		if (N%3 == 2) {
			return 0;
		}
		N /= 3;
	}
	return 1;
}

int main() {
	int N;
	scanf("%d", &N);
	if (N != 0 && checkBase(N)) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	return 0;
}

/* 0도 입력 가능~~~~ */