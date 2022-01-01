#include<cstdio>
#define ll long long
int x1, y1, x2, y2, x3, y3, x4, y4;
bool check(double a, double b, double x) {
  return (a<=b && a-0.00000001<=x && x<=b+0.00000001) || (a>b && b-0.00000001<=x && x<=a+0.00000001);
}

int main() {
  scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
  ll lhs = (ll)(x1-x2)*(y3-y4)-(ll)(x3-x4)*(y1-y2);
  ll rhs = -(ll)x1*x3*y4+(ll)x2*x3*y4+(ll)x1*x3*y2-(ll)x1*x4*y2+(ll)x1*x4*y3-(ll)x2*x3*y1+(ll)x2*x4*y1-(ll)x2*x4*y3;
  if (lhs == 0) {
    if (rhs != 0) {
      printf("0\n");
    }
    else {
      printf("%d\n", (((x1<=x3 && x3<=x2) || (x2<=x3 && x3<=x1)) && ((y1<=y3 && y3<=y2) || (y2<=y3 && y3<=y1))) || (((x1<=x4 && x4<=x2) || (x2<=x4 && x4<=x1)) && ((y1<=y4 && y4<=y2) || (y2<=y4 && y4<=y1))) || (((x3<=x1 && x1<=x4) || (x4<=x1 && x1<=x3)) && ((y3<=y1 && y1<=y4) || (y4<=y1 && y1<=y3))) || (((x3<=x2 && x2<=x4) || (x4<=x2 && x2<=x3)) && ((y3<=y2 && y2<=y4) || (y4<=y2 && y2<=y3))) ? 1 : 0);
    }
  }
  else {
    double x = (double)rhs/lhs;
    double y = (x1 == x2) ? (y3-y4)*(x-x3)/(x3-x4)+y3 : (y1-y2)*(x-x1)/(x1-x2)+y1;
    printf("%d\n", check(x1, x2, x) && check(y1, y2, y) && check(x3, x4, x) && check(y3, y4, y) ? 1 : 0);
  }
}
