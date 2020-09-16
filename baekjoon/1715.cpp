#include<cstdio>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;

int N, ans;

struct cmp {
  bool operator() (int lhs, int rhs) {
    return lhs > rhs;
  }
};

int main() {
  scanf("%d", &N);
  priority_queue<int, vector<int>, cmp> pq;

  for (int i=0; i<N; i++) {
    int num;
    scanf("%d", &num);
    pq.push(num);
  }

  while (pq.size() > 1) {
    int card1 = pq.top();
    pq.pop();
    int card2 = pq.top();
    pq.pop();
    pq.push(card1+card2);
    ans += card1+card2;
  }

  printf("%d\n", ans);
}