// Baekjoon Online Judge #4485
// (Dijkstra)

#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N;
	int num = 1;

	while (true) {
		queue<int> queue_i;
		queue<int> queue_j;

		cin >> N;
		if (N == 0)
			break;

		int **cave = new int *[N];
		int **cost = new int *[N];
		for (int i = 0; i < N; i++) {
			cave[i] = new int[N];
			cost[i] = new int[N];
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int temp;
				cin >> temp;
				cave[i][j] = temp;
				cost[i][j] = -1;
			}
		}

		cost[0][0] = cave[0][0];

		cost[1][0] = cost[0][0] + cave[1][0];
		cost[0][1] = cost[0][0] + cave[0][1];

		queue_i.push(1);
		queue_j.push(0);

		queue_i.push(0);
		queue_j.push(1);

		while (!queue_i.empty()) {
			int i = queue_i.front(), j = queue_j.front();
//			cout << i << " " << j << endl;
			queue_i.pop();
			queue_j.pop();

			if (i+1 < N) {
//				cout << ">>>" << cost[i+1][j] << "||" << cost[i][j] << " " << cave[i+1][j] << endl;
				if (cost[i+1][j] == -1 || cost[i+1][j] > cost[i][j] + cave[i+1][j]) {
					cost[i+1][j] = cost[i][j] + cave[i+1][j];

					queue_i.push(i+1);
					queue_j.push(j);
				}
			}
			if (j+1 < N) {
//				cout << ">>>" << cost[i][j+1] << "||" << cost[i][j] << " " << cave[i][j+1] << endl;
				if (cost[i][j+1] == -1 || cost[i][j+1] > cost[i][j] + cave[i][j+1]) {
					cost[i][j+1] = cost[i][j] + cave[i][j+1];

					queue_i.push(i);
					queue_j.push(j+1);
				}
			}
			if (i-1 >= 0) {
//				cout << ">>>" << cost[i-1][j] << "||" << cost[i][j] << " " << cave[i-1][j] << endl;
				if (cost[i-1][j] == -1 || cost[i-1][j] > cost[i][j] + cave[i-1][j]) {
					cost[i-1][j] = cost[i][j] + cave[i-1][j];


					queue_i.push(i-1);
					queue_j.push(j);
				}
			}
			if (j-1 >= 0) {
//				cout << ">>>" << cost[i][j-1] << "||" << cost[i][j] << " " << cave[i][j-1] << endl;
				if (cost[i][j-1] == -1 || cost[i][j-1] > cost[i][j] + cave[i][j-1]) {
					cost[i][j-1] = cost[i][j] + cave[i][j-1];

					queue_i.push(i);
					queue_j.push(j-1);
				}
			}
		}

		cout << "Problem " << num << ": " << cost[N-1][N-1] << endl;
		num++;
	}

	return 0;
}

/*
입력 행렬 중 (0, 0)의 값을 시작으로 하고 나머지 위치의 값들을 그 지점으로 가는 edge의 value로 생각을 하여
다익스트라 알고리즘을 적용할 수 있다.
단 이 코드는 다익스트라 알고리즘을 잘 몰라서 효율적으로 구현한 건 아닌 것 같다.
 */