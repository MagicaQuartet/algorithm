#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define NONE 0
#define A 1
#define AB 2
string S;
vector<char> vchar;
vector<int> vstatus;
int main() {
  cin >> S;
  for (auto c: S) {
    int status = NONE;
    if (!vstatus.empty()) {
      status = vstatus.back();
    }

    if (status == NONE && c == 'A') {
      vchar.push_back(c);
      vstatus.push_back(A);
    }
    else if (status == A && c == 'B') {
      vchar.push_back(c);
      vstatus.push_back(AB);
    }
    else if (status == AB && c == 'C') {
      vchar.pop_back();
      vchar.pop_back();
      vstatus.pop_back();
      vstatus.pop_back();
    }
    else {
      vchar.push_back(c);
      if (c == 'A') {
        vstatus.push_back(A);
      }
      else {
        vstatus.push_back(NONE);
      }
    }
  }
  for (auto c: vchar) {
    cout << c;
  }
  cout << "\n";
}
