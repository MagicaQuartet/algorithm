// Baekjoon Online Judge #2629
// (Backtracking, Dynamic Programming)

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int n_weight, n_ball;
	cin >> n_weight;

	vector<int> weight;
	set<int> all_weights;
	all_weights.insert(0);
	for (int i = 0; i < n_weight; i++) {
		int temp;
		cin >> temp;
		set<int> new_weights;

		weight.push_back(temp);
		for (set<int>::iterator it=all_weights.begin(); it!=all_weights.end(); ++it) {
			if ((*it)-temp > 0)
				new_weights.insert((*it)-temp);
			else
				new_weights.insert(temp-(*it));
			new_weights.insert((*it)+temp);
		}

		all_weights.insert(new_weights.begin(), new_weights.end());
	}

	cin >> n_ball;

	vector<int> ball;
	for (int i = 0; i < n_ball; i++) {
		int temp;
		cin >> temp;
		ball.push_back(temp);
	}

	for (int i = 0; i < n_ball; i++)
		cout << (all_weights.find(ball[i])!=all_weights.end() ? "Y" : "N") << endl;

	return 0;
}

/*
추를 다 입력받은 뒤에 각각의 추를 오른쪽에 두거나 왼쪽에 두거나 쓰지 않거나 하는 세 가지 선택지를 모두 택하며 구슬과 같은 무게를 만들 수 있는 지를
재귀 함수로 확인하려 했더니 보기 좋게 시간 초과가 되었다.

추를 입력받으며 어떤 추를 입력받은 시점까지 만들 수 있는 모든 무게를 저장하고, 그 뒤에 그 set에 저울에 올려놓을 구슬의 무게가 있는지 확인하는
방식으로 바꾸어서 통과할 수 있었다. 태그를 보니 DP도 있던데 생각해보니 이 부분이 DP인 것 같다.
 */