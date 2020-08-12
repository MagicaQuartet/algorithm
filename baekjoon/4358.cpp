#include<iostream>
#include<string>
#include<map>
using namespace std;

struct cmp {
  bool operator() (const string& lhs, const string& rhs) const {
    return lhs < rhs;
  }
};

int N;
string s;
map<string, int, cmp> trees;

int main() {
  N = 0;
  while (getline(cin, s, '\n')) {

    if (trees.find(s) == trees.end()) {
      trees[s] = 0;
    }
    trees[s]++;
    N++;
  }

  cout << fixed;
  cout.precision(4);
  for (auto tree: trees) {
    cout << tree.first << " " << tree.second*100.0/N << "\n";
  }
}