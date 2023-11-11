#include<iostream>
#include<string>
using namespace std;
string S;
int N;
int main() {
  cin >> N >> S;
  char prev = ' ';
  bool ans = false;
  for (auto c: S) {
    if (c == 'a' && prev == 'b') {
      ans = true;
      break;
    }
    if (c == 'b' && prev == 'a') {
      ans = true;
      break;
    }
    prev = c;
  }
  cout << (ans ? "Yes\n" : "No\n");
}
