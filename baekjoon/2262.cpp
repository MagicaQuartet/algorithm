#include<cstdio>
#include<list>
#include<iterator>
#include<algorithm>
using namespace std;
int N, max_, with, ans;
list<int>::iterator maxit;
int main() {
  list<int> data;
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    int num;
    scanf("%d", &num);
    data.push_back(num);
  }
  
  ans = 0;
  while(--N) {
    max_ = 0;
    for (list<int>::iterator it=data.begin(); it!=data.end(); ++it) {
      if (max_ < *it) {
        max_ = *it;
        maxit = it;
        
        if (it == data.begin()) {
          with = *next(it);
        }
        else if (next(it) == data.end()) {
          with = *prev(it);
        }
        else {
          with = max(*prev(it), *next(it));
        }
      }
    }
    ans += max_ - with;
    data.erase(maxit);
  }
  printf("%d\n", ans);
}