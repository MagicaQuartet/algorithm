// Baekjoon Online Judge #2157
// (Dynamic Programming)

#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	vector<map<int, int>> max_point;
	vector<map<int, int>> point;

	for (int i = 0; i < N; i++) {
		max_point.push_back(map<int, int>());
		point.push_back(map<int, int>());
	}

	for (int i = 0; i < K; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a > b)
			continue;

		if (point[a-1].find(b) == point[a-1].end())
			point[a-1].insert(make_pair(b, c));
		else {
			if (point[a-1][b] < c)
				point[a-1][b] = c;
		}
	}

	max_point[0].insert(make_pair(1, 0));

	for (int i = 0; i < N-1; i++) {
		for (map<int, int>::iterator it=point[i].begin(); it!=point[i].end(); ++it) {
			int dest = it->first;
			int p = it->second;

			for (map<int, int>::iterator _it=max_point[i].begin(); _it!=max_point[i].end(); ++_it) {
				int cnt = _it->first;
				int cur_p = _it->second;

				if (cnt+1 <= M) {
					if (max_point[dest-1].find(cnt+1) != max_point[dest-1].end()) {
						if (max_point[dest-1][cnt+1] < cur_p + p)
							max_point[dest-1][cnt+1] = cur_p + p;
					}
					else
						max_point[dest-1].insert(make_pair(cnt+1, cur_p + p));
				}
			}
		}
	}

	int result = 0;
	for (map<int, int>::iterator it=max_point[N-1].begin(); it!=max_point[N-1].end(); ++it) {
		if (it->second > result)
			result = it->second;
	}

	cout << result << endl;
}

/*
모든 노선의 정보를 입력받은 뒤, 1번 지역부터 시작해서 각 지역으로 갈 때 거쳐가는 지역의 수와 기내식 점수의 합의 최댓값을 DP를 이용해 구한다.
서쪽에서 동쪽으로 가는 노선은 필요 없으므로 아예 입력받지 않는다.
 */