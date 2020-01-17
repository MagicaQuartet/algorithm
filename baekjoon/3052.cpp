#include<cstdio>
#include<cstring>
int n, r[42], cnt=0;
int main() {
  memset(r, 0, 168);
  for (int i=0; i<10; i++) {
    scanf("%d", &n);
    r[n%42]++;
    if (r[n%42] == 1) cnt++;
  }
  printf("%d\n", cnt);
}