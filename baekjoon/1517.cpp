#include<cstdio>
#include<cstring>
#include<vector>
#define vi vector<int>
#define ll long long
using namespace std;
int N;
ll ans;
int arr[500010];
vi mergeSort(int l, int r) {
  if (l == r) {
    return vi(1, arr[l]);
  }
  int mid = (l+r)/2;
  vi ret;
  ret.reserve(r-l+1);
  vi retLeft = mergeSort(l, mid);
  vi retRight = mergeSort(mid+1, r);
  
  int lidx = 0;
  int ridx = 0;
  while (lidx < retLeft.size() && ridx < retRight.size()) {
    if (retLeft[lidx] <= retRight[ridx]) {
      ret.push_back(retLeft[lidx++]);
    }
    else {
      ans += retLeft.size()-lidx;
      ret.push_back(retRight[ridx++]);
    }
  }
  while (lidx < retLeft.size()) {
    ret.push_back(retLeft[lidx++]);
  }
  while (ridx < retRight.size()) {
    ret.push_back(retRight[ridx++]);
  }
  return ret;
}
int main() {
  scanf("%d", &N);
  for (int i=1; i<=N; i++) {
    scanf("%d", arr+i);
  }
  ans = 0;
  mergeSort(1, N);
  printf("%lld\n", ans);
}