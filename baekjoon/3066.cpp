#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T, N, lislen;
int lis[40010];
int main() {
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &N);
    lislen = 0;
    memset(lis, -1, sizeof(lis));
    for (int i=1; i<=N; i++) {
      int num;
      scanf("%d", &num);
      int head = 1;
      int tail = lislen;
      while (head < tail) {
        int mid = (head+tail)/2;
        if (lis[mid] >= num) {
          tail = mid;
        }
        else {
          head = mid + 1;
        }
      }
      if (lis[tail] < num) tail++;
      lis[tail] = num;
      lislen = max(lislen, tail);
    }
    printf("%d\n", lislen);
  }
}
