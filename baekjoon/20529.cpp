#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string s;
int t, n, ans;
int bitcnt(int b) {
  int cnt = 0;
  while(b>0) {
    cnt += b & 1;
    b >>= 1;
  }
  return cnt;
}
void solve(const vector<int>& arr, int idx, vector<int>& selected) {
  if (idx == n) {
    if (selected.size() != 3) return;
    int res0 = arr[selected[0]]^arr[selected[1]];
    int res1 = arr[selected[2]]^arr[selected[1]];
    int res2 = arr[selected[0]]^arr[selected[2]];
    ans = min(ans, bitcnt(res0)+bitcnt(res1)+bitcnt(res2));
    return;
  }
  if (selected.size() == 3) {
    solve(arr, n, selected);
    return;
  }

  solve(arr, idx+1, selected);
  selected.push_back(idx);
  solve(arr, idx+1, selected);
  selected.pop_back();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n;
    vector<int> selected;
    vector<int> arr;
    ans = 987654321;
    selected.reserve(n);
    arr.reserve(n);
    for (int i=0; i<n; i++) {
      cin >> s;
      int b = 8*(s[0]=='E')+4*(s[1]=='S')+2*(s[2]=='T')+(s[3]=='J');
      arr.push_back(b);
    }
    if (n > 32) {
      cout << 0 << "\n";
      continue;
    }
    solve(arr, 0, selected);
    cout << ans << "\n";
  }
}
