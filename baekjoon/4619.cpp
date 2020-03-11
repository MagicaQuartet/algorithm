#include<cstdio>
#include<algorithm>
using namespace std;
long long B, pre;
int N;
long long _pow(int n, int r) {
  long long ret = 1;
  for (int i=0; i<r; i++) {
    ret *= n;
  }
  return ret;
}
int main() {
  while(1) {
    scanf("%lld %d", &B, &N);
    if (B == 0) break;
    
    pre = -1000000;
    
    for (int i=1; i<=1000000; i++) {
      long long p = _pow(i, N);
      if (p < B) {
        pre = p;
      }
      else {
        printf("%d\n", (B-pre < p-B && i>1) ? i-1 : i);
        break;
      }
    }
  }
}