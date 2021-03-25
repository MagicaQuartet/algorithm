#include<iostream>
#include<string>
using namespace std;
int N, M;
string S;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M >> S;
  int cnt = 0;
  int ans = 0;
  int mode = 0;
  for (int i=0; i<M; i++) {
    if (mode == 0 && S[i] == 'I') {
      mode = 1;
    }
    else if (mode == 1 && S[i] == 'O') {
      mode = 2;
    }
    else if (mode == 2 && S[i] == 'I') {
      mode = 1;
      cnt++;
      if (cnt >= N) {
        ans++;
      }
    }
    else {
      mode = S[i] == 'I' ? 1 : 0;
      cnt = 0;
    }
  }
  cout << ans << "\n";
}