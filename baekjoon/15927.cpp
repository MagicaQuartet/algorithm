#include<iostream>
#include<string>
using namespace std;

int n, ans, head, tail;
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  n = s.size();
  ans = -1;
  head = 0;
  tail = n-1;
  while (head < tail) {
    if (s[head++] != s[tail--]) {
      ans = n;
      break;
    }
  }
  if (ans > -1) {
    printf("%d\n", ans);
    return 0;
  }
  head = 0;
  tail = n-2;
  while (head < tail) {
    if (s[head++] != s[tail--]) {
      ans = n-1;
      break;
    }
  }
  printf("%d\n", ans);
}