#include<iostream>
#include<vector>

using namespace std;

int findCombination(const vector<int>& S, vector<int>& current, int min_idx, int length) {
  if (length == 6) {
    for (int i=0; i<6; i++)
      cout << current[i] << " ";
    cout << endl;
    return 0;
  }
  
  if (min_idx + (6-length) - 1 > S.size())
    return 0;
  
  for (int i=min_idx; i<S.size(); i++) {
    current.push_back(S[i]);
    findCombination(S, current, i+1, length+1);
    current.pop_back();
  }
}

int main() {
  int k;
  cin.sync_with_stdio(false);
  
  cin >> k;
  
  while (k != 0) {
    vector<int> S;
    vector<int> current;
    int temp;
    
    for (int i=0; i<k; i++) {
      cin >> temp;
      S.push_back(temp);
    }
    
    findCombination(S, current, 0, 0);
    
    cout << endl;
    cin >> k;
  }
}

/* 재귀 함수를 이용한 모든 조합 찾기 */