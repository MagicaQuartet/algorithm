#include<iostream>
#include<vector>

using namespace std;

int subsequenceSub(const vector<int>& seq, const int S, int sum, int idx) {
  if (idx > seq.size())
    return 0;
  
  int ret = 0;
  
  for (int i=idx; i<seq.size(); i++) {
    sum += seq[i];
    if (sum == S)
      ret += 1;
    ret += subsequenceSub(seq, S, sum, i+1);
    sum -= seq[i];
  }
  
  return ret;
}

int main() {
  int N, S, temp;
  vector<int> seq;
  
  cin >> N >> S;
  
  for (int i=0; i<N; i++) {
    cin >> temp;
    seq.push_back(temp);
  }
  
  cout << subsequenceSub(seq, S, 0, 0) << endl;
  return 0;
}

/* 재귀 함수를 이용하여 부분수열의 합을 찾는 문제 */