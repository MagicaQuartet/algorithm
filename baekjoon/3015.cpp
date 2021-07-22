#include<cstdio>
#include<cstring>
#include<utility>
#include<stack>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int N;
int arr[500010];

int main() {
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    scanf("%d", arr+i);
  }
  stack<pii > stk;
  ll ans = 0;
  for (int i=0; i<N; i++) {
    int point = 0;
    while (!stk.empty()) {
      if (stk.top().first >= arr[i]) {
        break;
      }

      point++;
      stk.pop();
    }
    ans += point;
    if (!stk.empty() && stk.top().first == arr[i]) {
      point += stk.top().second ;
    }
    stk.push(make_pair(arr[i], point));
  }
  while (!stk.empty()) {
    stk.pop();
  }

  for (int i=N-1; i>=0; i--) {
    int point = 0;
    while (!stk.empty()) {
      if (stk.top().first >= arr[i]) {
        break;
      }

      point++;
      stk.pop();
    }
    ans += point;
    if (!stk.empty() && stk.top().first == arr[i]) {
      point += stk.top().second;
    }
    stk.push(make_pair(arr[i], point));
  }
  while (!stk.empty()) {
    stk.pop();
  }

  for (int i=0; i<N; i++) {
    int cnt = 1;
    while (!stk.empty()) {
      if (stk.top().first >= arr[i]) {
        break;
      }

      ans += (ll)stk.top().second*(stk.top().second-1)/2;
      stk.pop();
    }
    if (!stk.empty() && stk.top().first == arr[i]) {
      cnt = stk.top().second + 1;
      stk.top().second = 1;
    }
    stk.push(make_pair(arr[i], cnt));
  }
  while (!stk.empty()) {
    ans += (ll)stk.top().second*(stk.top().second-1)/2;
    stk.pop();
  }
  printf("%lld\n", ans);
}
