#include<iostream>
#include<string>
using namespace std;
int cnt[2];
char pre;
string S;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  pre = 0;
  cnt[0] = cnt[1] = 0;
  
  cin >> S;
  for (auto c : S) {
    if (pre != c) {
      cnt[c - '0']++;
      pre = c;
    }
  }
  
  cout << (cnt[0] < cnt[1] ? cnt[0] : cnt[1]);
}

/*
  간단하게 off-line으로 풀긴 했는데 on-line으로 풀 수 있다.
*/