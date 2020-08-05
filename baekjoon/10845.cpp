#include<iostream>
#include<string>
#include<queue>
using namespace std;

int N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  queue<int> q;
  
  while(N--) {
    string cmd;
    int arg;

    cin >> cmd;
    
    if (cmd == "push") {
      cin >> arg;
      q.push(arg);
    }
    else if (cmd == "pop") {
      if (q.empty()) {
        cout << -1 << "\n";
      }
      else {
        cout << q.front() << "\n";
        q.pop();
      }
    }
    else if (cmd == "size") {
      cout << q.size() << "\n";
    }
    else if (cmd == "empty") {
      cout << (q.empty() ? 1 : 0) << "\n";
    }
    else if (cmd == "front") {
      cout << (q.empty() ? -1 : q.front()) << "\n";
    }
    else {
      cout << (q.empty() ? -1 : q.back()) << "\n";
    }
  }
}