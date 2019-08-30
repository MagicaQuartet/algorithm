#include<cstdio>

using namespace std;

int main() {
	int L, R, sub, cnt, answer;
	scanf("%d %d", &L, &R);
	
	answer = 0;
	cnt = 2;
	sub = (L*R)/100;
	while (sub > 5) {
		answer += sub*cnt;
		sub = (sub*R)/100;
		cnt *= 2;
	}
	
	printf("%d\n", answer);
	return 0;
}