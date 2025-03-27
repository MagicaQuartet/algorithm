#include<cstdio>
#include<utility>
#define ll long long
#define pll pair<ll, ll>
using namespace std;
int x1, y1, x2, y2, x3, y3, x4, y4;
int ccw(pll a, pll b, pll c) {
  ll val = (a.first*b.second+b.first*c.second+c.first*a.second) - (b.first*a.second+c.first*b.second+a.first*c.second);
  if (val == 0) {
    return 0;
  }
  return val > 0 ? 1 : -1;
}
int main() {
  scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
  pll p1 = make_pair(x1, y1);
  pll p2 = make_pair(x2, y2);
  pll p3 = make_pair(x3, y3);
  pll p4 = make_pair(x4, y4);
  int c1 = ccw(p1, p2, p3);
  int c2 = ccw(p1, p2, p4);
  int c3 = ccw(p3, p4, p1);
  int c4 = ccw(p3, p4, p2);
  printf("%d\n", c1*c2 <= 0 && c3*c4 <= 0 ? 1 : 0);
}
