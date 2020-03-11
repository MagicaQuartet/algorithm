#include<cstdio>
#include<set>
using namespace std;
int N, M;
int main() {
  set<int> data;
  scanf("%d", &N);
  while(N--) {
    int num;
    scanf("%d", &num);
    data.insert(num);
  }
  
  scanf("%d", &M);
  while(M--) {
    int q;
    scanf("%d", &q);
    printf("%d\n", data.find(q) != data.end() ? 1 : 0);
  }
}
