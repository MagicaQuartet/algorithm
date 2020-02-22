#include<iostream>
#include<string>
#include<vector>
using namespace std;
string T, P;
vector<int> getPartialMatch(const string &P) {
  int m = P.size();
  vector<int> pi(m, 0);
  
  int matched = 0;
  
  for (int i=1; i<m; i++) {
    while(matched > 0 && P[i] != P[matched]) {
      matched = pi[matched-1];
    }
    
    if (P[i] == P[matched]) {
      matched++;
      pi[i] = matched;
    }
  }
  
  return pi;
}
vector<int> KMP(const string &T, const string &P) {
  int n = T.size(), m = P.size();
  vector<int> ret;
  vector<int> pi = getPartialMatch(P);
  
  int matched = 0;
  
  for (int i=0; i<n; i++) {
    while(matched > 0 && T[i] != P[matched]) {
      matched = pi[matched-1];
    }
    if (T[i] == P[matched]) {
      matched++;
      if (matched == m) {
        ret.push_back(i-m+1);
        matched = pi[matched-1];
      }
    }
  }
  
  return ret;
}
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  getline(cin, T);
  getline(cin, P);
  
  vector<int> ret = KMP(T, P);
  cout << ret.size() << endl;
  for (auto i : ret) {
    cout << i+1 << " ";
  }
  return 0;
}

/*
  T, P를 제외한 모든 변수를 지역변수로 선언하고 각 함수의 인자와 반환값만 다른데
  내가 구현한 코드는 틀리고 종만북 코드 형식을 따른 코드는 통과가 된다. 도대체 왜지...???
*/