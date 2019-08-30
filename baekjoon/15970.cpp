// Baekjoon Online Judge #15970

#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	int N, pos, color, curColor, prev, result;
	scanf("%d", &N);

	vector<pair<int, int>> point;

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &pos, &color);
		point.push_back(make_pair(color, pos));
	}

	sort(point.begin(), point.end());

	curColor = point[0].first;
	vector<int> diff;
	result = 0;
	for (int i = 1; i < N; i++) {
		if (point[i].first != curColor) {
			prev = diff.front();
			result += diff.front() + diff.back();
			for (vector<int>::iterator it=diff.begin()+1; it!=diff.end(); ++it) {
				result += *it < prev ? *it : prev;
				prev = *it;
			}
			diff.clear();
			curColor = point[i].first;
		}
		else {
			diff.push_back(point[i].second - point[i-1].second);
		}
	}
	prev = diff.front();
	result += diff.front() + diff.back();
	for (vector<int>::iterator it=diff.begin()+1; it!=diff.end(); ++it) {
		result += *it < prev ? *it : prev;
		prev = *it;
	}

	printf("%d\n", result);
	return 0;
}