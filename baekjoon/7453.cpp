#include<cstdio>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

int n;
int A[4010], B[4010], C[4010], D[4010];

int main() {
  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    scanf("%d %d %d %d", A+i, B+i, C+i, D+i);
  }

  vector<int> sum1;
  vector<int> sum2;
  sum1.reserve(n*n);
  sum2.reserve(n*n);

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      sum1.push_back(A[i]+B[j]);
      sum2.push_back(C[i]+D[j]);
    }
  }

  sort(sum2.begin(), sum2.end());

  ll ans = 0;

  for (auto num: sum1) {
    vector<int>::iterator lb = lower_bound(sum2.begin(), sum2.end(), -num);
    vector<int>::iterator ub = upper_bound(sum2.begin(), sum2.end(), -num);
    ans += ub-lb;
  }

  printf("%lld\n", ans);
}