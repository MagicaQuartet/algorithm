#include<iostream>
#include<string>
#include<vector>
#include<deque>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  string s;
  vector<deque<char> > gears(4, deque<char>());
  vector<int> direction(4, 0);
  for (int i=0; i<4; i++) {
    cin >> s;
    for (auto c: s) {
      gears[i].push_back(c);
    }
  }
  int K, g, d;
  cin >> K;
  while (K--) {
    cin >> g >> d;
    g -= 1;
    direction[g] = d;
    for (int i=g-1; i>=0; i--) {
      direction[i] = (!direction[i+1] || gears[i+1][6] == gears[i][2]) ? 0 : -direction[i+1];
    }
    for (int i=g+1; i<4; i++) {
      direction[i] = (!direction[i-1] || gears[i][6] == gears[i-1][2]) ? 0 : -direction[i-1];
    }

    for (int i=0; i<4; i++) {
      if (direction[i] == 1) {
        gears[i].push_front(gears[i][7]);
        gears[i].pop_back();
      }
      else if (direction[i] == -1) {
        gears[i].push_back(gears[i][0]);
        gears[i].pop_front();
      }
    }
  }

  int ans = 0;
  for (int i=0; i<4; i++) {
    ans += (gears[i][0] == '1') ? (1 << i) : 0;
  }
  printf("%d\n", ans);
}
