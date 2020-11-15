#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int N, K;
int minVal[200010];
int parent[200010];
queue<pair<pair<int, int>, int> > q;

int main() {
  scanf("%d %d", &N, &K);
  memset(minVal, -1, sizeof(minVal));
  memset(parent, -1, sizeof(parent));

  q.push(make_pair(make_pair(-1, N), 0));
  while(!q.empty()) {
    int pre = q.front().first.first;
    int pos = q.front().first.second;
    int cnt = q.front().second;
    q.pop();
    
    if (pos < 0 || pos >= 200010) {
      continue;
    }
    if (minVal[pos] != -1 && minVal[pos] <= cnt) {
      continue;
    }

    minVal[pos] = cnt;
    parent[pos] = pre;

    q.push(make_pair(make_pair(pos, pos-1), cnt+1));
    q.push(make_pair(make_pair(pos, pos+1), cnt+1));
    q.push(make_pair(make_pair(pos, pos*2), cnt+1));
  }

  printf("%d\n", minVal[K]);

  vector<int> path;
  int step = K;
  while(step != -1) {
    path.push_back(step);
    step = parent[step];
  }

  for (vector<int>::reverse_iterator rit=path.rbegin(); rit!=path.rend(); ++rit) {
    printf("%d ", *rit);
  }
  printf("\n");
}