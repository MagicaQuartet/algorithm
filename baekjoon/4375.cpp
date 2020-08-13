#include<cstdio>
#define ll long long
int n;
int main() {
  while(scanf("%d", &n) != EOF) {
    int ans = 1;
    int cnt = 1;

    while (ans%n) {
      ans = (ans%n)*10 + 1;
      cnt++;
    }

    printf("%d\n", cnt);
  }
}