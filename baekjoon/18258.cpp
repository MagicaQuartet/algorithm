#include<iostream>
#include<string>
#include<queue>
using namespace std;
int N;
string s;
queue<int> q;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> s;
    if (s == "push") {
      int num;
      cin >> num;
      q.push(num);
    }
    else {
      if (s == "pop") {
        if (q.empty()) {
          cout << "-1\n";
        }
        else {
          cout << q.front() << "\n";
          q.pop();
        }
      }
      else if (s == "size") {
        cout << q.size() << "\n";
      }
      else if (s == "empty") {
        cout << (q.empty() ? 1 : 0) << "\n";
      }
      else if (s == "front") {
        cout << (q.empty() ? -1 : q.front()) << "\n";
      }
      else if (s == "back") {
        cout << (q.empty() ? -1 : q.back()) << "\n";
      }
    }
  }
}