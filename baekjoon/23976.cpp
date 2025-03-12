#include<iostream>
#include<string>
#include<cstring>
#define Q 1000000007
#define ll long long
using namespace std;
int N, K;
string s;
ll dp[2510][2510][2];
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> N >> K >> s;
  memset(dp, 0, sizeof(dp));
  if (s[0] == '0') {
    dp[0][1][0] = 1;
  }
  else {
    dp[0][1][1] = 1;
  }
  for (int i=1; i<=s.size(); i++) {
    for (int j=1; j<=i+1; j++) {
      if (s[i] == '0') {
        dp[i][j][0] = (dp[i-1][j-1][0] + dp[i-1][j-1][1])%Q;
        dp[i][j][1] = dp[i-1][j][1];
      }
      else {
        dp[i][j][0] = 0;
        dp[i][j][1] = (dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j][1])%Q;
      }
    }
  }
  cout << (dp[N-1][K][0] + dp[N-1][K][1])%Q << "\n";
}
