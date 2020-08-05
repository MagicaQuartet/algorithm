#include<iostream>
#include<string>
using namespace std;

int N, beginIdx, endIdx;
int dq[20010];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  beginIdx = 10004;
  endIdx = 10005;

  while(N--) {
    string cmd;
    int arg;

    cin >> cmd;

    if (cmd == "push_front") {
      cin >> arg;
      dq[beginIdx--] = arg;
    }
    else if (cmd == "push_back") {
      cin >> arg;
      dq[endIdx++] = arg;
    }
    else if (cmd == "pop_front") {
      if (endIdx - beginIdx > 1) {
        cout << dq[beginIdx+1] << "\n";
        beginIdx++;
      }
      else {
        cout << -1 << "\n";
      }
    }
    else if (cmd == "pop_back") {
      if (endIdx - beginIdx > 1) {
        cout << dq[endIdx-1] << "\n";
        endIdx--;
      }
      else {
        cout << -1 << "\n";
      }
    }
    else if (cmd == "size") {
      cout << endIdx - beginIdx - 1 << "\n";
    }
    else if (cmd == "empty") {
      cout << (endIdx - beginIdx == 1 ? 1 : 0) << "\n";
    }
    else if (cmd == "front") {
      cout << (endIdx - beginIdx > 1 ? dq[beginIdx+1] : -1) << "\n";
    }
    else {
      cout << (endIdx - beginIdx > 1 ? dq[endIdx-1] : -1) << "\n";
    }
  }
}

/*
  직접 구현
*/