#include<cstdio>
using namespace std;

int n;
char a[101], b[101];
int main() {
  scanf("%d%s%s", &n, a, b);
  int ans = 0;
  for (int i=0; i<n; i++) {
    if (a[i] != b[i]) {
      ans++;
    }
  }
  printf("%d\n", ans);
}
