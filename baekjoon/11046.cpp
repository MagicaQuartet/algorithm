#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, s, e, c, arr[2000010], A[2000010];
int r, p;

int main() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    arr[2*i] = -1;
    scanf("%d", arr+2*i+1);
  }
  arr[2*n] = -1;
  r = p = -1;
  for (int i=0; i<=2*n; i++) {
    if (i <= r) {
      A[i] = min(r-i, A[2*p-i]);
    }
    else {
      A[i] = 0;
    }

    while (i-A[i]-1 >= 0 && i+A[i]+1 <= 2*n && arr[i-A[i]-1] == arr[i+A[i]+1]) {
      A[i]++;
    }

    if (r < i + A[i]) {
      r = i + A[i];
      p = i;
    }
  }

  scanf("%d", &m);
  while (m--) {
    scanf("%d %d", &s, &e);
    s = 2*s-1;
    e = 2*e-1;
    c = (s+e)/2;
    printf("%d\n", (A[c] >= e-c) ? 1 : 0);
  }
}