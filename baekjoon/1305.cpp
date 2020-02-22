#include<iostream>
#include<string>
#include<vector>
using namespace std;
int L;
string ad;
int solve(const string& S) {
  vector<int> pi(L, 0);
  
  int matched = 0;
  for (int i=1; i<L; i++) {
    while(matched > 0 && S[i] != S[matched]) {
      matched = pi[matched-1];
    }
    
    if (S[i] == S[matched]) {
      matched++;
      pi[i] = matched;
    }
  }
  return pi[L-1];
}
int main() {
  cin.sync_with_stdio(false);
  cin >> L >> ad;
  cout << L-solve(ad);
}

/*
  주어진 문자열의 접두사이자 접미사인 부분 문자열의 길이를 찾으면 된다.
*/