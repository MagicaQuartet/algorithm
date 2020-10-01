#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;

int N, K, ans;
int minVal[200010];
queue<pair<int, int> > q;

int main() {
  scanf("%d %d", &N, &K);
  memset(minVal, -1, sizeof(minVal));

  q.push(make_pair(N, 0));
  ans = 0;
  while(!q.empty()) {
    int pos = q.front().first;
    int cnt = q.front().second;
    q.pop();
    
    if (pos < 0 || pos >= 200010) {
      continue;
    }
    if (minVal[pos] != -1 && minVal[pos] < cnt) {
      if (pos == K) break;
      else continue;
    }

    minVal[pos] = cnt;
    if (pos == K) {
      ans++;
    }

    q.push(make_pair(pos-1, cnt+1));
    q.push(make_pair(pos+1, cnt+1));
    q.push(make_pair(pos*2, cnt+1));
  }

  printf("%d\n%d\n", minVal[K], ans);
}