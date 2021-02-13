#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
#define vi vector<int>
int N, M, indegree[32010];
int main() {
  scanf("%d%d", &N, &M);
  vector<vi > graph(N+1, vi());
  memset(indegree, 0, sizeof(indegree));
  for (int i=0; i<M; i++) {
    int A, B;
    scanf("%d%d", &A, &B);
    graph[A].push_back(B);
    indegree[B]++;
  }
  
  priority_queue<int, vi, greater<int> > pq;
  for (int i=1; i<=N; i++) {
    if (indegree[i] == 0) pq.push(i);
  }
  while (!pq.empty()) {
    int problem = pq.top();
    pq.pop();
    printf("%d ", problem);
    for (int nxt: graph[problem]) {
      if (--indegree[nxt] == 0) pq.push(nxt);
    }
  }
  printf("\n");
}