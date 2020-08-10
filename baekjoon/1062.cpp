#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, K;
string word;

int dfs(const vector<string>& words, vector<int> used, int idx, int left) {
  if (left == 0) {
    int ret = 0;

    for (int i=0; i<words.size(); i++) {
      int allUsed = 1;
      for (int j=0; j<words[i].size(); j++) {
        if (!used[words[i][j]-'a']) {
          allUsed = 0;
          break;
        }
      }

      if (allUsed) {
        ret++;
      }
    }

    return ret;
  }

  if (idx+left-1 >= 26) {
    return 0;
  }

  if (used[idx]) {
    return dfs(words, used, idx+1, left);
  }

  int ret = dfs(words, used, idx+1, left);
  used[idx] = 1;
  ret = max(ret, dfs(words, used, idx+1, left-1));
  used[idx] = 0;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> K;

  if (K < 5) {
    cout << 0 << "\n";
    return 0;
  }

  vector<string> words;
  vector<int> used(26, 0);
  used[0] = used['n'-'a'] = used['t'-'a'] = used['i'-'a'] = used[2] = 1;

  for (int i=0; i<N; i++) {
    cin >> word;
    words.push_back(word);
  }

  cout << dfs(words, used, 0, K-5) << endl;
}

/*
  의외로 brute force에 가까운 풀이가 정해였나보다
*/