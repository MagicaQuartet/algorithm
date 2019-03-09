#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
  int N, input, answer;
  cin >> N;
  
  vector<int> cost;
  
  for (int i=0; i<N; i++) {
    cin >> input;
    cost.push_back(input);
  }
  
  sort(cost.begin(), cost.end());
  
  answer = 0;
  
  for (int i=0; i<N; i++) {
    answer += cost[i]*(N-i);
  }
  
  cout << answer << endl;
  
  return 0;
}