// Baekjoon Online Judge #1756
// (Implementation)

#include <iostream>

using namespace std;

int main() {
	int D, N;
	int oven_idx, pizza_idx;
	bool above_pizza = true;
	cin >> D >> N;

	int *oven_radius = new int[D];
	int *pizza_radius = new int[N];
	int *pizza_limit = new int[N];

	for (int i = 0; i < D; i++) {
		int temp;
		cin >> temp;
		if (i > 0 && oven_radius[i-1] < temp)
			oven_radius[i] = oven_radius[i-1];
		else
			oven_radius[i] = temp;
	}

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		pizza_radius[i] = temp;
	}

	oven_idx = D-1;

	for (int i = 0; i < D; i++) {
		if (oven_radius[i] < pizza_radius[0]) {
			oven_idx = i - 1;
			break;
		}
	}

	pizza_idx = 0;

	while (oven_idx >= 0 && pizza_idx < N) {
		if (oven_radius[oven_idx] >= pizza_radius[pizza_idx]) {
			if (!above_pizza && oven_radius[oven_idx + 1] >= pizza_radius[pizza_idx]) {
				oven_idx--;
			}
			else {
				oven_idx--;
				pizza_idx++;
				above_pizza = true;
			}
		}
		else {
			oven_idx--;
			above_pizza = false;
		}
	}

	if (pizza_idx != N) {
		cout << 0 << endl;
	}
	else {
		cout << oven_idx+2 << endl;
	}

	return 0;
}

/*
피자와 피자 사이에 빈 공간이 있을 수 있기 때문에 각 피자가 최대로 얼마나 깊게 내려갈 수 있는 지를
알아야 한다. 그러나 이것을 O(nm)으로 하면 시간 초과가 된다.

오븐의 위쪽부터 아래쪽으로 순차적으로 이동할 때, 어차피 어떤 깊이에 내려올 수 있는 피자는
지나온 깊이의 오븐 반지름의 최솟값보다 반지름이 같거나 작은 피자이다. 그러므로 처음에 오븐의 깊이 별 반지름을 입력받을 때
그대로 모두 받지 않고 이전 깊이의 반지름보다 입력 값이 같거나 작을 때만 그 값을 반지름으로 하고, 그렇지 않은 경우
이전 깊이의 반지름을 저장한다.

이렇게 하면, 0번째 피자가 어느 깊이까지 들어가는지만을 알면 된다. 이것을 알아내는 데에 O(n)이 걸리고, 이후 각 피자가 들어갈 깊이를
순차적으로 알아내는 것은 O(n+m)이다.
 */