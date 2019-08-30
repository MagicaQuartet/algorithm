// Baekjoon Online Judge #11726
// (Dynamic Programing)

#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	long long *tiles = new long long[n];
	
	if (n == 1)
		cout << 1 << endl;
	else {
		tiles[0] = 1;
		tiles[1] = 2;

		for (int i = 2; i < n; i++)
			tiles[i] = (tiles[i-1] + tiles[i-2]) % 10007;

		cout << tiles[n-1] << endl;
	}

	return 0;
}

/*
2*n의 크기를 덮는 경우는 2*(n-2)의 크기를 덮는 경우에서 가로로 2개 배치하거나
2*(n-1)의 크기를 덮는 경우에서 세로로 1개 배치하면 된다.
이 때, 2*(n-2)의 크기를 덮는 경우에서 세로로 2개를 배치는 것은 중복이 되기 때문에 제외한다.
 */