#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int N;

bool cmpstr (string str1, string str2) {
  if (str1.size() != str2.size()) {
    return str1.size() < str2.size();
  }
  else {
    return str1 < str2;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  vector<string> words;
  words.reserve(N);

  for (int i=0; i<N; i++) {
    string s;
    cin >> s;
    words.push_back(s);
  }

  sort(words.begin(), words.end(), cmpstr);

  for (int i=0; i<words.size(); i++) {
    if (i>0 && words[i] == words[i-1]) {
      continue;
    }
    cout << words[i] << '\n';
  }
}