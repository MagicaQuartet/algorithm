#include<cstdio>
#include<queue>
#define ll long long
#define INF 0x80000000
using namespace std;

struct cmp {
  bool operator() (int lhs, int rhs) {
    return lhs > rhs;
  }
};

int K, N, cnt;
int primes[101];
priority_queue<int, vector<int>, cmp> pq;

int main() {
  scanf("%d %d", &K, &N);

  for (int i=0; i<K; i++) {
    scanf("%d", primes+i);
    pq.push(primes[i]);
  }

  cnt = 0;
  ll num, prevNum = -1;
  while (!pq.empty()) {
    num = pq.top();
    pq.pop();
    if (num == prevNum) { continue; }
    cnt++;
    if (cnt == N) { break; }

    for (int i=0; i<K; i++) {
      if (num*primes[i] >= INF) {
        break;
      }

      pq.push(num*primes[i]);
    }

    prevNum = num;
  }
  printf("%lld\n", num);
}