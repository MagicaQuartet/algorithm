#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define vi vector<int>
#define ll long long
int A[500010], numToIdx[1000010];
int B[500010];
int N;
ll ans;
vi mergeSort(int l, int r) {
  if (l == r) {
    return vi(1, B[l]);
  }
  int mid = (l+r)/2;
  vi retLeft = mergeSort(l, mid);
  vi retRight = mergeSort(mid+1, r);
  vi ret;
  ret.reserve(r-l+1);

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
  while (lidx < retLeft.size()) ret.push_back(retLeft[lidx++]);
  while (ridx < retRight.size()) ret.push_back(retRight[ridx++]);
  return ret;
}
int main() {
  scanf("%d", &N);
  for (int i=1; i<=N; i++) {
    scanf("%d", A+i);
    numToIdx[A[i]] = i;
  }
  for (int i=1; i<=N; i++) {
    int num;
    scanf("%d", &num);
    B[i] = numToIdx[num];
  }
  ans = 0;
  mergeSort(1, N);
  printf("%lld\n", ans);
}