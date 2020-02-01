#include<cstdio>
#include<queue>
#include<utility>
#include<functional>
using namespace std;
int n, cnt, a, b, cache[500];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >> pq;
int main() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%d %d", &a, &b);
    pq.push(make_pair(a, b));
  }
  cnt = 0;
  for (int i=0; i<n; i++) {
    cache[i] = -1;
    for (int j=0; j<=i; j++) {
      if (cache[j] == -1 || pq.top().second <= cache[j]) {
        cache[j] = pq.top().second;
        if (cnt < j+1) {
          cnt = j+1;
        }
        break;
      }
    }
    pq.pop();
  }
  printf("%d\n", n-cnt);
}