#include<cstdio>
#include<utility>
#include<algorithm>
#define pii pair<int, int>
using namespace std;
int T;
int x1, y1, x2, y2, rx1, ry1, rx2, ry2;
int ccw(pii a, pii b, pii c) {
  int val = (a.first*b.second+b.first*c.second+c.first*a.second) - (b.first*a.second+c.first*b.second+a.first*c.second);
  if (val == 0) {
    return 0;
  }
  return val > 0 ? 1 : -1;
}
bool intersect(pii l11, pii l12, pii l21, pii l22) {
  int c1 = ccw(l11, l12, l21) * ccw(l11, l12, l22);
  int c2 = ccw(l21, l22, l11) * ccw(l21, l22, l12);
  if (c1 == 0 && c2 == 0) {
    pii nl11 = l11 < l12 ? l11 : l12;
    pii nl12 = l11 < l12 ? l12 : l11;
    pii nl21 = l21 < l22 ? l21 : l22;
    pii nl22 = l21 < l22 ? l22 : l21;
    return nl21 <= nl12 && nl11 <= nl22;
  }
  return c1 <= 0 && c2 <= 0;
}
int main() {
  scanf("%d", &T);
  while(T--) {
    scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &rx1, &ry1, &rx2, &ry2);
    pii l1 = make_pair(x1, y1);
    pii l2 = make_pair(x2, y2);
    pii r1 = make_pair(rx1, ry1);
    pii r2 = make_pair(rx1, ry2);
    pii r3 = make_pair(rx2, ry2);
    pii r4 = make_pair(rx2, ry1);
    // 교차
    if (intersect(l1, l2, r1, r2)) {
      printf("T\n");
      continue;
    }
    if (intersect(l1, l2, r2, r3)) {
      printf("T\n");
      continue;
    }
    if (intersect(l1, l2, r3, r4)) {
      printf("T\n");
      continue;
    }
    if (intersect(l1, l2, r4, r1)) {
      printf("T\n");
      continue;
    }
    // 선분이 사각형 내부에 있음
    int minrx = min(rx1, rx2);
    int minry = min(ry1, ry2);
    int maxrx = max(rx1, rx2);
    int maxry = max(ry1, ry2);
    if (minrx <= l1.first && minrx <= l2.first && minry <= l1.second && minry <= l2.second && l1.first <= maxrx && l2.first <= maxrx && l1.second <= maxry && l2.second <= maxry) {
      printf("T\n");
      continue;
    }
    printf("F\n");
  }
}
