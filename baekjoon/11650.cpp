#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#define pii pair<int, int>
using namespace std;

int N;

bool cmp (pii c1, pii c2) {
  return (c1.first != c2.first) ? c1.first < c2.first : c1.second < c2.second;
}

int main() {
  scanf("%d", &N);
  vector<pii > coords;
  coords.reserve(N);

  for (int i=0; i<N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    coords.push_back({x, y});
  }

  sort(coords.begin(), coords.end(), cmp);

  for (int i=0; i<N; i++) {
    printf("%d %d\n", coords[i].first, coords[i].second);
  }
}