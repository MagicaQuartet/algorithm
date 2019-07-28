#include <cstdio>

using namespace std;

int main() {
	long long n, q, r;
	int answer;
	scanf("%lld", &n);
	n -= 1;
	
	q = n / 4;
	r = n % 4;
	
	switch (r) {
		case 0:
			answer = (q%2==0) ? 1 : 5;
			break;
		case 1:
			answer = (q%2==0) ? 2 : 4;
			break;
		case 2:
			answer = 3;
			break;
		case 3:
			answer = (q%2==0) ? 4 : 2;
			break;
	}
	
	printf("%d\n", answer);
	return 0;
}

/* 규칙성 찾기 */