#include<cstdio>
#include<list>
using namespace std;
int N, data[10];
list<int> ans;
int main() {
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    scanf("%d", data+i);
  }
  
  for (int i=N-1; i>=0; i--) {
    list<int>::iterator it = ans.begin();
    while(data[i]--) ++it;
    ans.insert(it, i+1);
  }
  
  for (auto i : ans) {
    printf("%d ", i);
  }
}

/*
  키가 가장 큰 사람부터 위치를 정한다.
*/