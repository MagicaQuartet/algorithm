#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define vi vector<int>
int N, M, indegree[1010];
int main() {
  scanf("%d %d", &N, &M);
  vi ans;
  ans.reserve(N);
  vector<vi > graph(N+1, vi());
  for (int i=0; i<M; i++) {
    int cnt, num, prevNum;
    scanf("%d", &cnt);
    prevNum = -1;
    for (int j=0; j<cnt; j++) {
      scanf("%d", &num);
      if (prevNum != -1) {
        graph[prevNum].push_back(num);
        indegree[num]++;
      }
      prevNum = num;
    }
  }

  queue<int> q;
  for (int i=1; i<=N; i++) {
    if (indegree[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    int top = q.front();
    q.pop();
    ans.push_back(top);
    for (int nxt: graph[top]) {
      indegree[nxt]--;
      if (indegree[nxt] == 0) q.push(nxt);
    }
  }

  if (ans.size() == N) {
    for (int num: ans) {
      printf("%d\n", num);
    }
  }
  else {
    printf("0\n");
  }
}
