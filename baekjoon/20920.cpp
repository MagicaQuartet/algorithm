#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int N, M;
map<string, int> cnt;
bool cmp(string s1, string s2) {
  if (cnt[s1] != cnt[s2]) {
    return cnt[s1] > cnt[s2];
  }
  if (s1.size() != s2.size()) {
    return s1.size() > s2.size();
  }
  return s1 < s2;
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> N >> M;
  while(N--) {
    string s;
    cin >> s;
    if (s.size() < M) {
      continue;
    }
    cnt[s]++;
  }
  vector<string> words;
  for(map<string, int>::iterator it=cnt.begin(); it!=cnt.end(); ++it) {
    words.push_back(it->first);
  }
  sort(words.begin(), words.end(), cmp);
  for(auto word: words) {
    cout << word << '\n';
  }
}
