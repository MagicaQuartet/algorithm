// Baekjoon Online Judge #11727
// (Dynamic Programming)

#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int *tiles = new int[n];

	if (n == 1)
		cout << 1 << endl;
	else {
		tiles[0] = 1;
		tiles[1] = 3;

		for (int i = 2; i < n; i++)
			tiles[i] = (tiles[i-1] + tiles[i-2] * 2) % 10007;

		cout << tiles[n-1] << endl;
	}

	return 0;
}

/*
11726번과 유사하다.
 */