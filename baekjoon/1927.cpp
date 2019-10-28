#include <cstdio>
#include <queue>
using namespace std;

int main() {
  int N, x;
  priority_queue<int, vector<int>, greater<int> > pq;
  scanf("%d", &N);
  while(N--) {
    scanf("%d", &x);
    if (x == 0) {
      if (pq.empty())
        printf("0\n");
      else {
        printf("%d\n", pq.top());
        pq.pop();
      }
    }
    else
      pq.push(x);
  }
  return 0;
}

/* priority queue 연습 */