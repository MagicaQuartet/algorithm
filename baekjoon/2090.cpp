#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
int N, num;
ll gcd(ll a, ll b) {
  if (a < b) {
    ll tmp = b;
    b = a;
    a = tmp;
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a%b);
}
int main() {
  scanf("%d", &N);
  ll a = 0;
  ll b = 1;
  while (N--) {
    scanf("%d", &num);
    a = a*num+b;
    b *= num;
    ll g = gcd(a, b);
    a /= g;
    b /= g;
  }
  printf("%lld/%lld\n", b, a);
}
