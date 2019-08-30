// Baekjoon Online Judge #2358
// (Math)

#include <iostream>
#include <set>

using namespace std;

int main() {
	int n;
	cin >> n;

	set<int> x_all_set, y_all_set, x_valid_set, y_valid_set;

	for (int i = 0; i < n; i++) {
		int x, y, prev_length;
		cin >> x >> y;

		prev_length = x_all_set.size();
		x_all_set.insert(x);
		if (prev_length == x_all_set.size())
			x_valid_set.insert(x);

		prev_length = y_all_set.size();
		y_all_set.insert(y);
		if (prev_length == y_all_set.size())
			y_valid_set.insert(y);
	}

	cout << x_valid_set.size() + y_valid_set.size() << endl;
	return 0;
}

/*
2번 이상 등장하는 x 좌표와 y 좌표의 수를 세서 더하면 된다.
input을 모두 받고 정렬을 한 뒤 걸러낼 수 있긴 할텐데 직접하기는 귀찮아서
STL로 제공되는 set을 사용하여 이미 등장한 좌표인지 아닌지 확인하였다.
같은 점이 2번 이상 입력되는 경우도 함께 처리할 수 있다.
 */