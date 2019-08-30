// Baekjoon Online Judge #1976

#include <cstdio>
#include <vector>

using namespace std;

int find(vector<int> &parent, int num) {
	int n = num;
	while (n != parent[n]) {
		n = parent[n];
		if (n == -1)
			break;
	}
	return n;
}

int main() {
	int N, M, temp;
	int find_i, find_j, head;
	scanf("%d %d", &N, &M);

	vector<int> parent;
	for (int i = 0; i < N; i++)
		parent.push_back(i);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &temp);
			if (j <= i)
				continue;

			if (temp == 1) {
				find_i = find(parent, i);
				find_j = find(parent, j);
				if (find_i != find_j)
					parent[find_j] = find_i;
			}
		}
	}

	head = -1;
	for (int i = 0; i < M; i++) {
		scanf("%d", &temp);

		if (head == -1)
			head = find(parent, temp);
		else if (head != find(parent, temp)) {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
}

/*
Union-find를 이용해 여행 계획에 포함된 도시들이 서로 연결되어 있는 지를 확인한다.
 */