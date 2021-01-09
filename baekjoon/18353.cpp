#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N, ldslen;
int arr[2010];
int lds[2010];
int main() {
  scanf("%d", &N);
  for (int i=1; i<=N; i++) {
    scanf("%d", arr+i);
  }
  memset(lds, -1, sizeof(lds));
  lds[0] = 987654321;
  ldslen = 0;
  for (int i=1; i<=N; i++) {
    int head = 1;
    int tail = ldslen;
    while (head < tail) {
      int mid = (head+tail)/2;
      if (arr[i] >= lds[mid]) {
        tail = mid;
      }
      else {
        head = mid + 1;
      }
    }
    if (arr[i] < lds[tail]) tail++;
    ldslen = max(ldslen, tail);
    lds[tail] = arr[i];
  }
  printf("%d\n", N-ldslen);
}
