#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef vector<int> vi;
int N, M, K, X, A, B;

int main() {
  scanf("%d %d %d %d", &N, &M, &K, &X);
  queue<int> q;
  vector<vi > graph;
  int d[300010], ans;
  memset(d, -1, sizeof(d));
  for (int i=0; i<N; i++) {
    graph.push_back(vi());
  }
  for (int i=0; i<M; i++) {
    scanf("%d %d", &A, &B);
    graph[A-1].push_back(B-1);
  }

  ans = 0;
  for (int node: graph[X-1]) {
    q.push(node);
    d[node] = 1;
  }
  d[X-1] = 0;

  while(!q.empty()) {
    int node = q.front();
    q.pop();
    if (d[node] == K) {
      ans++;
    }
    for (int nextNode: graph[node]) {
      if (d[nextNode] != -1 && d[nextNode] <= d[node] + 1) {
        continue;
      }
      d[nextNode] = d[node] + 1;
      q.push(nextNode);
    }
  }
  
  if (ans == 0) {
    printf("-1\n");
  }
  else {
    for (int i=0; i<N; i++) {
      if (d[i] == K) {
        printf("%d\n", i+1);
      }
    }
  }
}
