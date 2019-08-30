// Baekjoon Online Judge #1037

#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int N, input;
	scanf("%d", &N);

	vector<int> num;
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		num.push_back(input);
	}

	sort(num.begin(), num.end());
	printf("%d\n", num[0]*num[N-1]);

	return 0;
}

/*
진짜 약수들을 오름/내림차순으로 정렬해서 가장 앞에 나오는 약수와 가장 뒤에 나오는 약수를 곱하면 된다.
 */