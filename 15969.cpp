// Baekjoon Online Judge #15969

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, temp;
	scanf("%d", &N);

	vector<int> grade;

	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		grade.push_back(temp);
	}

	sort(grade.begin(), grade.end());
	printf("%d\n", grade[N-1] - grade[0]);
	return 0;
}