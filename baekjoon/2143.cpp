#include<cstdio>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

ll T;
int an, bn;
ll A[1010], B[1010];

int main() {
  scanf("%lld", &T);
  scanf("%d", &an);
  vector<ll> aSum;
  aSum.reserve(an*(an-1)/2);
  A[0] = 0;
  for (int i=1; i<=an; i++) {
    int num;
    scanf("%d", &num);
    A[i] = A[i-1] + num;
  }
  scanf("%d", &bn);
  vector<ll> bSum;
  bSum.reserve(bn*(bn-1)/2);
  B[0] = 0;
  for (int i=1; i<=bn; i++) {
    int num;
    scanf("%d", &num);
    B[i] = B[i-1] + num;
  }

  for (int i=0; i<an; i++) {
    for (int j=i+1; j<=an; j++) {
      aSum.push_back(A[j]-A[i]);
    }
  }
  for (int i=0; i<bn; i++) {
    for (int j=i+1; j<=bn; j++) {
      bSum.push_back(B[j]-B[i]);
    }
  }

  sort(bSum.begin(), bSum.end());

  ll ans = 0;
  
  for (int i=0; i<aSum.size(); i++) {
    vector<ll>::iterator lb = lower_bound(bSum.begin(), bSum.end(), T-aSum[i]);
    vector<ll>::iterator ub = upper_bound(bSum.begin(), bSum.end(), T-aSum[i]);
    ans += ub-lb;
  }
  
  printf("%lld\n", ans);
}

/*
  ㅋㅋㅋㅋㅋint로 되는 줄 알았는데 죄다 ll로 했어야 했네~
*/