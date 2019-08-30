// Baekjoon Online Judge #1026

#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int N, input, result;

	scanf("%d", &N);

	vector<int> A;
	vector<int> B;

	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		A.push_back(input);
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		B.push_back(input);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	result = 0;
	for (int i = 0; i < N; i++)
		result += A[i] * B[N-i-1];

	printf("%d\n", result);
	return 0;
}

/*
A는 오름차순 정렬, B는 내림차순 정렬 (혹은 반대로) 하여 index가 같은 원소끼리 곱하여 모두 더하면 된다.
근데 아직 C++에서 Compare가 어떤건지 잘 모르겠다. cplusplus의 sort 예시를 참고하여 오름차순 내림차순 함수를 따로 만들고
넣어봤는데 런타임 에러가 나더라. 이 코드는 sort하는 부분만 달라진 코드이다.
 */