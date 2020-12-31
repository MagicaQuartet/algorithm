#include<cstdio>
#include<algorithm>
using namespace std;

int t, n;
int arr[101];

int getGCD(int A, int B) {
  int a = max(A, B);
  int b = min(A, B);
  int r = a % b;
  while (r) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

int main() {
  scanf("%d", &t);
  while(t--) {
    long long ans = 0;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
      scanf("%d", arr+i);
    }
    for (int i=0; i<n-1; i++) {
      for (int j=i+1; j<n; j++) {
        ans += getGCD(arr[i], arr[j]);
      }
    }
    printf("%lld\n", ans);
  }
}