#include<cstdio>

using namespace std;

int answer(const int p, int q, int r) {
	if (q == 0)
		return r;
	
	return answer(p, q-1, (r*p)%10);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int a, b, ret;
		scanf("%d %d", &a, &b);
		ret = answer(a, b, 1);
		printf("%d\n", ret == 0 ? 10 : ret);
	}
	return 0;
}

/* O(q) 재귀로 해도 되긴 하는데 그거보다 더 똑똑한 방법이 있다. r = answer(p, q/2); return r*r*(q%2?x:1)%10;*/