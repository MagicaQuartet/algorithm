// Baekjoon Online Judge #1932
// (Dynamic Programming)

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, maxn, idx, size = 0;
	cin >> n;
	maxn = n;

	for(int i = 1; i <= n; i++)
		size += i;

	int* intTriangle = new int[size];
	int* maxFromBottom = new int[size];

	for (int i = 0; i < size; i++) {
		int temp;
		cin >> temp;
		intTriangle[i] = temp;
	}

	idx = size - n;
	for (int i = size - 1; i >= 0; i--) {
		if (n == maxn) {
			maxFromBottom[i] = intTriangle[i];
		}
		else {
			maxFromBottom[i] = intTriangle[i] + max(maxFromBottom[i+n], maxFromBottom[i+n+1]);
		}

		if (i == idx) {
			n--;
			idx = idx - n;
		}
	}

	cout << maxFromBottom[0];
	return 0;
}

/*
삼각형의 맨 아래 층부터 시작해서, 각 자리에 이르는 경로상의 숫자의 합 중 가장 큰 값을 저장한다.
연산이 끝나면 삼각형의 꼭대기까지 이르는 경로상의 숫자의 합 중 가장 큰 값을 알 수 있다.
 */