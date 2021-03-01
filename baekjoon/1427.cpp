#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string s;
int cnt[10];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  memset(cnt, 0, sizeof(cnt));
  for (char c: s) {
    cnt[c-'0']++;
  }
  for (int i=9; i>=0; i--) {
    for (int j=0; j<cnt[i]; j++) {
      cout << i;
    }
  }
  cout << "\n";
}
