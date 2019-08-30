// Baekjoon Online Judge #15971

#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

int main() {
	int N, robot1, robot2, src, dst, length, max_path, step;
	scanf("%d %d %d", &N, &robot1, &robot2);

	vector<vector<pair<int, int>>> cave;
	vector<int> d;
	vector<int> parent;

	for (int i = 0; i < N; i++) {
		cave.push_back(vector<pair<int, int>>());
		d.push_back(-1);
		parent.push_back(-1);
	}

	for (int i = 0; i < N-1; i++) {
		scanf("%d %d %d", &src, &dst, &length);
		cave[src-1].push_back(make_pair(length, dst-1));
		cave[dst-1].push_back(make_pair(length, src-1));
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, robot1-1));

	while (!pq.empty()) {
		int len = pq.top().first;
		int pos = pq.top().second;
		pq.pop();

		if (d[pos] > len)
			continue;

		d[pos] = len;

		for (vector<pair<int, int>>::iterator it=cave[pos].begin(); it!=cave[pos].end(); ++it) {
			pair<int, int> next = *it;
			if (d[next.second] != -1)
				continue;
			else {
				pq.push(make_pair(next.first+len, next.second));
				parent[next.second] = pos;
			}
		}
	}

	step = robot2-1;
	max_path = 0;
	while (parent[step] != -1) {
		int diff = d[step] - d[parent[step]];
		if (max_path < diff)
			max_path = diff;
		step = parent[step];
	}

	printf("%d\n", d[robot2-1] - max_path);
}