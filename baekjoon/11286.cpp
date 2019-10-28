#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

struct cmp {
  bool operator() (int t, int u) {
    if (abs(t) == abs(u))
      return t > u;
    else
      return abs(t) > abs(u);
  }
};

int main() {
  int N, x;
  priority_queue<int, vector<int>, cmp> pq;
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

/* 힙 -> priority queue */