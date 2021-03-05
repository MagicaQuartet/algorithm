#include<iostream>
#include<string>
#include<deque>
using namespace std;
int T, n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while (T--) {
    deque<int> dq;
    string p, arr;
    int n, rvs;
    cin >> p >> n >> arr;
    rvs = 0;
    int num, possible;
    num = 0;
    possible = 1;
    for (char c: arr) {
      if (c == ',') {
        dq.push_back(num);
        num = 0;
      }
      else if (num != 0 && c == ']') {
        dq.push_back(num);
      }
      else if (c >= '0' && c <= '9') {
        num *= 10;
        num += (c-'0');
      }
    }
    for (char c: p) {
      if (c == 'R') {
        rvs = !rvs;
      }
      else {
        if (dq.empty()) {
          possible = 0;
          break;
        }
        if (rvs) {
          dq.pop_back();
        }
        else {
          dq.pop_front();
        }
      }
    }

    if (possible) {
      int sz = dq.size();
      cout << '[';
      for (int i=0; i<sz; i++) {
        if (rvs) {
          cout << dq.back();
          dq.pop_back();
        }
        else {
          cout << dq.front();
          dq.pop_front();
        }
        if (i<sz-1) cout << ',';
      }
      cout << "]\n";
    }
    else {
      cout << "error\n";
    }
  }
}