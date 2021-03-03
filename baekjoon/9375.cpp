#include<iostream>
#include<string>
#include<map>
#include<utility>
using namespace std;
int t, n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    map<string, int> m;
    cin >> n;
    while (n--) {
      string name, category;
      cin >> name >> category;
      if (m.find(category) == m.end()) {
        m[category] = 1;
      }
      m[category]++;
    }

    int ans = 1;
    for (auto p: m) {
      ans *= p.second;
    }
    printf("%d\n", ans-1);
  }
}