#include<cstdio>
#include<cstring>
using namespace std;
int cache[10036];
int main() {
  int n, dx;
  memset(cache, 0, 10036);
  for (int i=1; i<=10000; i++) {
    if (cache[i] == 0) {
      printf("%d\n", i);
    }
    n = dx = i;
    while (n > 0) {
      dx += n%10;
      n /= 10;
    }
    cache[dx]++;
  }
}