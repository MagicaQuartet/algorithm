// Baekjoon Online Judge #1931
// (Greedy)

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct meetingcmp {
	bool operator() (pair<int, int> lhs, pair<int, int> rhs) {
		return rhs.second < lhs.second || (rhs.second == lhs.second && rhs.first < lhs.first);
	}
};

int main() {
	int N;
	cin >> N;

	priority_queue<pair<int, int>, vector<pair<int, int>>, meetingcmp> pq;

	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;

		pq.push(make_pair(start, end));
	}

	int t = -1;
	int cnt = 0;

	while (!pq.empty()) {
		pair<int, int> meeting = pq.top();
		pq.pop();

		//cout << ">>> " << meeting.first << " " << meeting.second << endl;

		if (meeting.first < t)
			continue;

		//cout << "****" << endl;

		t = meeting.second;
		cnt++;
	}

	cout << cnt << endl;
	return 0;
}

/*
모든 미팅 시간을 끝나는 시간 순으로 오름차순 정렬한다. 만약 끝나는 시간이 같다면, 시작하는 순으로 오름차순 정렬한다.
시작하는 순은 k n / n n (k<n) 과 같은 경우가 있을 때 중요하다.

정렬을 한 뒤 pq에서 미팅 일정을 하나씩 뽑아내며 그 중 시간이 겹치지 않아 진행 가능한 회의의 수를 센다.
 */