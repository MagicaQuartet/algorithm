#include<cstdio>
#include<queue>

using namespace std;

int main() {
	int A, B, C;
	priority_queue<int> pq;
	scanf("%d%d%d", &A, &B, &C);
	
	pq.push(A);
	pq.push(B);
	pq.push(C);
	
	pq.pop();
	printf("%d\n", pq.top());
	return 0;
}