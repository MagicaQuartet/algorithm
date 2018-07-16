// Baekjoon Online Judge #12893

#include <cstdio>
#include <vector>

using namespace std;

int find(vector<int> &enemy, int idx) {
	int root;
	root = idx;
	while (true) {
		if (root != enemy[enemy[root]]) {
			root = enemy[enemy[root]];
		}
		else
			break;
	}

	return root;
}

int main() {
	int N, M;
	int p, q;
	int result = 1;
	scanf("%d %d", &N, &M);

	vector<int> enemy;

	for (int i = 0; i < N; i++) {
		enemy.push_back(-1);
	}

	while (M--) {
		scanf("%d %d", &p, &q);
		p--;
		q--;

		if (result == 0)
			continue;

		if (enemy[p] == -1 && enemy[q] == -1) {
			enemy[p] = q;
			enemy[q] = p;
		}
		else if (enemy[p] == -1) {
			enemy[p] = find(enemy, q);
		}
		else if (enemy[q] == -1) {
			enemy[q] = find(enemy, p);
		}
		else {
			if (find(enemy, p) == find(enemy, q)) {
				result = 0;
			}
			else {
				enemy[p] = find(enemy, q);
				enemy[q] = find(enemy, p);
			}
		}
	}

	printf("%d\n", result);
	return 0;
}

/*
Union-find...와는 다르긴 하지만 암튼 그것에서 착안하였다. 전혀 연관성이 없는 것일 수도 있지만 암튼.

union-find에서와 마찬가지로 어떤 집단(여기서는, 서로 친구인 집단)과 그 집단을 대표하는 대표값이 있도록 할 것이다.
기본적으로, i와 j가 적대 관계일 경우 enemy[i] = j, enemy[j] = 1이다.
이 때, enemy[k]의 값은 항상 어떤 우호 집단의 대표값만이 있도록 한다.
이 조건을 유지하면, p, q가 입력되었고 p, q 모두 어떤 우호 집단에 속해있다면, p와 q의 우호 집단의 대표값이 같을 경우에만
이론이 성립하지 않는다. 이외의 경우에는 이론에 어긋나지 않는 경우이다.
 */