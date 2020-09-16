#include<cstdio>
int x1, y1, x2, y2, x, y;
int main() {
  x2 = y2 = -1;
  scanf("%d %d", &x1, &y1);
  scanf("%d %d", &x, &y);
  if (x1 != x) x2 = x;
  if (y1 != y) y2 = y;
  scanf("%d %d", &x, &y);
  if (x2 != -1 && x == x2) x = x1;
  else if (x2 != -1 && x == x1) x = x2;
  if (y2 != -1 && y == y2) y = y1;
  else if (y2 != -1 && y == y1) y = y2;
  printf("%d %d\n", x, y);
}