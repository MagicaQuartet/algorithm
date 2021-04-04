#include<cstdio>
#include<cmath>
#define ll long long
struct Point {
  int x;
  int y;
};
struct Vector {
  int x;
  int y;
  Vector(Point src, Point dst): x(dst.x-src.x), y(dst.y-src.y) {}
};
int N;
Point p, p1, p2;
ll getArea(Vector v1, Vector v2) {
  ll cross = (ll)v1.x*v2.y-(ll)v1.y*v2.x;
  return cross;
}
int main() {
  scanf("%d", &N);
  scanf("%d %d", &p.x, &p.y);
  scanf("%d %d", &p1.x, &p1.y);
  double ans = 0;
  for (int i=2; i<N; i++) {
    scanf("%d %d", &p2.x, &p2.y);
    Vector v1(p, p1);
    Vector v2(p, p2);
    ans += getArea(v1, v2);
    p1.x = p2.x;
    p1.y = p2.y;
  }
  printf("%.1f\n", fabs(ans)/2);
}
