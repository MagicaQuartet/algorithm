#include<cstdio>
#include<utility>
#include<queue>
#define pii pair<int, int>
#define INF 1000000001
using namespace std;

int N, a, b;
int sum, pre, lines;
priority_queue<pii > pq;

int main() {
  scanf("%d", &N);

  while(N--) {
    scanf("%d %d", &a, &b);
    pq.push(make_pair(a, -1));
    pq.push(make_pair(b, 1));
  }

  sum = lines = 0;
  pre = INF;
  while(!pq.empty()) {
    int pos = pq.top().first;
    int mode = pq.top().second;
    pq.pop();

    if (pre != INF && lines > 0) {
      sum += pre-pos;
    }

    pre = pos;
    lines += mode;
  }

  printf("%d\n", sum);
}