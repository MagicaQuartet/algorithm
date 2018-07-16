// Baekjoon Online Judge #1826
// (Greedy)

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>

using namespace std;

int main() {
	int N, dist, curOil, curPos, cnt;
	cin >> N;

	vector<pair<int, int>> oil;
	priority_queue<int> pq;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		oil.push_back(make_pair(a, b));
	}

	cin >> dist >> curOil;
	oil.push_back(make_pair(dist, 0));
	curPos = 0;
	cnt = 0;

	sort(oil.begin(), oil.end());

	for (int i = 0; i < N+1; i++) {
		if (oil[i].first > dist)
			break;

		if (oil[i].first - curPos <= curOil) {
			curOil -= oil[i].first - curPos;
			curPos = oil[i].first;
			pq.push(oil[i].second);
		}
		else {
			if (pq.empty()) {
				cnt = -1;
				break;
			}
			else {
				while (curOil < oil[i].first - curPos) {
					if (pq.empty()) {
						cnt = -1;
						break;
					}
					curOil += pq.top();
					pq.pop();
					cnt++;
				}

				if (cnt == -1)
					break;

				curOil -= oil[i].first - curPos;
				curPos = oil[i].first;
				pq.push(oil[i].second);
			}
		}
	}

	cout << cnt << endl;
	return 0;
}

/*
가지고 있는 기름으로 갈 수 있는 주유소까지 간다. 이 때, 지나치는 주유소들마다 그 곳에서 채울 수 있는
기름의 양을 pq에 저장한다.
더이상 다음 주유소나 마을로 갈 수 없을 경우, 갈 수 있을 때까지 pq에서 값을 빼내 기름을 채운 것으로 간주한다.
마을에 도착할 때까지 pq에서 값을 빼내는 횟수를 출력한다.
 */