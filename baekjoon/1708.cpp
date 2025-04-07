#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<utility>
using namespace std;
#define ll long long
#define point pair<int, int>
int N;
point p;

ll ccw(point p1, point p2, point p3) {
  return (ll)(p2.first - p1.first) * (p3.second - p2.second) - (ll)(p2.second - p1.second) * (p3.first - p2.first);
}

point start = { 40001, 40001 };
bool cmp(point p1, point p2) {
  if (p1.second == p2.second) {
    return p1.first < p2.first;
  }
  return p1.second < p2.second;
}
bool ccwcmp(point p1, point p2) {
  ll c1 = ccw(start, p1, p2);
  ll c2 = ccw(start, p2, p1);
  if (c1 == 0 && c2 == 0) {
    return cmp(p1, p2);
  }
  return c1 > c2;
}

int main() {
  scanf("%d", &N);
  vector<point> arr;
  stack<point> hull;

  for (int i = 0; i < N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    point np = { x, y };
    arr.push_back(np);
    if (cmp(np, start)) {
      start = np;
    }
  }

  sort(arr.begin(), arr.end(), ccwcmp);
  hull.push(arr[0]);
  hull.push(arr[1]);
  for (int i = 2; i < arr.size(); i++) {
    point next = arr[i];
    while (hull.size() >= 2) {
      point second = hull.top();
      hull.pop();
      point first = hull.top();
      ll check = ccw(first, second, next);
      if (check >= 0) {
        if (check > 0) {
          hull.push(second);
        }
        break;
      }
    }
    hull.push(next);
  }
  printf("%zu\n", hull.size());
}
