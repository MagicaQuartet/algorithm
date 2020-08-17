#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int w, b;
int maxScore, maxLen, wordCount;
string longWord;
vector<string> words(300010, "");
char board[4][4];
int visited[4][4];
int found[300010];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct TrieNode {
  TrieNode* children[26];
  bool terminal;
  int wordIdx;

  TrieNode(): terminal(false) {
    memset(children, 0, sizeof(children));
  }

  TrieNode* getChild(char c) {
    return children[c-'A'];
  }

  bool hasChild(char c) {
    return children[c-'A'] != NULL;
  }
};

struct Trie {
  TrieNode* root = new TrieNode();

  void insert(const string& word, int idx) {
    TrieNode* current = root;
    for (int i=0; i<word.size(); i++) {
      char c = word[i];
      if (!(current->hasChild(c))) {
        current->children[c-'A'] = new TrieNode();
      }
      current = current->getChild(c);
    }
    current->wordIdx = idx;
    current->terminal = true;
  }

  int find(const string& word) {
    TrieNode* current = root;
    for (int i=0; i<word.size(); i++) {
      char c = word[i];
      if (current->hasChild(c)) {
        current = current->getChild(c);
      }
      else {
        return -1;
      }
    }
    return current->terminal ? current->wordIdx : -1;
  }
};

Trie* trie = new Trie();

int getScore(int len) {
  if (len <= 2) {
    return 0;
  }
  else if (len <= 4) {
    return 1;
  }
  else if (len == 5) {
    return 2;
  }
  else if (len == 6) {
    return 3;
  }
  else if (len == 7) {
    return 5;
  }
  else {
    return 11;
  }
}

void dfs(int x, int y, string& s) {
  visited[x][y] = 1;
  s.push_back(board[x][y]);

  int idx = trie->find(s);
  if (idx > -1 && !found[idx]) {
    string picked = words[idx];
    found[idx] = 1;
    maxScore += getScore(picked.size());
    if (maxLen < picked.size() || (maxLen == picked.size() && picked < longWord)) {
      maxLen = picked.size();
      longWord = picked;
    }
    wordCount++;
  }

  if (s.size() < 8) {
    for (int i=0; i<8; i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];

      if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {
        continue;
      }

      if (visited[nx][ny]) {
        continue;
      }

      dfs(nx, ny, s);
    }
  }

  s.pop_back();
  visited[x][y] = 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> w;
  for (int i=0; i<w; i++) {
    string word;
    cin >> word;
    words[i] = word;
    trie->insert(word, i);
  }

  cin >> b;
  while(b--) {
    for (int i=0; i<4; i++) {
      string row;
      cin >> row;
      for (int j=0; j<4; j++) {
        board[i][j] = row[j];
      }
    }
    memset(found, 0, sizeof(found));

    maxScore = maxLen = wordCount = 0;
    longWord = "";
    for (int i=0; i<4; i++) {
      for (int j=0; j<4; j++) {
        string initStr = "";
        dfs(i, j, initStr);
      }
    }
    cout << maxScore << " " << longWord << " " << wordCount << "\n";
  }
}

/*
  트라이 구현이 너무 익숙하지 않다... 연습할 필요 있을 듯
*/