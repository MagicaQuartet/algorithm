#include<cstdio>
#include<map>
using namespace std;
#define ll long long
int A, B, C;
int r;
map<int, int> dp;
int solve(int x, int p) {
  if (p == 1) return x;
  if (dp.find(p) != dp.end()) return dp[p];
  int ret = solve(x, p/2);
  return dp[p] = ((ll)ret*(((ll)ret*(p%2?x:1))%C))%C;
}
int main() {
  scanf("%d %d %d", &A, &B, &C);
  r = A % C;
  printf("%d\n", solve(r, B));
}