// Baekjoon Online Judge #1700
// (Greedy)

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> busy;
	set<int> busySet;
	vector<int> useSequence;
	vector<vector<int>> useIdx;
	map<int, int> nextIdx;

	for (int i = 0; i < K; i++) {
		busy.push_back(0);
		useIdx.push_back(vector<int>());
	}

	for (int i = 0; i < K; i++) {
		int temp;
		cin >> temp;
		useSequence.push_back(temp);
		useIdx[temp-1].push_back(i);
	}

	int cnt = 0;
	int evicted_cnt = 0;

	for (int i = 0; i < K; i++) {
		if (busy[useSequence[i]-1] == 1) {
			useIdx[useSequence[i]-1].erase(useIdx[useSequence[i]-1].begin());
			if (!useIdx[useSequence[i]-1].empty())
				nextIdx[useSequence[i]-1] = useIdx[useSequence[i]-1].front();
			else
				nextIdx[useSequence[i]-1] = K;
			continue;
		}

		if (cnt < N) {
			useIdx[useSequence[i]-1].erase(useIdx[useSequence[i]-1].begin());
			if (!useIdx[useSequence[i]-1].empty())
				nextIdx[useSequence[i]-1] = useIdx[useSequence[i]-1].front();
			else
				nextIdx[useSequence[i]-1] = K;
			busySet.insert(useSequence[i]);
			busy[useSequence[i]-1] = 1;
			cnt++;
		}
		else {
			int evicted = 0, max_value = 0;
			for (set<int>::iterator it=busySet.begin(); it!=busySet.end(); ++it) {
				if (max_value < nextIdx[(*it) - 1]) {
					evicted = *it;
					max_value = nextIdx[(*it) - 1];
				}
			}
			busy[evicted-1] = 0;
			busySet.erase(evicted);

			useIdx[useSequence[i]-1].erase(useIdx[useSequence[i]-1].begin());
			if (!useIdx[useSequence[i]-1].empty())
				nextIdx[useSequence[i]-1] = useIdx[useSequence[i]-1].front();
			else
				nextIdx[useSequence[i]-1] = K;
			busySet.insert(useSequence[i]);
			busy[useSequence[i]-1] = 1;
			evicted_cnt++;
		}
	}

	cout << evicted_cnt << endl;
	return 0;
}

/*
멀티탭이 모두 사용 중일 경우, 다음 번에 쓰이는 시간이 가장 늦은 기기를 뽑는다.
 */
