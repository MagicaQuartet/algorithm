#include<cstdio>
int x1, y1, x2, y2, x3, y3;
int main() {
  scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
  int res = (y1-y2)*(x3-x2)-(x1-x2)*(y3-y2);
  printf("%d\n", (!!res)*(res > 0 ? 1 : -1));
}
