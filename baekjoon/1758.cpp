#include<cstdio>
#include<queue>
using namespace std;
int N, order;
long long ans;
int main (){
  priority_queue<int> pq;
  scanf("%d", &N);
  
  while (N--) {
    int num;
    scanf("%d", &num);
    pq.push(num);
  }
  
  ans = 0;
  order = 1;
  while(!pq.empty()) {
    if (pq.top() - (order - 1) <= 0) {
      break;
    }
    
    ans += pq.top() - (order++ - 1);
    pq.pop();
  }
  
  printf("%lld\n", ans);
}