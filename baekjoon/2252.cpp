#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int indegree[32010];
int outdegree[32010];
int visited[32010];

int main() {
  scanf("%d %d", &N, &M);
  memset(indegree, 0, sizeof(indegree));
  memset(outdegree, 0, sizeof(outdegree));
  memset(visited, 0, sizeof(visited));
  vector<vector<int> > graph;
  graph.reserve(N+1);

  for (int i=0; i<=N; i++) {
    graph.push_back(vector<int>());
  }

  for (int i=0; i<M; i++) {
    int A, B;
    scanf("%d %d", &A, &B);
    indegree[B]++;
    outdegree[A]++;
    graph[A].push_back(B);
  }

  queue<int> q;
  for (int i=1; i<=N; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  while(!q.empty()) {
    int student = q.front();
    q.pop();
    visited[student] = 1;
    printf("%d ", student);

    for (auto i: graph[student]) {
      indegree[i]--;

      if (indegree[i] == 0) {
        q.push(i);
      }
    }
  }

  for (int i=1; i<=N; i++) {
    if (visited[i] == 0) {
      printf("%d ", i);
    }
  }
  printf("\n");
}