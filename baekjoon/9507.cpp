#include<cstdio>
int t, n, pos;
long long koong[68];
int main() {
  koong[0] = koong[1] = 1;
  koong[2] = 2;
  koong[3] = 4;
  pos = 3;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    if (pos < n) {
      for (int i=pos+1; i<=n; i++) {
        koong[i] = koong[i-1] + koong[i-2] + koong[i-3] + koong[i-4];
        pos++;
      }
    }
    printf("%lld\n", koong[n]);
  }
}