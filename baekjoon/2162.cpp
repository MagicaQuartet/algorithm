#include<cstdio>
#include<utility>
#include<vector>
#include<map>
#define pii pair<int, int>
using namespace std;
int N;
int group[3010];
vector<pair<pii, pii>> lines;
int ccw(pii a, pii b, pii c) {
  int val = (a.first*b.second+b.first*c.second+c.first*a.second) - (b.first*a.second+c.first*b.second+a.first*c.second);
  if (val == 0) {
    return 0;
  }
  return val > 0 ? 1 : -1;
}
bool intersect(pair<pii, pii> l1, pair<pii, pii> l2) {
  int c1 = ccw(l1.first, l1.second, l2.first);
  int c2 = ccw(l1.first, l1.second, l2.second);
  int c3 = ccw(l2.first, l2.second, l1.first);
  int c4 = ccw(l2.first, l2.second, l1.second);

  if (c1*c2 == 0 && c3*c4 == 0) {
    pair<pii, pii> nl1 = l1;
    if (nl1.second < nl1.first) {
      nl1.first = l1.second;
      nl1.second = l1.first;
    }
    pair<pii, pii> nl2 = l2;
    if (nl2.second < nl2.first) {
      nl2.first = l2.second;
      nl2.second = l2.first;
    }
    return nl2.first <= nl1.second && nl1.first <= nl2.second;
  }
  return c1*c2 <= 0 && c3*c4 <= 0;
}
int find(int idx) {
  if (group[idx] == idx) {
    return idx;
  }
  return group[idx] = find(group[idx]);
}
void merge(int idx1, int idx2) {
  if (!intersect(lines[idx1], lines[idx2])) {
    return;
  }
  int head1 = find(idx1);
  int head2 = find(idx2);
  group[idx2] = head1;
  group[head2] = head1;
}
int main() {
  scanf("%d", &N);
  lines.reserve(N);
  for (int i=0; i<N; i++) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    lines.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
    group[i] = i;
    for (int j=0; j<i; j++) {
      merge(j, i);
    }
  }
  map<int, int> ans;
  int maxCnt = -1;
  for (int i=0; i<N; i++) {
    find(i);
    ans[group[i]]++;
    if (maxCnt < ans[group[i]]) {
      maxCnt = ans[group[i]];
    }
  }
  printf("%lu\n%d\n", ans.size(), maxCnt);
}
