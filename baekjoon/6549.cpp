#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;

int n;
int nums[100010];

ll solve(int left, int right) {
  if (left == right) {
    return nums[left];
  }

  ll ret = 0;
  int mid = (left+right)/2;
  ret = max(solve(left, mid), solve(mid+1, right));

  int l = mid;
  int r = mid+1;
  int h = min(nums[l], nums[r]);
  ret = max(ret, (ll)h*2);
  
  while (1) {
    if (l == left && r == right) {
      break;
    }
    else if (l == left) {
      h = min(h, nums[++r]);
      ret = max(ret, (ll)h*(r-l+1));
    }
    else if (r == right) {
      h = min(h, nums[--l]);
      ret = max(ret, (ll)h*(r-l+1));
    }
    else {
      if (nums[l-1] < nums[r+1]) {
        h = min(h, nums[++r]);
        ret = max(ret, (ll)h*(r-l+1));
      }
      else {
        h = min(h, nums[--l]);
        ret = max(ret, (ll)h*(r-l+1));
      }
    }
  }

  return ret;
}

int main() {
  while (1) {
    scanf("%d", &n);
    if (n == 0) {
      break;
    }

    for (int i=1; i<=n; i++) {
      scanf("%d", nums+i);
    }

    printf("%lld\n", solve(1, n));
  }
}