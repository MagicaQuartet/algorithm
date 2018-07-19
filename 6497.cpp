// Baekjoon Online Judge #6497

#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

int main() {
	int m, n, x, y, z, total_sum, mst_sum;
	while (true) {
		scanf("%d %d", &m, &n);

		if (m == 0 && n == 0)
			break;
	
		vector<int> visited;
		vector<vector<pair<int, int>>> city;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
		for (int i = 0; i < m; i++) {
			visited.push_back(0);
			city.push_back(vector<pair<int, int>>());
		}
	
		total_sum = 0;
	
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &x, &y, &z);
	
			city[x].push_back(make_pair(z, y));
			city[y].push_back(make_pair(z, x));
			total_sum += z;
	
			if (x == 0)
				pq.push(make_pair(z, y));
			else if (y == 0)
				pq.push(make_pair(z, x));
		}
	
		visited[0] = 1;
		mst_sum = 0;
	
		while (!pq.empty()) {
			pair<int, int> road = pq.top();
			pq.pop();
	
			if (visited[road.second] == 1)
				continue;
	
			visited[road.second] = 1;
			mst_sum += road.first;
	
			for (vector<pair<int, int>>::iterator it=city[road.second].begin(); it!=city[road.second].end(); ++it) {
				if (visited[it->second] == 1)
					continue;
				pq.push(*it);
			}
		}
	
		printf("%d\n", total_sum-mst_sum);
	}
	return 0;
}

/*
처음에 주어지는 그래프의 모든 edge의 가중치의 합을 구한 뒤 MST를 이루는 edge의 가중치의 합을 빼면 된다.
**테스트 케이스가 여러 개가 주어진다는 점에 유의! 예제 입력만 봐서는 간과하기 쉽다!**
 */