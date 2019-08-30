// Baekjoon Online Judge #13301

#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	if (N == 1)
		printf("%d\n", 4);
	else if (N == 2)
		printf("%d\n", 6);
	else {
		vector<long long> f;
		f.push_back(1);
		f.push_back(1);

		for (int i = 0; i < N-2; i++) {
			f.push_back(f[i] + f[i+1]);
		}

		printf("%lld\n", 2*(f[N-1]+2*f[N-2]+f[N-3]));
	}
	return 0;
}

/*
피보나치
 */