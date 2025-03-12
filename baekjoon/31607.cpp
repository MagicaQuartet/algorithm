#include<cstdio>
using namespace std;

int a, b, c;
int main() {
  scanf("%d%d%d", &a, &b, &c);
  printf("%d\n", a+b==c||a+c==b||b+c==a ? 1 : 0);
}
