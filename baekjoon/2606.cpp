#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
#define pii pair<int, int>
#define INF 987654321
using namespace std;

int N, M, a, b, ans;

int main() {
  vector<vector<int> > graph;
  vector<int> distance;
  priority_queue<pii > pq;
  
  scanf("%d %d", &N, &M);
  
  for (int i=0; i<N; i++) {
    distance.push_back(INF);
    for (int j=0; j<N; j++) {
      graph.push_back(vector<int>(N, 0));
    }
  }
  
  for (int i=0; i<M; i++) {
    scanf("%d %d", &a, &b);
    
    graph[a-1][b-1] = 1;
    graph[b-1][a-1] = 1;
  }
  
  for (int i=1; i<N; i++) {
    if (graph[0][i] == 1) {
      pq.push(make_pair(0, i));
    }
  }
  
  ans = 0;
  
  while (!pq.empty()) {
    int src = pq.top().first;
    int dst = pq.top().second;
    pq.pop();
    
    if (distance[dst] != INF) {
      continue;
    }
    
    distance[dst] = distance[src] + 1;
    ans += 1;
    
    for (int i=1; i<N; i++) {
      if (graph[dst][i] == 1 && distance[i] == INF) {
        pq.push(make_pair(dst, i));
      }
    }
  }
  
  printf("%d\n", ans);
}