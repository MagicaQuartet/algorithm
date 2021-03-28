#include<cstdio>
#include<queue>
#include<map>
#include<functional>
using namespace std;
#define ll long long
int T, k;
ll n;
char op;
int main() {
  scanf("%d", &T);
  while(T--) {
    priority_queue<ll> pqMax;
    priority_queue<ll, vector<ll>, greater<ll> > pqMin;
    map<int, int> currentCnt;
    scanf("%d", &k);
    while(k--) {
      getchar();
      scanf("%c %lld", &op, &n);
      if (op == 'I') {
        pqMax.push(n);
        pqMin.push(n);
        if (!currentCnt.count(n)) {
          currentCnt[n] = 0;
        }
        currentCnt[n] += 1;
      }
      else if (op == 'D') {
        if (n == 1) {
          while(!pqMax.empty() && currentCnt[pqMax.top()] == 0) {
            pqMax.pop();
          }
          if (pqMax.empty()) {
            continue;
          }
          currentCnt[pqMax.top()] -= 1;
          pqMax.pop();
        }
        else {
          while(!pqMin.empty() && currentCnt[pqMin.top()] == 0) {
            pqMin.pop();
          }
          if (pqMin.empty()) {
            continue;
          }
          currentCnt[pqMin.top()] -= 1;
          pqMin.pop();
        }
      }
    }
    while(!pqMax.empty() && currentCnt[pqMax.top()] == 0) {
      pqMax.pop();
    }
    while(!pqMin.empty() && currentCnt[pqMin.top()] == 0) {
      pqMin.pop();
    }
    if (pqMax.empty()) {
      printf("EMPTY\n");
    }
    else {
      printf("%lld %lld\n", pqMax.top(), pqMin.top());
    }
  }
}
