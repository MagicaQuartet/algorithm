// Baekjoon Online Judge #1697
// (Backtracking, BFS)

#include <iostream>
#include <set>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	if (N >= K)
		cout << N-K << endl;
	else {
		int t = 0;
		set<int> used_position;
		set<int> position;
		set<int> new_position;
		position.insert(N);
		used_position.insert(N);
		
		while (true) {
			if (position.find(K) != position.end())
				break;

			for (set<int>::iterator it=position.begin(); it!=position.end(); ++it) {
				if (*it > 0 && *it < 2/3.0 * K && used_position.find((*it)*2) == used_position.end())
					new_position.insert((*it)*2);
				if (*it > 2 && used_position.find((*it)-1) == used_position.end())
					new_position.insert((*it)-1);
				if (*it < 100000 && used_position.find((*it)+1) == used_position.end())
					new_position.insert((*it)+1);
			}

			position.clear();
			position.insert(new_position.begin(), new_position.end());
			used_position.insert(new_position.begin(), new_position.end());
			new_position.clear();
			t++;
		}

		cout << t << endl;
	}

	return 0;
}

/*
BFS로 각 timestamp에 도달 가능한 위치를 구하고, 그 중에 K가 있으면 탐색을 중단하도록 하였다.
그냥 하면 시간 초과나 메모리 초과가 뜨길래 비효율적인 위치나 이미 방문한 위치를 거르는 최적화를
여러 차례 시도한 끝에 메모리 초과에서 벗어났다...
 */