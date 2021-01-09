#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N, lislen;
int arr[200010], lis[200010];
int main() {
  scanf("%d", &N);
  memset(lis, -1, sizeof(lis));
  for (int i=1; i<=N; i++) {
    scanf("%d", arr+i);
  }
  lislen = 0;
  for (int i=1; i<=N; i++) {
    int head = 1;
    int tail = lislen;
    while (head < tail) {
      int mid = (head+tail)/2;
      if (arr[i] <= lis[mid]) {
        tail = mid;
      }
      else {
        head = mid + 1;
      }
    }
    if (lis[tail] < arr[i]) tail++;
    lislen = max(lislen, tail);
    lis[tail] = arr[i];
  }
  printf("%d\n", N-lislen);
}