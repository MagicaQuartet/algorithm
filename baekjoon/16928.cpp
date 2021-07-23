#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
int N, M;
int d[101], moveTo[101];

int main() {
  scanf("%d %d", &N, &M);
  memset(d, -1, sizeof(d));
  memset(moveTo, -1, sizeof(moveTo));
  for (int i=0; i<N+M; i++) {
    int start, end;
    scanf("%d %d", &start, &end);
    moveTo[start] = end;
  }

  queue<pii> q;
  q.push(make_pair(1, 0));
  while (!q.empty()) {
    int pos = q.front().first;
    int t = q.front().second;
    q.pop();

    if (d[pos] != -1 && d[pos] <= t) {
      continue;
    }
    d[pos] = t;
    for (int i=1; i<=6; i++) {
      int dest = pos+i;
      if (dest > 100) {
        break;
      }
      if (d[dest] != -1 && d[dest] <= t+1) {
        continue;
      }
      if (moveTo[dest] == -1) {
        q.push(make_pair(dest, t+1));
        continue;
      }
      if (d[moveTo[dest]] != -1 && d[moveTo[dest]] <= t+1) {
        continue;
      }
      q.push(make_pair(moveTo[dest], t+1));
    }
  }
  printf("%d\n", d[100]);
}
