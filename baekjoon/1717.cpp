// Baekjoon Online Judge #1717

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
	int n, m, q, a, b;
	int find_a, find_b;
	scanf("%d %d", &n, &m);

	vector<int> parent;

	for (int i = 0; i < n+1; i++)
		parent.push_back(i);

	while (m--) {
		scanf("%d %d %d", &q, &a, &b);
		if (q) {
			find_a = find(parent, a);
			find_b = find(parent, b);
			if (find_a == find_b)
				printf("YES\n");
			else
				printf("NO\n");

			parent[a] = find_a;
			parent[b] = find_b;
		}
		else {
			find_a = find(parent, a);
			find_b = find(parent, b);
			if (find_a != find_b)
				parent[find_b] = find_a;
		}
	}

	return 0;
}

/*
Union-find를 이용하는 문제. 단, 단순 구현으로는 시간 초과로 통과하지 못했다.
여기서는 a, b에 대해 find를 한 뒤 a와 b의 parent를 a와 b의 ancestor로 바꾸는 최적화를 이용하였다.
 */