#include<cstdio>
#include<cstring>
#include<vector>
#include<unordered_map>
#include<utility>
#include<functional>
#include<algorithm>
using namespace std;
int tx, ty, n, x, y, h, dx, dy;
double key;
unordered_map<double, vector<pair<int, int> > > pmap; // dx > 0, dy != 0
unordered_map<double, vector<pair<int, int> > > mmap; // dx < 0, dy != 0
unordered_map<double, vector<pair<int, int> > > zpmap; // dx == 0, dy > 0
unordered_map<double, vector<pair<int, int> > > zmmap; // dx == 0, dy < 0
vector<pair<int, int> > pvector; // dy == 0, dx > 0
vector<pair<int, int> > mvector; // dy == 0, dx < 0
int dp[1000000];
int lis(vector<pair<int, int> >& data) {
  sort(data.begin(), data.end());
  int n = data.size();
  int max = 0;
  for (int i=0; i<n; i++) {
    dp[i] = 987654321;
    for (int j=0; j<=i; j++) {
      if (data[i].second <= dp[j]) {
        dp[j] = data[i].second;
        if (max < j+1) {
          max = j+1;
        }
        break;
      }
    }
  }
  return max;
}
int main() {
  scanf("%d %d %d", &tx, &ty, &n);
  for (int i=0; i<n; i++) {
    scanf("%d %d %d", &x, &y, &h);
    dx = tx-x;
    dy = ty-y;
    key = dx/(double)dy;
    if (dy == 0) {
      if (dx > 0) {
        pvector.push_back(make_pair(dx, h));
      }
      else {
        mvector.push_back(make_pair(-dx, h));
      }
    }
    else {
      if (dx > 0) {
        if (!pmap.count(key)) {
          pmap[key] = vector<pair<int, int> >();
        }
        pmap[key].push_back(make_pair(dx, h));
      }
      else if (dx == 0) {
        if (dy > 0) {
          if (!zpmap.count(key)) {
            zpmap[key] = vector<pair<int, int> >();
          }
          zpmap[key].push_back(make_pair(dy, h));
        }
        else {
          if (!zmmap.count(key)) {
            zmmap[key] = vector<pair<int, int> >();
          }
          zmmap[key].push_back(make_pair(-dy, h));
        }
      }
      else {
        if (!mmap.count(key)) {
          mmap[key] = vector<pair<int, int> >();
        }
        mmap[key].push_back(make_pair(-dx, h));
      }
    }
  }
  
  int ret = 0;
  for (pair<double, vector<pair<int, int> > > elem: pmap) {
    ret += lis(elem.second);
  }
  for (pair<double, vector<pair<int, int> > > elem: mmap) {
    ret += lis(elem.second);
  }
  for (pair<double, vector<pair<int, int> > > elem: zpmap) {
    ret += lis(elem.second);
  }
  for (pair<double, vector<pair<int, int> > > elem: zmmap) {
    ret += lis(elem.second);
  }
  ret += lis(pvector);
  ret += lis(mvector);
  printf("%d\n", ret);
}

/* 1. TV를 시작점으로 하는 반직선상에 위치한 도마뱀들끼리 그룹을 짓는다. */
/* 2. 각 그룹에서 도마뱀들을 TV에 가까운 순으로 정렬한다 */
/* 3. 정렬한 후 h값을 기준으로 LIS의 길이를 구한다. 이렇게 모든 그룹의 LIS 길이를 구하여 합산한다. */