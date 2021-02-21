#include<cstdio>
#include<algorithm>
using namespace std;
int a, b, c, d, e;
int main() {
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
  printf("%d\n", min(a, min(b, c))+min(d, e)-50);
}