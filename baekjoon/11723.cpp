#include<iostream>
#include<string>
using namespace std;
#define EMPTY 0b00000000000000000000
#define ALL 0b11111111111111111111
int M;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> M;
  int S = EMPTY;
  while(M--) {
    string op;
    int n;
    cin >> op;
    if (op == "all") {
      S = ALL;
    }
    else if (op == "empty") {
      S = EMPTY;
    }
    else {
      cin >> n;
      if (op == "add") {
        S |= (1<<(n-1));
      }
      else if (op == "remove") {
        S &= ~(1<<(n-1));
      }
      else if (op == "check") {
        cout << !!(S&(1<<(n-1))) << "\n";
      }
      else if (op == "toggle") {
        S ^= (1<<(n-1));
      }
    }
  }
}
