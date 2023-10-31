#include<cstdio>
#include<utility>
#include<queue>
using namespace std;
#define record pair<pair<pair<int, int>, int>, int>
int N, K;
int main() {
  scanf("%d%d", &N, &K);
  priority_queue<record> pq;
  for (int i=0; i<N; i++) {
    int n, a, b, c;
    scanf("%d%d%d%d", &n, &a, &b, &c);
    pq.push({{{a, b}, c}, n});
  }
  int rank = 0;
  int buffer = 1;
  int prev_a = -1;
  int prev_b = -1;
  int prev_c = -1;
  while(!pq.empty()) {
    record top = pq.top();
    pq.pop();
    int a = top.first.first.first;
    int b = top.first.first.second;
    int c = top.first.second;
    int n = top.second;
    if (a != prev_a || b != prev_b || c != prev_c) {
      rank += buffer;
      buffer = 1;
    } else {
      buffer++;
    }
    prev_a = a;
    prev_b = b;
    prev_c = c;
    if (n == K) {
      break;
    }
  }
  printf("%d\n", rank);
}
