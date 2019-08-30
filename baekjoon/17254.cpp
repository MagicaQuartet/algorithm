#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
#include<functional>

using namespace std;

int main() {
	int N, M;
	int keyboard, time;
	char c;
	priority_queue<pair<pair<int, int>, char>, vector<pair<pair<int, int>, char>>, greater<pair<pair<int, int>, char>>> pq;
	scanf("%d %d", &N, &M);
	
	while(M--) {
		scanf("%d %d %c", &keyboard, &time, &c);
		pq.push(make_pair(make_pair(time, keyboard), c));
	}
	
	while(!pq.empty()) {
		printf("%c",pq.top().second);
		pq.pop();
	}
	printf("\n");
	return 0;
}

/* pq를 이용해 1. 시간 2. 키보드 번호 순으로 오름차수 정렬해서 대충 하면 된다 */