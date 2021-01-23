#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
#define pii pair<int, int>
int n, x, y;
bool cmp(pii lhs, pii rhs) {
  return lhs.second != rhs.second ? lhs.second < rhs.second : lhs.first < rhs.first;
}
int main() {
  scanf("%d", &n);
  vector<pii > arr;
  arr.reserve(n);
  while (n--) {
    scanf("%d %d", &x, &y);
    arr.push_back({x, y});
  }
  sort(arr.begin(), arr.end(), cmp);
  for (pii p: arr) {
    printf("%d %d\n", p.first, p.second);
  }
}