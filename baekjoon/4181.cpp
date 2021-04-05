#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
#define INF 1000000001
typedef long long ll;
typedef pair<ll, ll> pll;
int n;
pll start(INF, INF);
ll dist(pll p1, pll p2) {
  return (p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second);
}
ll ccw(pll p, pll p1, pll p2) {
  pll v1(p1.first-p.first, p1.second-p.second);
  pll v2(p2.first-p1.first, p2.second-p1.second);
  return v1.first*v2.second-v1.second*v2.first;
}
bool ccwcmp(pll p1, pll p2) {
  ll ccwResult = ccw(start, p1, p2);
  if (ccwResult != 0) {
    return ccwResult > 0;
  }
  return dist(start, p1) < dist(start, p2);
}
int main() {
  scanf("%d", &n);
  vector<pll > hull;

  for (int i=0; i<n; i++) {
    int x, y;
    char c;
    scanf("%d %d %c", &x, &y, &c);
    if (c == 'N') {
      continue;
    }

    if (x < start.first || (x == start.first && y < start.second)) {
      start.first = x;
      start.second = y;
    }
    hull.push_back(make_pair(x, y));
  }
  sort(hull.begin(), hull.end(), ccwcmp);
  int len = hull.size();
  int idx = len;
  for (int i=1; i<len-1; i++) {
    ll check = ccw(start, hull[i], hull[i+1]);
    ll check2 = ccw(hull[i-1], hull[i], hull[i+1]);
    if (check == 0 && check2 < 0) {
      idx = i;
      break;
    }
  }
  printf(">>> %d\n", idx);
  printf("%d\n", len);
  for (int i=0; i<idx; i++) {
    printf("%lld %lld\n", hull[i].first, hull[i].second);
  }
  for (int i=len-1; i>=idx; i--) {
    printf("%lld %lld\n", hull[i].first, hull[i].second);
  }
}
