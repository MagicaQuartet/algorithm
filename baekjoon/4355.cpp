#include<cstdio>
#include<vector>
using namespace std;
int n, ans;
int main() {
  while (1) {
    scanf("%d", &n);
    if (!n) break;
    ans = n;
    if (n%2 == 0) {
      ans /= 2;
      while (n%2 == 0) n /= 2;
    }
    for (int i=3; i*i<=n; i+=2) {
      if (n%i == 0) {
        ans = (ans / i) * (i-1);
        while (n%i == 0) n /= i;
      }
    }
    if (n > 1) ans = (ans / n) * (n-1);
    printf("%d\n", ans);
  }
}