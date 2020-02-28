#include<iostream>
#include<string>
using namespace std;
string A, B;
int n, m, cnt;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  getline(cin, A);
  getline(cin, B);
  n = A.size();
  m = B.size();
  cnt = 0;
  for (int i=0; i+m <= n;) {
    bool match = true;
    for (int j=0; j<m; j++) {
      if (A[i+j] != B[j]) {
        match = false;
        break;
      }
    }
    
    if (match) {
      cnt++;
      i += m;
    }
    else {
      i++;
    }
  }
  cout << cnt;
}

/*
  문자열에 공백이 있는 줄은 몰랐네~
*/