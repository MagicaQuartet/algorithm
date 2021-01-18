#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
int N, arr[100010];
ll ans;
ll solve(int l, int r) {
  if (l == r) {
    return arr[l];
  }
  int mid = (l+r)/2;
  ll retLeft = solve(l, mid);
  ll retRight = solve(mid+1, r);
  ans = max(ans, max(retLeft, retRight));

  int lidx = mid;
  int ridx = mid+1;
  ll h = min(arr[lidx], arr[ridx]);
  ans = max(ans, (ridx-lidx+1)*h);
  while (lidx > l && ridx < r) {
    if (h == 0) break;
    if (arr[lidx-1] >= arr[ridx+1]) lidx--;
    else ridx++;
    h = min(h, (ll)min(arr[lidx], arr[ridx]));
    ans = max(ans, (ridx-lidx+1)*h);
  }
  while (lidx > l) {
    if (h == 0) break;
    lidx--;
    h = min(h, (ll)min(arr[lidx], arr[ridx]));
    ans = max(ans, (ridx-lidx+1)*h);
  }
  while (ridx < r) {
    if (h == 0) break;
    ridx++;
    h = min(h, (ll)min(arr[lidx], arr[ridx]));
    ans = max(ans, (ridx-lidx+1)*h);
  }
  return ans;
}
int main() {
  scanf("%d", &N);
  for (int i=1; i<=N; i++) {
    scanf("%d", arr+i);
  }
  ans = 0;
  printf("%lld\n", solve(1, N));
}